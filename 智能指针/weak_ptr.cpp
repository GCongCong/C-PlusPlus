# include<iostream>
//5.解决强指针互相引用问题，用弱指针，在指针指向时，计数不变化，只将指针指向改变即可
//不能单独使用，和强指针配合使用
//4.shared_ptr，不通过权限转移的方式，允许多个指针指向同一块内存
//用一个结构体来保存内存块地址和指向这个内存块地址的指针个数，引用计数法。对其进行增加，删除，查找，获得操作
//shared_ptr每指向一块内存，往这里增加一条记录，释放一个删除一个。
//4-1用数据结构管理shared_ptr指向的内存块,采用结点保存一条内存块记录，一条记录包含地址，计数;因为地址，数字都是已知类型，所以不需要使用模板
class Manage
{
public:
	Manage()
	{
		std::cout<<"total[10]创建完成"<<std::endl;
		current = 0;
	}
	//1.添加一个内存块信息或计数
	void add(void* ptr)
	{
		int i = find(ptr);//查找该内存块是否存在
		if(i != -1)//表示存在
		{
			total[i].count++;//对应内存块计数++即可
		}
		else//不存在
		{
			total[current].addr = ptr;//将地址放入结构体
			total[current].count = 1;//计数为1
			current++;
		}
	}
	//2. 减少计数,当计数变为0，表示最后一个指针对此内存块指向结束，我们并不清空地址记录，只是不允许减了
	//所以结构体只能保存10块内存地址信息
	void del(void* ptr)
	{
		int i = find(ptr);
		if(i < 0)//表示没找到，抛出异常
		{
			throw std::exception("ptr error");
		}
		else
		{
			if(total[i].count>0)
			{
				total[i].count--;
			}
		}
	}
	//3.获得内存块的引用计数
	int getc(void* ptr)
	{
		int i = find(ptr);
		if(i < 0)
		{
			return -1;
		}
		else
		{
			return total[i].count;
		}
	}
	//4.打印管理内存块的信息
	void show()
	{
		std::cout<<"-------可以管理10块内存地址-------"<<std::endl;
		for(int i = 0;i < 10;i++)
		{
			std::cout<<"第"<<i<<"个结点保存的内存块地址："<<total[i].addr<<"指向内存块的指针个数："<<total[i].count<<std::endl;
		}
		std::cout<<"----------------------------------"<<std::endl;
	}
private:
	//查找当前数据结构中是否存在该地址
	int find(void* ptr)
	{
		for(int i = 0;i<10;i++)
		{
			if(ptr == total[i].addr)
				return i;
		}
		return -1;
	}
	class Node//一条记录
	{
	public:
		Node(void* a = NULL,int c = 0)
			:addr(a),count(c)
		{}
		void* addr;
		int count;
	};
	Node total[10];//表示可以记录10个内存块的信息
	int current;//current之前是已经记录了内存地址信息，代表现在里面的有效元素个数
};
//4-2shared_ptr指针指向的内存通过管理类来管理，所以定义一个全局静态管理类对象
template<typename T>
class Shared_ptr
{
public:
	Shared_ptr(T* ptr = NULL)
		:mptr(ptr)
	{
		manage.add(mptr);//智能指针指向内存，将内存地址添加到管理结构体中
	}
	Shared_ptr(Shared_ptr<T>& rhs)
	{
		mptr = rhs.mptr;
		manage.add(mptr);
	}
	Shared_ptr<T> operator=(Shared_ptr<T>& rhs)//赋值，先析构旧内存块，再指向新的
	{
		if(this != &rhs)
		{
			this->~Shared_ptr();//处理旧指针
			mptr=rhs.mptr;
			manage.add(mptr);
		}
		return *this;
	}
	T* operator->()
	{
		return mptr;
	}
	T& operator*()
	{
		return *mptr;
	}
	void showma()
	{
		manage.show();
	}
	 T* getptr()const//给弱指针用
	{
		return mptr;
	}
	~Shared_ptr()
	{
		manage.del(mptr);//减少内存地址计数
		if(manage.getc(mptr) == 0)//如果此时内存计数为0，表示当前指针为最后一个指针，释放内存块
		{
			delete mptr;
		}
		else//否则，置为NULL即可。
		{
			mptr=NULL;
		}
	}
private:
	T* mptr;
	static Manage manage;
};
template<typename T>
Manage Shared_ptr<T>::manage;

//5.解决强指针互相引用问题，用弱指针，在指针指向时，计数不变化，只将指针指向改变即可
//不能单独使用，和强指针配合使用
template<typename T>
class Weak_ptr
{
public:
	Weak_ptr(T* ptr=NULL)
		:mptr(ptr)
	{}
	Weak_ptr(Weak_ptr<T>& rhs)
	{
		mptr=rhs.mptr;
	}
	Weak_ptr<T> operator= (Weak_ptr<T>& rhs)//弱指针=弱指针赋值
	{
		if(this != &rhs)
		{
			mptr=rhs.mptr;
		}
		return *this;
	}
	Weak_ptr<T> operator= (const Shared_ptr<T>& rhs)//弱指针=强指针赋值，不能直接访问Shared_ptr的私有成员，所以从公有接口获取
	{
		mptr=rhs.getptr();//常对象只能调用常方法，所以getptr需要用const修饰
		return *this;
	}
	~Weak_ptr()
	{}
private:
	T* mptr;
};
class B;
class A
{
public:
	A()
	{
		std::cout<<"A()"<<std::endl;
	};
	~A()
	{
		std::cout<<"~A()"<<std::endl;
	}
	//Shared_ptr<B> spa;出现强指针互相引用问题 
	Weak_ptr<B> spa;
};
class B
{
public:
	B()
	{
		std::cout<<"B()"<<std::endl;
	};
	~B()
	{
		std::cout<<"~B()"<<std::endl;
	}
	Weak_ptr<A> spb;
};
int main()
{
	/*int* a = new int(10);
	Shared_ptr<int> s1(a);
	Shared_ptr<int> s2(a);
	Shared_ptr<int> s3(a);
	Shared_ptr<int> s4 = new int(20);
	Shared_ptr<int> s5=s4;
	s1=s5;
	s5.showma();
	*/
	//缺陷，强指针内部的互相引用，使用弱指针解决 
	Shared_ptr<A> pa = new A();//A内部存在强指针
	Shared_ptr<B> pb = new B();//B也存在
	pa->spa=pb;//互相指向
	pb->spb=pa;//析构只会析构pa，此时A生成的堆内存有2个指针指向，但是只会析构pa,内存块不能被释放，因为计数为1
}

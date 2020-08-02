# include<iostream>
//1.auto_ptr,所有权唯一，当前内存块只能有一个指针指向，这样不会出现一个内存块被释放多次的问题
template<typename T>
class Auto_ptr
{
public:
	Auto_ptr(T* ptr)
		:mptr(ptr)
	{
		std::cout<<"Auto_ptr()"<<std::endl;
	}
	Auto_ptr(Auto_ptr<T>& rhs)//rhs为已经存在的对象，让新对象指针指向它指向的的内存，它断开指向，保证所有权唯一
	{
		std::cout<<"Auto_ptr(&rhs)"<<std::endl;
		mptr = rhs.Release();
	}
	Auto_ptr<T> operator=(Auto_ptr<T>& rhs)//赋值运算符重载
	{
		if(this != &rhs)
		{
			std::cout<<"Auto_ptr(operator=)"<<std::endl;
			delete mptr;//释放原来指向的内存，原来指针指向的内存有多个指针指向，那么此时mptr=NULL,delete NULL是正确的
			mptr=rhs.Release();
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
	~Auto_ptr()
	{
		delete mptr;
		std::cout<<"~Auto_ptr()"<<std::endl;
	}
private:
	T* Release()//新指针获得所有权函数
	{
		T* temp = mptr;//保存旧指针的指向
		mptr = NULL;//断开旧指针指向内存的连接
		return temp;//将旧指针原来指向的内存地址返回，让新指针指向
	}
	T* mptr;
};
class Test
{
public:
	void show()
	{
		std::cout<<"Hello"<<std::endl;
	}
};
int main()
{
	//智能指针应该可以和普通指针的使用一样
	//1. 开辟内存int *p = new int(10);
	Auto_ptr<int> pa1 = new int(10);
	//2. 解引用赋值*p=20
	*pa1=20;
	std::cout<<"*pa1="<<*pa1<<std::endl;
	//3. 指向对象，调用函数如：Test* ptest = new Test();ptest->show();
	Auto_ptr<Test>pa2=new Test();
	pa2->show();
	//4.缺陷，智能指针提前失效问题
	/*Auto_ptr<int> pa3 = new int(10);
	Auto_ptr<int> pa4 = pa3;//此时pa3指针已经失效为NULL
	*pa4=30;//成功，因为此时它已经获得了内存的所有权
	*pa3=40;//失败，此时pa3为NULL，对保留区操作，崩溃
	return 0;*/
}

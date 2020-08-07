# include<iostream>
# include<deque>
# include<vector>
# include<list>
# include<algorithm>
# include<iterator>
# include<set>
# include<map>
# include<string>
//观察者模式

class Listen//监听者抽象类
{
public:
	Listen( std::string n)
		:name(n)
	{}
	virtual void Deal(int message)=0;
protected:
	 std:: string name;
};
class Listen1:public Listen//监听者1,对1，2事件感兴趣
{
public:
	Listen1( std::string n)
		:Listen(n)
	{}
	void Deal(int message)//对自己感兴趣的事件进行处理
	{
		switch(message)
		{
		case 1:
			std::cout<<"Listen1 Deal message 1 !"<<std::endl;
			break;
		case 2:
			std::cout<<"Listen1 Deal message 1 !"<<std::endl;
			break;
		default:
			std::cout<<"Listen1 not intersting this message!"<<std::endl;
			break;
		}
	}
};
class Listen2:public Listen//监听者2,对2，3事件感兴趣
{
public:
	Listen2( std::string n)
		:Listen(n)
	{}
	void Deal(int message)//对自己感兴趣的事件进行处理
	{
		switch(message)
		{
		case 2:
			std::cout<<"Listen2 Deal message 2 !"<<std::endl;
			break;
		case 3:
			std::cout<<"Listen2 Deal message 3 !"<<std::endl;
			break;
		default:
			std::cout<<"Listen2 not intersting this message!"<<std::endl;
			break;
		}
	}
};
class Listen3:public Listen//监听者3,对1，3事件感兴趣
{
public:
	Listen3( std::string n)
		:Listen(n)
	{}
	void Deal(int message)//对自己感兴趣的事件进行处理
	{
		switch(message)
		{
		case 1:
			std::cout<<"Listen3 Deal message 1 !"<<std::endl;
			break;
		case 3:
			std::cout<<"Listen3 Deal message 3 !"<<std::endl;
			break;
		default:
			std::cout<<"Listen3 not intersting this message!"<<std::endl;
			break;
		}
	}
};

class Observe
{
public:
	typedef std::map<int,std::vector< Listen*>> mmap;//类型重定义
	typedef std::vector< Listen*> myvec;
	void registerM(int message, Listen* listen)//将监听者感兴趣的事件注册
	{
		//1.先看事件是否存在,使用查找函数
		mmap::iterator it=mymap.find(message);
		if(it!=mymap.end())
		{
			it->second.push_back(listen);//存在，将将监听者放入集合，second是vector
		}
		else//不存在，将集合放入map中，使用map[键值]=集合插入即可
		{
			myvec vec;
			vec.push_back(listen);
			mymap[message]=vec;
		}
	}
	void notify(int message)//事件发生，通知监听者
	{
		//1.遍历集合，查找是否有对此事件感兴趣的监听者
		mmap::iterator it=mymap.find(message);//查找
		if(it!=mymap.end())//有对此事件感兴趣的监听者，循环集合通知，让其处理
		{
			myvec::iterator vit=it->second.begin();//从数组起始点开始
			while(vit!=it->second.end())
			{
				(*vit)->Deal(message);//数组中保存监听者指针，解引用得到监听者指针，调用处理函数，进行处理
				vit++;
			}
		}
		else//没有监听者对此事件感兴趣
		{
			std::cout<<"no listen intersting "<<message<<"message"<<std::endl;
		}
	}
private:
	//将事件-监听者集合放入map中,集合用vector存储，存储监听者抽象类指针，可以访问任意监听者，基类指针指向派生类对象
	std::map<int,std::vector< Listen*>> mymap;
};
int main()
{
	Listen1 L1("listen1");//const char[8]
	Listen2 L2("listen2");
	Listen3 L3("listen3");
	Observe ob;//定义观察者
	//注册监听者感兴趣的事件
	ob.registerM(1,&L1);
	ob.registerM(2,&L1);
	ob.registerM(2,&L2);
	ob.registerM(3,&L2);
	ob.registerM(1,&L3);
	ob.registerM(3,&L3);
	std::cout<<"--------1号事件触发-----------"<<std::endl;
	ob.notify(1);//1号事件被触发
	std::cout<<"--------3号事件触发-----------"<<std::endl;
	ob.notify(3);//3号事件被触发
	std::cout<<"--------4号事件触发-----------"<<std::endl;
	ob.notify(4);

}


//2.多线程下的双重锁机制的单例模式，加一层判断，并引入互斥锁
class LazySingleTon
{
public:
	static LazySingleTon* getIntance()//唯一的公有接口，生成唯一的对象
	{
		if(lazy==NULL)//避免生成唯一的对象后，对临界资源加锁，浪费系统资源
		{
			lock();//加锁
			if(lazy==NULL)//表示现在指针还没有指向唯一的对象
			{
				lazy=new LazySingleTon();//在堆上生成对象
			}
			unlock();//解锁
		}
		return lazy;//返回唯一的对象
	}

private:
	LazySingleTon()//私有构造
	{
		std::cout<<"create object"<<std::endl;
	}
	LazySingleTon(const LazySingleTon&);//私有拷贝构造
	static LazySingleTon* lazy;//静态成员变量
};
LazySingleTon* LazySingleTon::lazy=NULL;//初始化

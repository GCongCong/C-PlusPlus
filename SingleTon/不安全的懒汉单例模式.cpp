//1.懒汉模式
class LazySingleTon
{
public:
	static LazySingleTon* getIntance()//唯一的公有接口，生成唯一的对象
	{
		if(lazy==NULL)//表示现在指针还没有指向唯一的对象
		{
			lazy=new LazySingleTon();//在堆上生成对象
		}
		return lazy;//返回唯一的对象
	}

private:
	LazySingleTon()//私有构造
	{
		std::cout<<"create  lazy object"<<std::endl;
	}
	LazySingleTon(const LazySingleTon&);//私有拷贝构造
	static LazySingleTon* lazy;//静态成员变量
};
LazySingleTon* LazySingleTon::lazy=NULL;//初始化
int main()
{
	LazySingleTon* lazy1=LazySingleTon ::getIntance();
	LazySingleTon* lazy2=LazySingleTon ::getIntance();
	LazySingleTon* lazy3=LazySingleTon ::getIntance();
	
}

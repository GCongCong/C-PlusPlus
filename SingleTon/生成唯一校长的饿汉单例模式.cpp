//生成唯一校长的单例模式
class Reactor
{
public:
	static Reactor* getReactor()//返回唯一的对象
	{
		return reactor;
	}
	static void show()//打印对象信息
	{
		std::cout<<"-----唯一校长信息--"<<std::endl;
		std::cout<<"name ： "<<reactor->name<<std::endl;
		std::cout<<"age  ："<<reactor->age<<std::endl;
		std::cout<<"sex  ："<<reactor->sex<<std::endl;
		std::cout<<"-------------------"<<std::endl;
	}
private:
	Reactor(char* n,int a,bool s)//构造函数
	{
		name=new char[strlen(n)+1]();
		strcpy_s(name,strlen(n)+1,n);
		age=a;
		sex=s;
		std::cout<<"Reactor finish"<<std::endl;
	}
	Reactor(const Reactor&);//拷贝构造函数
	char* name;
	int age;
	bool sex;
	static Reactor* reactor;//指向唯一的对象
};
Reactor* Reactor::reactor=new Reactor("cc",21,false);//饿汉模式，提前生成唯一的对象

int main()
{
	Reactor* r1=Reactor::getReactor();
	Reactor* r2=Reactor::getReactor();
	Reactor::show();//打印唯一对象的信息
	std::cout<<"r1"<<r1<<std::endl;
	std::cout<<"r2"<<r2<<std::endl;
}

//2.工厂方法模式，一个工厂生产一种产品，多个工厂
//两个工厂，一个生产苹果，一个生产香蕉
class Fruit//抽象水果类
{
public:
	Fruit(std::string m)
		:name(m)
	{}
	virtual void oparator()=0;
protected:
	std::string name;
};
class Apple:public Fruit
{
public:
	Apple(std::string m)
		:Fruit(m)
	{};
	void oparator()
	{
		std::cout<<"apple"<<std::endl;
	}
};
class Banana:public Fruit
{
public:
	 Banana(std::string m)
		:Fruit(m)
	{};
	void oparator()
	{
		std::cout<<"banana"<<std::endl;
	}
};
class Factory//工厂抽象类
{
public:
	Factory(std::string name)
		:fname(name)
	{}
	virtual Fruit* create()=0;//纯虚函数
protected:
	std::string fname;
};
class Fa:public Factory//苹果工厂
{
public:
	Fa(std::string name)
		:Factory(name)
	{
		std::cout<<"苹果工厂建立完成"<<std::endl;
	}
	Fruit* create()//生产苹果
	{
		std::cout<<"苹果生产完成"<<std::endl;
		return new Apple("apple");//生产苹果
	}
};
class Fb:public Factory//香蕉工厂
{
public:
	Fb(std::string name)
		:Factory(name)
	{
		std::cout<<"香蕉工厂建立完成"<<std::endl;
	}
	Fruit* create()//生产香蕉
	{
		std::cout<<"香蕉生产完成"<<std::endl;
		return new Banana("banana");//生产香蕉
	}
};
int main()
{
	Fb fb("1");//建立香蕉工厂
	Fruit* f=fb.create();//生产香蕉
	Fa fa("2");//建立苹果工厂
	Fruit* f1=fa.create();//生产苹果
}

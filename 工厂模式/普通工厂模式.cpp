//1. 普通工厂模式，一个工厂，多条生产线

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
		std::cout<<"eat apple"<<std::endl;
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
		std::cout<<" eat banana"<<std::endl;
	}
};
class Factory//建立水果工厂
{
public:
	Factory()
	{
		std::cout<<"水果工厂建立完成"<<std::endl;
	}
	Fruit* create(int flag)
	{
		switch(flag)
		{
			case 1:
				std::cout<<"苹果生产完成"<<std::endl;
				return new Apple("apple");//生产苹果
				break;
			case 2:
				std::cout<<"香蕉生产完成"<<std::endl;
				return new Banana("banana");//生产香蕉
				break;
			default:
				return NULL;
				break;
		}
	}
};
int main()
{
	Factory F;//建立工厂
	Fruit* pf=F.create(1);//生产苹果
	Fruit* pf1=F.create(2);//生产香蕉
}

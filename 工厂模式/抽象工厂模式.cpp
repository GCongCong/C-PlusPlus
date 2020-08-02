//3.抽象工厂模式，一个工厂生产配套的产品如A1+B1，假如现在需要生产A1+B1,A2+B2产品，那么需要两个工厂,
# include<iostream>
# include<string>
class A//生产A类产品
{
public:
	A(std::string n)
		:name(n)
	{}
protected:
	std::string name;
};
class A1 :public A//生产A1产品
{
public:
	A1(std::string n)
		:A(n)
	{
	}
};
class A2 :public A//生产A2产品
{
public:
	A2(std::string n)
		:A(n)
	{
	}
};
class B//生产B类产品
{
public:
	B(std::string n)
		:name(n)
	{}
protected:
	std::string name;
};
class B1 :public B//生产B2产品
{
public:
	B1(std::string n)
		:B(n)
	{
	}
};
class B2:public B//生产A2产品
{
public:
	B2(std::string n)
		:B(n)
	{
	}
};
class Factory//建立工厂抽象类
{
public:
	Factory(std::string n)
		:name(n)
	{}
	virtual A* createA()=0;//生产A类产品
	virtual B* createB()=0;//生产B类产品
protected:
	std::string name;
};
class F1 :public Factory//生产A1+B1产品
{
public:
	F1(std::string n)
		:Factory(n)
	{
		std::cout<<"生产A1+B1产品工厂建立完成"<<std::endl;
	}
	 A* createA()//生产A1产品
	{
		std::cout<<"A1生产完成"<<std::endl;
		return new A1("A1");
	}
	B* createB()//生产B1产品
	{
		std::cout<<"B1生产完成"<<std::endl;
		return new B1("B1");
	}
};
class F2 :public Factory//生产A2+B2产品
{
public:
	F2(std::string n)
		:Factory(n)
	{
		std::cout<<"生产A2+B2产品工厂建立完成"<<std::endl;
	}
	 A* createA()//生产A1产品
	{
		std::cout<<"A1生产完成"<<std::endl;
		return new A2("A2");
	}
	B* createB()//生产B1产品
	{
		std::cout<<"B2生产完成"<<std::endl;
		return new B2("B2");
	}
};
int main()
{
	Factory* f=new F1("A1+B1");
	A* pa1=f->createA();
	B* pb1=f->createB();
	Factory* f2=new F2("A2+B2");
	A* pa2=f2->createA();
	B* pb2=f2->createB();
}

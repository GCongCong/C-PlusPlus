# include<iostream>

//4.不能被继承的类
//4-2使用虚继承和友元
class Derive;
class Base
{
private:
	Base(int data)
		:ma(data)
	{
		std::cout<<"Base"<<std::endl;
	}
	int ma;
	friend class Derive;
};
class Derive: virtual public Base//不能被继承,必须使用虚继承
{
public:
	Derive(int data)
		:mb(data),Base(data)
	{
		std::cout<<"Derive"<<std::endl;
	}
private:
	int mb;
};
class Test:public Derive
{
public:
	Test(int data)
		:mc(data),Derive(data),Base(data)
	{
		std::cout<<"Test"<<std::endl;
	}
private:
	int mc;
};
int main()
{
	//Derive a(10);
	Test a(1);
}





# include<iostream>

//4.���ܱ��̳е���
//4-2ʹ����̳к���Ԫ
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
class Derive: virtual public Base//���ܱ��̳�,����ʹ����̳�
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





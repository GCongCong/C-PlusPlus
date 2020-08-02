//3.���󹤳�ģʽ��һ�������������׵Ĳ�Ʒ��A1+B1������������Ҫ����A1+B1,A2+B2��Ʒ����ô��Ҫ��������,
# include<iostream>
# include<string>
class A//����A���Ʒ
{
public:
	A(std::string n)
		:name(n)
	{}
protected:
	std::string name;
};
class A1 :public A//����A1��Ʒ
{
public:
	A1(std::string n)
		:A(n)
	{
	}
};
class A2 :public A//����A2��Ʒ
{
public:
	A2(std::string n)
		:A(n)
	{
	}
};
class B//����B���Ʒ
{
public:
	B(std::string n)
		:name(n)
	{}
protected:
	std::string name;
};
class B1 :public B//����B2��Ʒ
{
public:
	B1(std::string n)
		:B(n)
	{
	}
};
class B2:public B//����A2��Ʒ
{
public:
	B2(std::string n)
		:B(n)
	{
	}
};
class Factory//��������������
{
public:
	Factory(std::string n)
		:name(n)
	{}
	virtual A* createA()=0;//����A���Ʒ
	virtual B* createB()=0;//����B���Ʒ
protected:
	std::string name;
};
class F1 :public Factory//����A1+B1��Ʒ
{
public:
	F1(std::string n)
		:Factory(n)
	{
		std::cout<<"����A1+B1��Ʒ�����������"<<std::endl;
	}
	 A* createA()//����A1��Ʒ
	{
		std::cout<<"A1�������"<<std::endl;
		return new A1("A1");
	}
	B* createB()//����B1��Ʒ
	{
		std::cout<<"B1�������"<<std::endl;
		return new B1("B1");
	}
};
class F2 :public Factory//����A2+B2��Ʒ
{
public:
	F2(std::string n)
		:Factory(n)
	{
		std::cout<<"����A2+B2��Ʒ�����������"<<std::endl;
	}
	 A* createA()//����A1��Ʒ
	{
		std::cout<<"A1�������"<<std::endl;
		return new A2("A2");
	}
	B* createB()//����B1��Ʒ
	{
		std::cout<<"B2�������"<<std::endl;
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

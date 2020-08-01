//3. Ðé¼Ì³Ð
class A
{
public:
	A(int data)
		:ma(data)
	{
		std::cout<<"A()"<<std::endl;
	}
	~A()
	{
		std::cout<<"~A()"<<std::endl;
	}
protected:
	int ma;
};
class B :virtual public A
{
public:
	B(int data)
		:mb(data),A(data)
	{
		std::cout<<"B()"<<std::endl;
	}
	~B()
	{
		std::cout<<"~B()"<<std::endl;
	}
protected:
	int mb;
};
class C :virtual public A
{
public:
	C(int data)
		:mc(data),A(data)
	{
		std::cout<<"C()"<<std::endl;
	}
	~C()
	{
		std::cout<<"~C()"<<std::endl;
	}
protected:
	int mc;
};
class D :public B,public C
{
public:
	D(int data)
		:md(data),A(data),B(data),C(data)
	{
		std::cout<<"D()"<<std::endl;
	}
	~D()
	{
		std::cout<<"~D()"<<std::endl;
	}
protected:
	int md;
};
int main()
{
	D d(10);
	return 0;
}

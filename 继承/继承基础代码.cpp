//1. ผฬณะ
class Base
{
public:
	Base(int data)
		:ma(data)
	{}
	virtual void show()
	{
		std::cout<<"Base::Show()"<<std::endl;
	}
	/*virtual void show(int)
	{
		std::cout<<"Base::Show(int)"<<std::endl;
	}*/
protected:
	int ma;
};
class Derive:public Base
{
public:
	Derive(int data)
		:Base(data),mb(data)
	{}
	void show()
	{
		std::cout<<"Derive::show()"<<std::endl;
	}
private:
	int mb;
};
int main()
{
	Base* pb = new Derive(10);
	std::cout<<typeid(pb).name()<<std::endl;
	std::cout<<typeid(*pb).name()<<std::endl;
	pb->show();
	delete pb;
}

class Base
{
public:
	Base(int data)
		:ma(data)
	{
		memset(this,0,sizeof(*this));
	}
	virtual void show()
	{
		std::cout<<"Base::Show()"<<std::endl;
	}
protected:
	int ma;
};
class Derive:public Base
{
public:
	Derive(int data)
		:Base(data),mb(data)
	{}
	void show()
	{
		std::cout<<"Derive::show()"<<std::endl;
	}
private:
	int mb;
};
int main()
{
	Base* pb=new Derive(10);
	pb->show();
	delete pb;
}

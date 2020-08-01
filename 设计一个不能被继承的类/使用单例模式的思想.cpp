//4-1使用单例模式的思想
class Base
{
public:
	static Base* getInstance(int data)
	{
		return new Base(data);
	}
private:
	Base(int data)
		:ma(data)
	{
		std::cout<<"Base"<<std::endl;
	}
	int ma;
};
class Derive:public Base//无法继承，因为无法访问Base的私有构造
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
int main()
{
	//Derive d(10);//不能继承
	Base* p=Base::getInstance(10);//缺陷
}

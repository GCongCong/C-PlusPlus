//2.纯虚函数
class Animal
{
public:
	Animal(std::string nm)
		:mname(nm)
	{}
	virtual void Bark()=0;//纯虚函数
protected:
	std::string mname;
};
class Dog:public Animal
{
public:
	Dog(std::string name)
		:Animal(name)
	{}
	void Bark()//重写纯虚函数，Bark函数变为虚函数
	{
		std::cout<<"wang wang wang!"<<std::endl;
	}
};
int main()
{
	Animal* pa=new Dog("Dog");//基类指针指向派生类对象，即抽象类指针指向具体实体
	pa->Bark();//调用派生类的虚函数
}

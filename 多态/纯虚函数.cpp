//2.���麯��
class Animal
{
public:
	Animal(std::string nm)
		:mname(nm)
	{}
	virtual void Bark()=0;//���麯��
protected:
	std::string mname;
};
class Dog:public Animal
{
public:
	Dog(std::string name)
		:Animal(name)
	{}
	void Bark()//��д���麯����Bark������Ϊ�麯��
	{
		std::cout<<"wang wang wang!"<<std::endl;
	}
};
int main()
{
	Animal* pa=new Dog("Dog");//����ָ��ָ����������󣬼�������ָ��ָ�����ʵ��
	pa->Bark();//������������麯��
}

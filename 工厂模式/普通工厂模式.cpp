//1. ��ͨ����ģʽ��һ������������������

class Fruit//����ˮ����
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
class Factory//����ˮ������
{
public:
	Factory()
	{
		std::cout<<"ˮ�������������"<<std::endl;
	}
	Fruit* create(int flag)
	{
		switch(flag)
		{
			case 1:
				std::cout<<"ƻ���������"<<std::endl;
				return new Apple("apple");//����ƻ��
				break;
			case 2:
				std::cout<<"�㽶�������"<<std::endl;
				return new Banana("banana");//�����㽶
				break;
			default:
				return NULL;
				break;
		}
	}
};
int main()
{
	Factory F;//��������
	Fruit* pf=F.create(1);//����ƻ��
	Fruit* pf1=F.create(2);//�����㽶
}

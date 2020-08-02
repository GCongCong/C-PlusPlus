//2.��������ģʽ��һ����������һ�ֲ�Ʒ���������
//����������һ������ƻ����һ�������㽶
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
		std::cout<<"apple"<<std::endl;
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
		std::cout<<"banana"<<std::endl;
	}
};
class Factory//����������
{
public:
	Factory(std::string name)
		:fname(name)
	{}
	virtual Fruit* create()=0;//���麯��
protected:
	std::string fname;
};
class Fa:public Factory//ƻ������
{
public:
	Fa(std::string name)
		:Factory(name)
	{
		std::cout<<"ƻ�������������"<<std::endl;
	}
	Fruit* create()//����ƻ��
	{
		std::cout<<"ƻ���������"<<std::endl;
		return new Apple("apple");//����ƻ��
	}
};
class Fb:public Factory//�㽶����
{
public:
	Fb(std::string name)
		:Factory(name)
	{
		std::cout<<"�㽶�����������"<<std::endl;
	}
	Fruit* create()//�����㽶
	{
		std::cout<<"�㽶�������"<<std::endl;
		return new Banana("banana");//�����㽶
	}
};
int main()
{
	Fb fb("1");//�����㽶����
	Fruit* f=fb.create();//�����㽶
	Fa fa("2");//����ƻ������
	Fruit* f1=fa.create();//����ƻ��
}

//4-1ʹ�õ���ģʽ��˼��
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
class Derive:public Base//�޷��̳У���Ϊ�޷�����Base��˽�й���
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
	//Derive d(10);//���ܼ̳�
	Base* p=Base::getInstance(10);//ȱ��
}

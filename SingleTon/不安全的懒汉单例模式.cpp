//1.����ģʽ
class LazySingleTon
{
public:
	static LazySingleTon* getIntance()//Ψһ�Ĺ��нӿڣ�����Ψһ�Ķ���
	{
		if(lazy==NULL)//��ʾ����ָ�뻹û��ָ��Ψһ�Ķ���
		{
			lazy=new LazySingleTon();//�ڶ������ɶ���
		}
		return lazy;//����Ψһ�Ķ���
	}

private:
	LazySingleTon()//˽�й���
	{
		std::cout<<"create  lazy object"<<std::endl;
	}
	LazySingleTon(const LazySingleTon&);//˽�п�������
	static LazySingleTon* lazy;//��̬��Ա����
};
LazySingleTon* LazySingleTon::lazy=NULL;//��ʼ��
int main()
{
	LazySingleTon* lazy1=LazySingleTon ::getIntance();
	LazySingleTon* lazy2=LazySingleTon ::getIntance();
	LazySingleTon* lazy3=LazySingleTon ::getIntance();
	
}

//2.���߳��µ�˫�������Ƶĵ���ģʽ����һ���жϣ������뻥����
class LazySingleTon
{
public:
	static LazySingleTon* getIntance()//Ψһ�Ĺ��нӿڣ�����Ψһ�Ķ���
	{
		if(lazy==NULL)//��������Ψһ�Ķ���󣬶��ٽ���Դ�������˷�ϵͳ��Դ
		{
			lock();//����
			if(lazy==NULL)//��ʾ����ָ�뻹û��ָ��Ψһ�Ķ���
			{
				lazy=new LazySingleTon();//�ڶ������ɶ���
			}
			unlock();//����
		}
		return lazy;//����Ψһ�Ķ���
	}

private:
	LazySingleTon()//˽�й���
	{
		std::cout<<"create object"<<std::endl;
	}
	LazySingleTon(const LazySingleTon&);//˽�п�������
	static LazySingleTon* lazy;//��̬��Ա����
};
LazySingleTon* LazySingleTon::lazy=NULL;//��ʼ��

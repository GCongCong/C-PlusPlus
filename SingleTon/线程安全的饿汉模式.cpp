//3. ����ģʽ--�̰߳�ȫ
class HunSingleTon
{
public:
	static HunSingleTon* getIntance()//Ψһ�Ĺ��нӿڣ������Ѿ����ɺõ�Ψһ�Ķ���
	{
		return Hun;//����Ψһ�Ķ���
	}

private:
	HunSingleTon()//˽�й���
	{
		std::cout<<"create Hun object"<<std::endl;
	}
	HunSingleTon(const HunSingleTon&);//˽�п�������
	static HunSingleTon* Hun;//��̬��Ա����
};
HunSingleTon* HunSingleTon::Hun=new HunSingleTon();//����Ψһ�Ķ���
int main()
{

	HunSingleTon* Hun1=HunSingleTon ::getIntance();
	HunSingleTon* Hun2=HunSingleTon ::getIntance();
	
}

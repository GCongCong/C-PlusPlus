# include<iostream>
# include<cstring>
class Person
{
public:
	void eat()
	{
		std::cout<<"eating"<<std::endl;
	}
	void study()
	{
		std::cout<<"studing"<<std::endl;
	}
private:
	char name[10];
    bool sex;//�Ա�
    int age;//����

};
class CGoods
{
public:
	CGoods(char* n,double p,int a)//���������Ĺ��캯��
	{
		mname=new char[strlen(n)+1]();
		strcpy_s(mname,strlen(n)+1,n);
		mprice=p;
		mamount=a;
		std::cout<<"CGoods(char*,int,int)"<<std::endl;
	}
	CGoods()//�޲ι��캯��
	{
		mname=new char[1]();
		std::cout<<"CGoods()"<<std::endl;
	}
	CGoods(int a)//int�����Ĺ��캯��
	{
		mname=new char[1]();
		mamount=a;
		std::cout<<"CGoods(int)"<<std::endl;
	}
	CGoods(const CGoods& temp)
	{
		mname=new char [strlen(temp.mname)+1]();
		strcpy_s(mname,strlen(temp.mname)+1,temp.mname);
		mprice=temp.mprice;
		mamount=temp.mamount;
		std::cout<<"CGoods& "<<std::endl;
	}
	CGoods& operator=(const CGoods& rhs)
	{
		if(this != &rhs)
		{
			delete[] mname;
			mname=new char [strlen(rhs.mname)+1]();
			strcpy_s(mname,strlen(rhs.mname)+1,rhs.mname);
			mprice=rhs.mprice;
			mamount=rhs.mamount;
		}
		std::cout<<"CGoods ="<<std::endl;
		return *this;
	}
	~CGoods()
	{
		delete[] mname;
		mname=NULL;
		std::cout<<"~CGoods"<<std::endl;
	}
	void show()
	{
		std::cout<<"��Ʒ����"<<mname;
		std::cout<<"��Ʒ�۸�"<<mprice;
		std::cout<<"��Ʒ����"<<mamount<<std::endl;
	}
private:
	char* mname;//��Ʒ����
	double mprice;//��Ʒ�۸�
	int mamount;//��Ʒ����
};
CGoods ggood1("g1",4,10);//1.ȫ�ֶ���
static CGoods ggood2("g2",2,10);//2.��̬ȫ�ֶ���
int main()
{
	std::cout<<"******4*******"<<std::endl;
	CGoods lgood1;//4.�ֲ�����
	std::cout<<"******4*******"<<std::endl;
	CGoods lgood2=lgood1;
	std::cout<<"******5*******"<<std::endl;
	static CGoods lgood3("13",30,10);//5.��̬�ֲ�����
	std::cout<<"******5*******"<<std::endl;
	std::cout<<"******6*******"<<std::endl;
	CGoods lgood4=CGoods("14",40,10);//6.��ʽ������ʱ���������ɶ���
	std::cout<<"******6*******"<<std::endl;
	std::cout<<"******7*******"<<std::endl;
	CGoods lgood5=20;//7.��ʽ������ʱ���������ɶ���
	std::cout<<"******7*******"<<std::endl;
	std::cout<<"******8*******"<<std::endl;
	lgood1=CGoods("tmp",20,30);//8.��ʽ������ʱ������������ֵ
	std::cout<<"******8*******"<<std::endl;
	std::cout<<"******9*******"<<std::endl;
	lgood2=30;//9.��ʽ������ʱ������������ֵ
	std::cout<<"******9*******"<<std::endl;

	std::cout<<"******10*******"<<std::endl;
	lgood3=(CGoods)(10,20,30,40);//10.��϶��ű��ʽ��ǿתΪ�Զ�������
	std::cout<<"******10*******"<<std::endl;
	std::cout<<"******11*******"<<std::endl;
	CGoods* pc1=new CGoods("pc1",10,20);//11.��̬����һ������
	std::cout<<"******11*******"<<std::endl;
	std::cout<<"******12*******"<<std::endl;
	CGoods* pc2=new CGoods[2];//12.��̬����2������
	std::cout<<"******12*******"<<std::endl;
	std::cout<<"******13*******"<<std::endl;
	CGoods* pc3=&CGoods("pc3",10,20);//13.ָ��ָ����ʱ�����ַ
	std::cout<<"******13*******"<<std::endl;
	std::cout<<"******14*******"<<std::endl;
	CGoods& rc3=CGoods("pc3",10,20);//14.����ָ����ʱ����
	std::cout<<"******14*******"<<std::endl;

	delete pc1;
	delete[] pc2;
	return 0;

}
//std::cout<<"******3*******"<<std::endl;������� 
CGoods ggood3("g3",3,10);//3. ȫ�ֶ���
//std::cout<<"******3*******"<<std::endl;

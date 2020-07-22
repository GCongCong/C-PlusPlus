/*������a+bi*/

class CComplex
{
public:
	CComplex(int real,int image)
		:mreal(real),mimage(image)
	{}
	//1.���أ�����+��ֵ
	const CComplex operator+(int val)
	{
		return CComplex(mreal+val,mimage);
	}
	//2.���أ���ֵ+����,��Ϊ����������Ƕ�������д�����⣬����������Ϊ��Ԫ����
	friend const CComplex operator+(int val,CComplex& c);
	//3.����>
	bool operator>(CComplex& c)
	{
		return (mreal>c.mreal)||((mreal==c.mreal)&&(mimage>c.mimage));
	}
	//4.�������<<,��Ϊ����������Ƕ�������д�����⣬����������Ϊ��Ԫ����
	friend std::ostream& operator<<(std::ostream& out,const CComplex& c);
	//5.��������>>,ͬ��д������
	friend std::istream& operator>>(std::istream& in, CComplex& c);
	//6.����==
	bool operator==(CComplex& c)
	{
		return (mreal==c.mreal)&&(mimage==c.mimage);
	}
private:
	int mreal;//ʵ��
	int mimage;//�鲿
};

const CComplex operator+(int val,CComplex& c)
{
	return CComplex(c.mreal+val,c.mimage);
}
std::ostream& operator<<(std::ostream& out,const CComplex& c)
{
	out<<c.mreal<<"i+"<<c.mimage;
	return out;
}
std::istream& operator>>(std::istream& in, CComplex& c)
{
	in>>c.mreal;
	in>>c.mimage;
	return in;
}
int main()
{
	CComplex cc1(10,20);
	CComplex cc2=cc1+10;
	CComplex cc3=10+cc1;
	if(cc2>cc1)
	{
		std::cout<<cc2<<std::endl;
	}
	if(cc3==cc2)
	{
		std::cout<<cc1<<std::endl;
	}
	std::cin>>cc2;
	std::cout<<cc2<<std::endl;
	return 0;
}


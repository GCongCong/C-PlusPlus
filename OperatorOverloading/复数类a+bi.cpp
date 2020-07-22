/*复数类a+bi*/

class CComplex
{
public:
	CComplex(int real,int image)
		:mreal(real),mimage(image)
	{}
	//1.重载：对象+数值
	const CComplex operator+(int val)
	{
		return CComplex(mreal+val,mimage);
	}
	//2.重载：数值+对象,因为左操作数不是对象，所以写到类外，在类内声明为友元函数
	friend const CComplex operator+(int val,CComplex& c);
	//3.重载>
	bool operator>(CComplex& c)
	{
		return (mreal>c.mreal)||((mreal==c.mreal)&&(mimage>c.mimage));
	}
	//4.重载输出<<,因为左操作数不是对象，所以写到类外，在类内声明为友元函数
	friend std::ostream& operator<<(std::ostream& out,const CComplex& c);
	//5.重载输入>>,同理写到类外
	friend std::istream& operator>>(std::istream& in, CComplex& c);
	//6.重载==
	bool operator==(CComplex& c)
	{
		return (mreal==c.mreal)&&(mimage==c.mimage);
	}
private:
	int mreal;//实部
	int mimage;//虚部
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


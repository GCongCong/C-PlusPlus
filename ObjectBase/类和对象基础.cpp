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
    bool sex;//性别
    int age;//年龄

};
class CGoods
{
public:
	CGoods(char* n,double p,int a)//三个参数的构造函数
	{
		mname=new char[strlen(n)+1]();
		strcpy_s(mname,strlen(n)+1,n);
		mprice=p;
		mamount=a;
		std::cout<<"CGoods(char*,int,int)"<<std::endl;
	}
	CGoods()//无参构造函数
	{
		mname=new char[1]();
		std::cout<<"CGoods()"<<std::endl;
	}
	CGoods(int a)//int参数的构造函数
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
		std::cout<<"商品名称"<<mname;
		std::cout<<"商品价格"<<mprice;
		std::cout<<"商品数量"<<mamount<<std::endl;
	}
private:
	char* mname;//商品名称
	double mprice;//商品价格
	int mamount;//商品数量
};
CGoods ggood1("g1",4,10);//1.全局对象
static CGoods ggood2("g2",2,10);//2.静态全局对象
int main()
{
	std::cout<<"******4*******"<<std::endl;
	CGoods lgood1;//4.局部变量
	std::cout<<"******4*******"<<std::endl;
	CGoods lgood2=lgood1;
	std::cout<<"******5*******"<<std::endl;
	static CGoods lgood3("13",30,10);//5.静态局部变量
	std::cout<<"******5*******"<<std::endl;
	std::cout<<"******6*******"<<std::endl;
	CGoods lgood4=CGoods("14",40,10);//6.显式生成临时对象来生成对象
	std::cout<<"******6*******"<<std::endl;
	std::cout<<"******7*******"<<std::endl;
	CGoods lgood5=20;//7.隐式生成临时对象来生成对象
	std::cout<<"******7*******"<<std::endl;
	std::cout<<"******8*******"<<std::endl;
	lgood1=CGoods("tmp",20,30);//8.显式生成临时对象来给对象赋值
	std::cout<<"******8*******"<<std::endl;
	std::cout<<"******9*******"<<std::endl;
	lgood2=30;//9.隐式生成临时对象来给对象赋值
	std::cout<<"******9*******"<<std::endl;

	std::cout<<"******10*******"<<std::endl;
	lgood3=(CGoods)(10,20,30,40);//10.结合逗号表达式，强转为自定义类型
	std::cout<<"******10*******"<<std::endl;
	std::cout<<"******11*******"<<std::endl;
	CGoods* pc1=new CGoods("pc1",10,20);//11.动态生成一个对象
	std::cout<<"******11*******"<<std::endl;
	std::cout<<"******12*******"<<std::endl;
	CGoods* pc2=new CGoods[2];//12.动态生成2个对象
	std::cout<<"******12*******"<<std::endl;
	std::cout<<"******13*******"<<std::endl;
	CGoods* pc3=&CGoods("pc3",10,20);//13.指针指向临时对象地址
	std::cout<<"******13*******"<<std::endl;
	std::cout<<"******14*******"<<std::endl;
	CGoods& rc3=CGoods("pc3",10,20);//14.引用指向临时对象
	std::cout<<"******14*******"<<std::endl;

	delete pc1;
	delete[] pc2;
	return 0;

}
//std::cout<<"******3*******"<<std::endl;不能输出 
CGoods ggood3("g3",3,10);//3. 全局对象
//std::cout<<"******3*******"<<std::endl;

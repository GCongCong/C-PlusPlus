/*1. 重载运算符基础*/
# if 0
# endif
class CInt
{
public:
	CInt(int val):value(val)
	{}
	//重载<
	bool operator<(int len)
	{
		return value<len;
	}
	//重载a++,把a放在临时量中，对a++，返回临时量
	const CInt operator++(int)//int是标识前置++的含义
	{
		CInt temp(*this);//生成局部对象
		value++;
		return temp;
	}
	//重载++a，直接对a++
	CInt& operator++()
	{
		++value;
		return *this;
	}
	//重载[] a[1]=*a+1=1+*a=1[a]，此时i为对象
	int& operator[](int* parr)
	{
		return parr[value];
	}


private:
	int value;
};
int main()
{
	int arr[]={1,2,3,4,5};
	int len=sizeof(arr)/sizeof(arr[0]);
	for(CInt i=0;i<len;i++)
	{
		std::cout<<i[arr]<<" ";
	}
	std::cout<<std::endl;
	return 0;
}


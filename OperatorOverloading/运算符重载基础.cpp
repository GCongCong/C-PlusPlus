/*1. �������������*/
# if 0
# endif
class CInt
{
public:
	CInt(int val):value(val)
	{}
	//����<
	bool operator<(int len)
	{
		return value<len;
	}
	//����a++,��a������ʱ���У���a++��������ʱ��
	const CInt operator++(int)//int�Ǳ�ʶǰ��++�ĺ���
	{
		CInt temp(*this);//���ɾֲ�����
		value++;
		return temp;
	}
	//����++a��ֱ�Ӷ�a++
	CInt& operator++()
	{
		++value;
		return *this;
	}
	//����[] a[1]=*a+1=1+*a=1[a]����ʱiΪ����
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


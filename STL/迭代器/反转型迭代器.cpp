# include<iostream>
# include<deque>
# include<vector>
# include<list>

//5.������
//1. ��ת������
template<typename Container>
void show(Container& con)
{
	typename Container::reverse_iterator it=con.rbegin();//ָ����棬�����ӡ
	for(;it!=con.rend();it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<std::endl;
}
int main()
{
	int a[]={3,2,1,5,4};
	int len=sizeof(a)/sizeof(a[0]);
	std::vector<int> vec(a,a+len);
	show(vec);
}


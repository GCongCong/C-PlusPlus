# include<iostream>
# include<deque>
# include<vector>
# include<list>

//5.迭代器
//1. 反转迭代器
template<typename Container>
void show(Container& con)
{
	typename Container::reverse_iterator it=con.rbegin();//指向后面，反向打印
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


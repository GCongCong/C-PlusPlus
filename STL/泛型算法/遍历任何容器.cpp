# include<iostream>
# include<deque>
# include<vector>
# include<list>

//4.泛型算法
//4-1 遍历任何容器
template<typename Container>
void show(Container& con)
{
	typename Container::iterator it=con.begin();//iterator为从属名称，所以声明类型，否则编译器不知道
	for(;it!=con.end();it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<std::endl;
}
int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9,10};
	int len=sizeof(a)/sizeof(a[0]);
	std::vector<int> vec(a,a+len);//通过迭代器区间构造deque
	std::list<int> lis(a,a+len);//通过迭代器区间构造deque
	std::deque<int> deq(a,a+len);//通过迭代器区间构造deque
	std::cout<<"vector"<<std::endl;
	show(vec);
	std::cout<<"list"<<std::endl;
	show(lis);
	std::cout<<"deque"<<std::endl;
	show(deq);
}

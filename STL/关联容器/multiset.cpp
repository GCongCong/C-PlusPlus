```cpp
# include<iostream>
# include<deque>
# include<vector>
# include<list>
# include<algorithm>
# include<iterator>
# include<set>
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
	std::multiset<int> myiset;//无参构造
	int a[]={0,1,2,3,4,5,6,7};
	int len=sizeof(a)/sizeof(a[0]);
	std::multiset<int> myset(a,a+len);//通过迭代器区间构造
	//2.迭代器打印整型容器
	show(myset);
	//3.迭代器指向起始位置，将数组的元素插入2号下标,会去重，所以不会插入
	myset.insert(a+2,a+5);
	show(myset);
}


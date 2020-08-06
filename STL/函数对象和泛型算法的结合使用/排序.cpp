# include<iostream>
# include<deque>
# include<vector>
# include<list>


//4-2 排序
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
// 实现降序
template<typename T>
class down
{
public:
	bool operator()(T& fir,T& las)
	{
		return fir < las;//表示只有第一个数小于第二个允许交换，那么小的在后面，降序
	}
};
//实现升序
template<typename T>
class up
{
public:
	bool operator()(T& fir,T& las)
	{
		return fir > las;
	}
};


template<typename Iterator,typename Com>
void Sort(Iterator first,Iterator last,Com& com)
{
	Iterator i=first;
	Iterator j=first;
	int k=0;//标记趟数
	for(i;i<last-1;i++,k++)
	{
		for(j=first;j<last-k-1;j++)//不能用last-j，因为迭代器-迭代器=偏移，不能和j比较，j是迭代器，所以引入k
		{
			if(com(*j,*(j+1)))//调用com.operator()(*j,*(j+1),对两个数进行比较，不同函数对象，不同的比较方式
			{
				typename Iterator::value_type tmp=*j;//获取当前迭代器的类型，定义一样类型的tmp，从属名称，声明类型
				*j=*(j+1);
				*(j+1)=tmp;
			}
		}
	}
}
int main()
{
	int a[]={3,2,1,5,4};
	int len=sizeof(a)/sizeof(a[0]);
	std::vector<int> vec(a,a+len);//通过迭代器区间构造deque
	std::vector<int>::iterator itv=vec.begin();
	show(vec);
	Sort(vec.begin(),vec.end(),down<int>());
	show(vec);
	Sort(vec.begin(),vec.end(),up<int>());
	show(vec);

}


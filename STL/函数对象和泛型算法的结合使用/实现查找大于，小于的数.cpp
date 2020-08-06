# include<iostream>
# include<deque>
# include<vector>
# include<list>

//4.函数对象
//实现小于
template<typename T>
class ComMin
{
public:
	ComMin(T v = T())
		:value(v)
	{}
	bool operator()(T& arg)//重载()实现小于功能
	{
		return arg < value;
	}
private:
	T value;//保存基准数
};
template<typename T>
class ComMax
{
public:
	ComMax(T v = T())
		:value(v)
	{}
	bool operator()(T& arg)//实现大于功能
	{
		return arg > value;
	}
private:
	T value;
};
//泛型算法
template <typename Iterator,typename Com>//对象
Iterator Find(Iterator first,Iterator last,Com& com)//传入对象
{
	for(;first != last;first++)
	{
		if(com(*first))//调用com.operator()(*first)，*first和基准比较，如10，小于/大于就会跳出
		{
			break;
		}
	}
	return first;
}
int main()
{
	int a[]={3,1,2,3,4,5,6,7,8,9,10};
	int len=sizeof(a)/sizeof(a[0]);
	std::vector<int> vec(a,a+len);//通过迭代器区间构造deque
	std::list<int> lis(a,a+len);//通过迭代器区间构造deque
	std::deque<int> deq(a,a+len);//通过迭代器区间构造deque
	std::vector<int>::iterator itv=Find(vec.begin(),vec.end(),ComMin<int>(4));//找到第一个比4小的
	if(itv!=vec.end())
	{
		std::cout<<"vector find: "<<*itv<<std::endl;
	}
	else
	{
		std::cout<<"vector no exist"<<std::endl;
	}
	std::deque<int>::iterator itd=Find(deq.begin(),deq.end(),ComMax<int>(9));//找到比9大的
	if(itd!=deq.end())
	{
		std::cout<<"deque find: "<<*itd<<std::endl;
	}
	else
	{
		std::cout<<"deque no exist"<<std::endl;
	}
}



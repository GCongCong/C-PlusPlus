# include<iostream>
# include<deque>
# include<vector>
# include<list>

//4.��������
//ʵ��С��
template<typename T>
class ComMin
{
public:
	ComMin(T v = T())
		:value(v)
	{}
	bool operator()(T& arg)//����()ʵ��С�ڹ���
	{
		return arg < value;
	}
private:
	T value;//�����׼��
};
template<typename T>
class ComMax
{
public:
	ComMax(T v = T())
		:value(v)
	{}
	bool operator()(T& arg)//ʵ�ִ��ڹ���
	{
		return arg > value;
	}
private:
	T value;
};
//�����㷨
template <typename Iterator,typename Com>//����
Iterator Find(Iterator first,Iterator last,Com& com)//�������
{
	for(;first != last;first++)
	{
		if(com(*first))//����com.operator()(*first)��*first�ͻ�׼�Ƚϣ���10��С��/���ھͻ�����
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
	std::vector<int> vec(a,a+len);//ͨ�����������乹��deque
	std::list<int> lis(a,a+len);//ͨ�����������乹��deque
	std::deque<int> deq(a,a+len);//ͨ�����������乹��deque
	std::vector<int>::iterator itv=Find(vec.begin(),vec.end(),ComMin<int>(4));//�ҵ���һ����4С��
	if(itv!=vec.end())
	{
		std::cout<<"vector find: "<<*itv<<std::endl;
	}
	else
	{
		std::cout<<"vector no exist"<<std::endl;
	}
	std::deque<int>::iterator itd=Find(deq.begin(),deq.end(),ComMax<int>(9));//�ҵ���9���
	if(itd!=deq.end())
	{
		std::cout<<"deque find: "<<*itd<<std::endl;
	}
	else
	{
		std::cout<<"deque no exist"<<std::endl;
	}
}



# include<iostream>
# include<deque>
# include<vector>
# include<list>

//4.�����㷨
//4-1 �����κ�����
template<typename Container>
void show(Container& con)
{
	typename Container::iterator it=con.begin();//iteratorΪ�������ƣ������������ͣ������������֪��
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
	std::vector<int> vec(a,a+len);//ͨ�����������乹��deque
	std::list<int> lis(a,a+len);//ͨ�����������乹��deque
	std::deque<int> deq(a,a+len);//ͨ�����������乹��deque
	std::cout<<"vector"<<std::endl;
	show(vec);
	std::cout<<"list"<<std::endl;
	show(lis);
	std::cout<<"deque"<<std::endl;
	show(deq);
}

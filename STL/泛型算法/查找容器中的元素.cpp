# include<iostream>
# include<deque>
# include<vector>
# include<list>

//4.�����㷨
//4-2����Ԫ��
template <typename Iterator,typename T>
Iterator find(Iterator first,Iterator last,T& val)
{
	for(;first != last;first++)
	{
		if(*first == val)
		{
			break;//��ʱfirstָ�������Чλ�ã����û���ҵ�����ôfirst��ָ������ĩβ����Чλ��
		}
	}
	return first;
}
int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9,10};
	int len=sizeof(a)/sizeof(a[0]);
	std::vector<int> vec(a,a+len);//ͨ�����������乹��deque
	std::list<int> lis(a,a+len);//ͨ�����������乹��deque
	std::deque<int> deq(a,a+len);//ͨ�����������乹��deque
	std::vector<int>::iterator itv=find(vec.begin(),vec.end(),6);//vector����
	if(itv!=vec.end())//��ʾ���صĵ���������Чλ�ã��ҵ���
	{
		std::cout<<"vector find: "<<*itv<<std::endl;
	}
	else
	{
		std::cout<<"vector no exist"<<std::endl;
	}
	std::list<int>::iterator its=find(lis.begin(),lis.end(),1);
	if(its!=lis.end())
	{
		std::cout<<"list find: "<<*its<<std::endl;
	}
	else
	{
		std::cout<<"list no exist"<<std::endl;
	}
	std::deque<int>::iterator itd=find(deq.begin(),deq.end(),90);
	if(itd!=deq.end())
	{
		std::cout<<"deque find: "<<*itd<<std::endl;
	}
	else
	{
		std::cout<<"deque no exist"<<std::endl;
	}


}

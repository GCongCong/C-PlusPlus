# include<iostream>
# include<deque>
# include<vector>
# include<list>


//4-2 ����
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
// ʵ�ֽ���
template<typename T>
class down
{
public:
	bool operator()(T& fir,T& las)
	{
		return fir < las;//��ʾֻ�е�һ����С�ڵڶ�������������ôС���ں��棬����
	}
};
//ʵ������
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
	int k=0;//�������
	for(i;i<last-1;i++,k++)
	{
		for(j=first;j<last-k-1;j++)//������last-j����Ϊ������-������=ƫ�ƣ����ܺ�j�Ƚϣ�j�ǵ���������������k
		{
			if(com(*j,*(j+1)))//����com.operator()(*j,*(j+1),�����������бȽϣ���ͬ�������󣬲�ͬ�ıȽϷ�ʽ
			{
				typename Iterator::value_type tmp=*j;//��ȡ��ǰ�����������ͣ�����һ�����͵�tmp���������ƣ���������
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
	std::vector<int> vec(a,a+len);//ͨ�����������乹��deque
	std::vector<int>::iterator itv=vec.begin();
	show(vec);
	Sort(vec.begin(),vec.end(),down<int>());
	show(vec);
	Sort(vec.begin(),vec.end(),up<int>());
	show(vec);

}


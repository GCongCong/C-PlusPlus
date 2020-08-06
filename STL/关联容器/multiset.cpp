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
	typename Container::iterator it=con.begin();//iteratorΪ�������ƣ������������ͣ������������֪��
	for(;it!=con.end();it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<std::endl;
}
int main()
{
	std::multiset<int> myiset;//�޲ι���
	int a[]={0,1,2,3,4,5,6,7};
	int len=sizeof(a)/sizeof(a[0]);
	std::multiset<int> myset(a,a+len);//ͨ�����������乹��
	//2.��������ӡ��������
	show(myset);
	//3.������ָ����ʼλ�ã��������Ԫ�ز���2���±�,��ȥ�أ����Բ������
	myset.insert(a+2,a+5);
	show(myset);
}


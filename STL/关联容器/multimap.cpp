# include<iostream>
# include<deque>
# include<vector>
# include<list>
# include<algorithm>
# include<iterator>
# include<set>
# include<map>
template<typename Container>
void show(Container& con)
{
	typename Container::iterator it=con.begin();//iteratorΪ�������ƣ������������ͣ������������֪��
	for(;it!=con.end();it++)
	{
		std::cout <<it->first << "-" << it->second << " ";
	}
	std::cout<<std::endl;
}
int main()
{
	std::multimap<int,int> mymap;//�޲ι���
	//1.����pair���󣬲���ͨ����ֵ����
	std::pair<int,int>p1(2,7);//pair����
	std::pair<int,int>p2(2,1);//���Ա����ظ�keyֵ
	std::pair<int,int>p3(3,6);//pair����
	std::pair<int,int>p4(5,8);//pair����
	mymap.insert(p1);
	mymap.insert(p2);
	mymap.insert(p3);
	mymap.insert(p4);
	show(mymap);	
}


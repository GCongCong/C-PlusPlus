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
	typename Container::iterator it=con.begin();//iterator为从属名称，所以声明类型，否则编译器不知道
	for(;it!=con.end();it++)
	{
		std::cout <<it->first << "-" << it->second << " ";
	}
	std::cout<<std::endl;
}
int main()
{
	std::multimap<int,int> mymap;//无参构造
	//1.插入pair对象，不能通过键值插入
	std::pair<int,int>p1(2,7);//pair对象
	std::pair<int,int>p2(2,1);//可以保存重复key值
	std::pair<int,int>p3(3,6);//pair对象
	std::pair<int,int>p4(5,8);//pair对象
	mymap.insert(p1);
	mymap.insert(p2);
	mymap.insert(p3);
	mymap.insert(p4);
	show(mymap);	
}


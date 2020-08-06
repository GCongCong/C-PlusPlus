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
	std::map<int,int> mymap;//无参构造
	//1.插入pair对象，
	std::pair<int,int>p1(1,1);//pair对象
	mymap.insert(p1);
	show(mymap);
	//2.生成对象插入
	std::map<int,int>::value_type p2(8,1);//生成隐式pair对象
	mymap.insert(p2);
	show(mymap);
	//3.通过键值插入
	mymap[9]=100;
	mymap[2]=6;
	mymap[3]=4;
	mymap[4]=5;
	mymap[2]=1;//将之前保存的key对应的值value顶替，所以现在是2-1，而不是2-6，因为不允许key值重复
	show(mymap);
	//4.通过key值打印：
	std::map<int,int>::iterator it=mymap.begin();
	while(it!=mymap.end())
	{
		std::cout<<it->first<<"---"<<it->second<<" ";
		it++;
	}
	std::cout<<std::endl;
	//5.查找元素1
	std::map<int,int>::iterator fit=mymap.find(1);
	if(fit!=mymap.end())
	{
		std::cout<<fit->first<<"-"<<fit->second<<std::endl;
	}
	else
	{
		std::cout<<"no"<<std::endl;
	}
	//6.删除第2个元素，
	std::map<int,int>::iterator it2=mymap.begin();//指向开始
	mymap.erase(++it2);
	show(mymap);
	//7.删除键值1对应的值
	mymap.erase(1);
	show(mymap);
	//8.删除0~3区间的元素,即0，1，2下标的
	std::map<int,int>::iterator it1=mymap.begin();
	++it1;++it1;++it1;
    mymap.erase(mymap.begin(),it1);
	show(mymap);
}


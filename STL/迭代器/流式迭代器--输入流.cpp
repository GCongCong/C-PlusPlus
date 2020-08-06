# include<iostream>
# include<deque>
# include<vector>
# include<list>
# include<algorithm>
# include<iterator>
//5.迭代器
template<typename Container>
void show(Container& con)
{
	typename Container::iterator it=con.begin();
	for(;it!=con.end();it++)
	{
		std::cout<<*it<<" ";
	}
	std::cout<<std::endl;
}
//2.流式迭代器
int main()
{
	std::vector<int> vec;
	std::copy(std::istream_iterator<int>(std::cin),
		std::istream_iterator<int>(),
		std::back_insert_iterator<std::vector<int>>(vec));//获取键盘数字
	show(vec);//打印

}


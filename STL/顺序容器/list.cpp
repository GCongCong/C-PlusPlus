# include<iostream>
# include<list>
template <typename T>
void show( std::list<T>& vec)
{
	std::list<T>::iterator it=vec.begin();
	while(it!=vec.end())
	{
		std::cout<<*it<<" ";
		it++;
	}
		std::cout<<std::endl;
}
int main()
{
	std::list<int> ilis;//无参构造
	std::list<double> dlis(10);//一个int参数的构造
	std::list<char> clis(10,'c');//两个int参数的构造
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	int len=sizeof(a)/sizeof(a[0]);
	std::list<int> lis(a,a+len);//通过迭代器区间构造
	//2.迭代器打印整型迭代器
	show<int>(lis);
	//3.尾插10
	lis.push_back(10);
	std::cout<<"尾插10"<<std::endl;
	show<int>(lis);
	//头插200
	lis.push_front(200);
	std::cout<<"尾插200"<<std::endl;
	show<int>(lis);
	//4.迭代器指向起始位置，将数组0~5的元素插入0号下标
	std::list<int>::iterator it=lis.begin();//支持双向迭代器，所以不能it+i，只能it++
	lis.insert(it,a,a+5);
	show<int>(lis);
	//5.在0号下标插入2个100
	lis.insert(lis.begin(),2,100);//插入过后，迭代器指向的位置变了，迭代器失效,所以下面使用begin()标识位置
	show<int>(lis);
	//5.删除第2个元素
	lis.erase(lis.begin());
	show<int>(lis);
	//6.删除尾部元素
	lis.pop_back();
	show<int>(lis);
	//删除头部元素
	lis.pop_front();
	show<int>(lis);
	//7.扩容，扩大空间，并初始化为0
	std::cout<<"原来大小："<<lis.size()<<std::endl;
	lis.resize(20);//扩容到20个大小
	std::cout<<"现在大小："<<lis.size()<<std::endl;
	show<int>(lis);
	//6.删除前开始~结尾之间的元素
	lis.erase(lis.begin(),lis.end());//删除0~3
	show<int>(lis);
}

# include<iostream>
# include<vector>

template <typename T>
void show( std::vector<T>& vec)
{
	std::vector<T>::iterator it=vec.begin();
	while(it!=vec.end())
	{
		std::cout<<*it<<" ";
		it++;
	}
		std::cout<<std::endl;
}
int main()
{
	std::vector<int> ivec;//无参构造
	std::vector<double> dvec(10);//一个int参数的构造
	std::vector<char> cvec(10,'c');//两个int参数的构造
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	int len=sizeof(a)/sizeof(a[0]);
	std::vector<int> vec(a,a+len);//通过迭代器区间构造
	//1.数组打印字符迭代器
	for(int i=0;i< cvec.size();i++)
	{
		std::cout<<cvec[i]<<" ";
	}
	std::cout<<std::endl;
	//2.迭代器打印整型迭代器
	show<int>(vec);
	//3.尾插10
	vec.push_back(10);
	std::cout<<"尾插10"<<std::endl;
	show<int>(vec);
	//4.迭代器指向起始位置，将vec的元素插入2号下标
	std::vector<int>::iterator it=vec.begin();
	vec.insert(it+2,a,a+5);
	show<int>(vec);
	//5.在0号下标插入2个100
	vec.insert(it,2,100);//插入过后，迭代器指向的位置变了，迭代器失效,所以下面使用begin()标识位置
	show<int>(vec);
	//6.删除前0~9之间的元素元素
	vec.erase(vec.begin(),vec.begin()+10);//删除0~9
	show<int>(vec);
	//5.删除第2个元素
	vec.erase(vec.begin()+2);
	show<int>(vec);
	//6.删除尾部元素
	vec.pop_back();
	show<int>(vec);
	//7.扩容，扩大空间，并初始化为0
	std::cout<<"原来大小："<<vec.size()<<std::endl;
	vec.resize(20);//扩容到20个大小
	std::cout<<"现在大小："<<vec.size()<<std::endl;
	show<int>(vec);
	//8.预留空间，不用就不会使用，原大小不变
	std::cout<<"原来大小："<<vec.size()<<std::endl;
	vec.reserve(40);//预留40个大小
	std::cout<<"现在大小："<<vec.size()<<std::endl;
	show<int>(vec);
	//9.清除
	vec.clear();
	show<int>(vec);
}

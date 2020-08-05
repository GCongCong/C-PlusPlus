# include<iostream>
# include<deque>
template <typename T>
void show( std::deque<T>& deq)
{
	std::deque<T>::iterator it=deq.begin();
	while(it!=deq.end())
	{
		std::cout<<*it<<" ";
		it++;
	}
		std::cout<<std::endl;
}
int main()
{
	std::deque<int> ideq;//无参构造
	std::deque<double> ddeq(10);//一个int参数的构造
	std::deque<char> cdeq(10,'c');//两个int参数的构造
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	int len=sizeof(a)/sizeof(a[0]);
	std::deque<int> deq(a,a+len);//通过迭代器区间构造
	//1.数组打印字符迭代器
	for(int i=0;i< cdeq.size();i++)
	{
		std::cout<<cdeq[i]<<" ";
	}
	std::cout<<std::endl;
	//2.迭代器打印整型容器
	show<int>(deq);
	//3.尾插10
	deq.push_back(10);
	std::cout<<"尾插10"<<std::endl;
	show<int>(deq);
	//头插200
	deq.push_front(200);
	std::cout<<"头插200"<<std::endl;
	show<int>(deq);
	//4.迭代器指向起始位置，将数组的元素插入2号下标
	std::deque<int>::iterator it=deq.begin();//操作完成后就会失效
	deq.insert(it+2,a,a+5);
	show<int>(deq);
	//5.在0号下标插入2个100
	std::deque<int>::iterator it1=deq.begin();
	deq.insert(it1,2,100);//it迭代器已经失效了，所以重新定义迭代器
	show<int>(deq);
	//6.删除前0~9之间的元素元素
	deq.erase(deq.begin(),deq.begin()+10);//删除0~9
	show<int>(deq);
	//5.删除第2个元素
	deq.erase(deq.begin()+2);
	show<int>(deq);
	//6.删除尾部元素
	deq.pop_back();
	show<int>(deq);
	//删除头部元素
	deq.pop_front();
	show<int>(deq);
	//7.扩容，扩大空间，并初始化为0
	std::cout<<"原来大小："<<deq.size()<<std::endl;
	deq.resize(20);//扩容到20个大小
	std::cout<<"现在大小："<<deq.size()<<std::endl;
	show<int>(deq);
	//9.清除
	deq.clear();
	show<int>(deq);
}

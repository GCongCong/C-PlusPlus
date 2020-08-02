# include<iostream>
//2.带有标志位的智能指针，处理auto_ptr失效的问题，允许多个指针指向同一块内存，最后一个指针释放内存即可
//即所有权不唯一，释放权唯一,利用标志位实现，flag=true进行释放，存在释放权转移的处理
template<typename T>
class Smart_ptr
{
public:
	Smart_ptr(T* ptr)
		:mptr(ptr),flag(true)
	{
		std::cout<<"Smart_ptr()"<<std::endl;
	}
	Smart_ptr(Smart_ptr<T>& rhs)
	{
		mptr = rhs.mptr;
		flag = rhs.flag;//旧指针将自己的释放权给新指针。
		rhs.flag = false;//取消旧指针释放权
	}
	Smart_ptr<T>& operator=(Smart_ptr<T>& rhs)
	{
		if(this != &rhs)
		{
			this->~Smart_ptr();//对原来指向的内存取消释放权,调用析构
			mptr = rhs.mptr;//指向新内存块
			flag = rhs.flag;//旧指针将自己的释放权给新指针。
			rhs.flag = false;//取消旧指针释放权
		}
		return *this;
	}
	T& operator*()
	{
		return *mptr;
	}
	T* operator->()
	{
		return mptr;
	}
	~Smart_ptr()
	{
		if(flag)//判断是否是最后一个指针
		{
			delete mptr;
			std::cout<<"~Smart_ptr()"<<std::endl;
		}
		mptr = NULL;
	}
private:
	bool flag;//释放权的标志
	T* mptr;
};
int main()
{
	Smart_ptr<int> s1 = new int(10);
	*s1=20;
	std::cout<<*s1<<std::endl;
	Smart_ptr<int> s2 = s1;
	*s2=30;
	*s1=40;//解决了auto_ptr所有权失效的问题
}

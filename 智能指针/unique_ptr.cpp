# include<iostream>
//3.前两个智能指针都是因为权限转移出现的问题，现在设计一个不允许转移权限的智能指针，禁止多个指针指向同一块内存
//只有一个指针指向这块内存，将拷贝构造函数赋值运算符写为私有即可，这就是unique_ptr
template<typename T>
class Unique_ptr
{
public:
	Unique_ptr(T* ptr)
		:mptr(ptr)
	{
		std::cout<<"Unique_ptr()"<<std::endl;
	}
	T* operator->()
	{
		return mptr;
	}
	T& operator*()
	{
		return *mptr;
	}
	~Unique_ptr()
	{
		delete mptr;
		std::cout<<"~Unique_ptr()"<<std::endl;
	}

private:
	Unique_ptr(Unique_ptr<T>& rhs);//私有拷贝构造
	Unique_ptr<T>& operator=(Unique_ptr<T>& rhs);//私有赋值
	T* mptr;
};
int main()
{
	Unique_ptr<int> u1=new int(10);
	*u1=20;
	//Unique_ptr<int> u2=u1;//禁止
	std::cout<<*u1<<std::endl;
	//缺陷：代码设计层面只允许一块内存被一个指针指向，但我们可以从代码层面让多个指针指向同一块内存
	/*int* a=new int;
	Unique_ptr<int> u2(a);
	Unique_ptr<int> u3(a);//程序崩溃，a内存被释放多次*/

}

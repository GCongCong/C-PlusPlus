# include<iostream>
//3.ǰ��������ָ�붼����ΪȨ��ת�Ƴ��ֵ����⣬�������һ��������ת��Ȩ�޵�����ָ�룬��ֹ���ָ��ָ��ͬһ���ڴ�
//ֻ��һ��ָ��ָ������ڴ棬���������캯����ֵ�����дΪ˽�м��ɣ������unique_ptr
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
	Unique_ptr(Unique_ptr<T>& rhs);//˽�п�������
	Unique_ptr<T>& operator=(Unique_ptr<T>& rhs);//˽�и�ֵ
	T* mptr;
};
int main()
{
	Unique_ptr<int> u1=new int(10);
	*u1=20;
	//Unique_ptr<int> u2=u1;//��ֹ
	std::cout<<*u1<<std::endl;
	//ȱ�ݣ�������Ʋ���ֻ����һ���ڴ汻һ��ָ��ָ�򣬵����ǿ��ԴӴ�������ö��ָ��ָ��ͬһ���ڴ�
	/*int* a=new int;
	Unique_ptr<int> u2(a);
	Unique_ptr<int> u3(a);//���������a�ڴ汻�ͷŶ��*/

}

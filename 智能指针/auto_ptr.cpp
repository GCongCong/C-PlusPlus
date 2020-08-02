# include<iostream>
//1.auto_ptr,����ȨΨһ����ǰ�ڴ��ֻ����һ��ָ��ָ�������������һ���ڴ�鱻�ͷŶ�ε�����
template<typename T>
class Auto_ptr
{
public:
	Auto_ptr(T* ptr)
		:mptr(ptr)
	{
		std::cout<<"Auto_ptr()"<<std::endl;
	}
	Auto_ptr(Auto_ptr<T>& rhs)//rhsΪ�Ѿ����ڵĶ������¶���ָ��ָ����ָ��ĵ��ڴ棬���Ͽ�ָ�򣬱�֤����ȨΨһ
	{
		std::cout<<"Auto_ptr(&rhs)"<<std::endl;
		mptr = rhs.Release();
	}
	Auto_ptr<T> operator=(Auto_ptr<T>& rhs)//��ֵ���������
	{
		if(this != &rhs)
		{
			std::cout<<"Auto_ptr(operator=)"<<std::endl;
			delete mptr;//�ͷ�ԭ��ָ����ڴ棬ԭ��ָ��ָ����ڴ��ж��ָ��ָ����ô��ʱmptr=NULL,delete NULL����ȷ��
			mptr=rhs.Release();
		}
		return *this;
	}
	T* operator->()
	{
		return mptr;
	}
	T& operator*()
	{
		return *mptr;
	}
	~Auto_ptr()
	{
		delete mptr;
		std::cout<<"~Auto_ptr()"<<std::endl;
	}
private:
	T* Release()//��ָ��������Ȩ����
	{
		T* temp = mptr;//�����ָ���ָ��
		mptr = NULL;//�Ͽ���ָ��ָ���ڴ������
		return temp;//����ָ��ԭ��ָ����ڴ��ַ���أ�����ָ��ָ��
	}
	T* mptr;
};
class Test
{
public:
	void show()
	{
		std::cout<<"Hello"<<std::endl;
	}
};
int main()
{
	//����ָ��Ӧ�ÿ��Ժ���ָͨ���ʹ��һ��
	//1. �����ڴ�int *p = new int(10);
	Auto_ptr<int> pa1 = new int(10);
	//2. �����ø�ֵ*p=20
	*pa1=20;
	std::cout<<"*pa1="<<*pa1<<std::endl;
	//3. ָ����󣬵��ú����磺Test* ptest = new Test();ptest->show();
	Auto_ptr<Test>pa2=new Test();
	pa2->show();
	//4.ȱ�ݣ�����ָ����ǰʧЧ����
	/*Auto_ptr<int> pa3 = new int(10);
	Auto_ptr<int> pa4 = pa3;//��ʱpa3ָ���Ѿ�ʧЧΪNULL
	*pa4=30;//�ɹ�����Ϊ��ʱ���Ѿ�������ڴ������Ȩ
	*pa3=40;//ʧ�ܣ���ʱpa3ΪNULL���Ա���������������
	return 0;*/
}

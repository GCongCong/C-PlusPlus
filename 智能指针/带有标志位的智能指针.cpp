# include<iostream>
//2.���б�־λ������ָ�룬����auto_ptrʧЧ�����⣬������ָ��ָ��ͬһ���ڴ棬���һ��ָ���ͷ��ڴ漴��
//������Ȩ��Ψһ���ͷ�ȨΨһ,���ñ�־λʵ�֣�flag=true�����ͷţ������ͷ�Ȩת�ƵĴ���
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
		flag = rhs.flag;//��ָ�뽫�Լ����ͷ�Ȩ����ָ�롣
		rhs.flag = false;//ȡ����ָ���ͷ�Ȩ
	}
	Smart_ptr<T>& operator=(Smart_ptr<T>& rhs)
	{
		if(this != &rhs)
		{
			this->~Smart_ptr();//��ԭ��ָ����ڴ�ȡ���ͷ�Ȩ,��������
			mptr = rhs.mptr;//ָ�����ڴ��
			flag = rhs.flag;//��ָ�뽫�Լ����ͷ�Ȩ����ָ�롣
			rhs.flag = false;//ȡ����ָ���ͷ�Ȩ
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
		if(flag)//�ж��Ƿ������һ��ָ��
		{
			delete mptr;
			std::cout<<"~Smart_ptr()"<<std::endl;
		}
		mptr = NULL;
	}
private:
	bool flag;//�ͷ�Ȩ�ı�־
	T* mptr;
};
int main()
{
	Smart_ptr<int> s1 = new int(10);
	*s1=20;
	std::cout<<*s1<<std::endl;
	Smart_ptr<int> s2 = s1;
	*s2=30;
	*s1=40;//�����auto_ptr����ȨʧЧ������
}

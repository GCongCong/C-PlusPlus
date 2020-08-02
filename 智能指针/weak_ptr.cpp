# include<iostream>
//5.���ǿָ�뻥���������⣬����ָ�룬��ָ��ָ��ʱ���������仯��ֻ��ָ��ָ��ı伴��
//���ܵ���ʹ�ã���ǿָ�����ʹ��
//4.shared_ptr����ͨ��Ȩ��ת�Ƶķ�ʽ��������ָ��ָ��ͬһ���ڴ�
//��һ���ṹ���������ڴ���ַ��ָ������ڴ���ַ��ָ����������ü�����������������ӣ�ɾ�������ң���ò���
//shared_ptrÿָ��һ���ڴ棬����������һ����¼���ͷ�һ��ɾ��һ����
//4-1�����ݽṹ����shared_ptrָ����ڴ��,���ý�㱣��һ���ڴ���¼��һ����¼������ַ������;��Ϊ��ַ�����ֶ�����֪���ͣ����Բ���Ҫʹ��ģ��
class Manage
{
public:
	Manage()
	{
		std::cout<<"total[10]�������"<<std::endl;
		current = 0;
	}
	//1.���һ���ڴ����Ϣ�����
	void add(void* ptr)
	{
		int i = find(ptr);//���Ҹ��ڴ���Ƿ����
		if(i != -1)//��ʾ����
		{
			total[i].count++;//��Ӧ�ڴ�����++����
		}
		else//������
		{
			total[current].addr = ptr;//����ַ����ṹ��
			total[current].count = 1;//����Ϊ1
			current++;
		}
	}
	//2. ���ټ���,��������Ϊ0����ʾ���һ��ָ��Դ��ڴ��ָ����������ǲ�����յ�ַ��¼��ֻ�ǲ��������
	//���Խṹ��ֻ�ܱ���10���ڴ��ַ��Ϣ
	void del(void* ptr)
	{
		int i = find(ptr);
		if(i < 0)//��ʾû�ҵ����׳��쳣
		{
			throw std::exception("ptr error");
		}
		else
		{
			if(total[i].count>0)
			{
				total[i].count--;
			}
		}
	}
	//3.����ڴ������ü���
	int getc(void* ptr)
	{
		int i = find(ptr);
		if(i < 0)
		{
			return -1;
		}
		else
		{
			return total[i].count;
		}
	}
	//4.��ӡ�����ڴ�����Ϣ
	void show()
	{
		std::cout<<"-------���Թ���10���ڴ��ַ-------"<<std::endl;
		for(int i = 0;i < 10;i++)
		{
			std::cout<<"��"<<i<<"����㱣����ڴ���ַ��"<<total[i].addr<<"ָ���ڴ���ָ�������"<<total[i].count<<std::endl;
		}
		std::cout<<"----------------------------------"<<std::endl;
	}
private:
	//���ҵ�ǰ���ݽṹ���Ƿ���ڸõ�ַ
	int find(void* ptr)
	{
		for(int i = 0;i<10;i++)
		{
			if(ptr == total[i].addr)
				return i;
		}
		return -1;
	}
	class Node//һ����¼
	{
	public:
		Node(void* a = NULL,int c = 0)
			:addr(a),count(c)
		{}
		void* addr;
		int count;
	};
	Node total[10];//��ʾ���Լ�¼10���ڴ�����Ϣ
	int current;//current֮ǰ���Ѿ���¼���ڴ��ַ��Ϣ�����������������ЧԪ�ظ���
};
//4-2shared_ptrָ��ָ����ڴ�ͨ�����������������Զ���һ��ȫ�־�̬���������
template<typename T>
class Shared_ptr
{
public:
	Shared_ptr(T* ptr = NULL)
		:mptr(ptr)
	{
		manage.add(mptr);//����ָ��ָ���ڴ棬���ڴ��ַ��ӵ�����ṹ����
	}
	Shared_ptr(Shared_ptr<T>& rhs)
	{
		mptr = rhs.mptr;
		manage.add(mptr);
	}
	Shared_ptr<T> operator=(Shared_ptr<T>& rhs)//��ֵ�����������ڴ�飬��ָ���µ�
	{
		if(this != &rhs)
		{
			this->~Shared_ptr();//�����ָ��
			mptr=rhs.mptr;
			manage.add(mptr);
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
	void showma()
	{
		manage.show();
	}
	 T* getptr()const//����ָ����
	{
		return mptr;
	}
	~Shared_ptr()
	{
		manage.del(mptr);//�����ڴ��ַ����
		if(manage.getc(mptr) == 0)//�����ʱ�ڴ����Ϊ0����ʾ��ǰָ��Ϊ���һ��ָ�룬�ͷ��ڴ��
		{
			delete mptr;
		}
		else//������ΪNULL���ɡ�
		{
			mptr=NULL;
		}
	}
private:
	T* mptr;
	static Manage manage;
};
template<typename T>
Manage Shared_ptr<T>::manage;

//5.���ǿָ�뻥���������⣬����ָ�룬��ָ��ָ��ʱ���������仯��ֻ��ָ��ָ��ı伴��
//���ܵ���ʹ�ã���ǿָ�����ʹ��
template<typename T>
class Weak_ptr
{
public:
	Weak_ptr(T* ptr=NULL)
		:mptr(ptr)
	{}
	Weak_ptr(Weak_ptr<T>& rhs)
	{
		mptr=rhs.mptr;
	}
	Weak_ptr<T> operator= (Weak_ptr<T>& rhs)//��ָ��=��ָ�븳ֵ
	{
		if(this != &rhs)
		{
			mptr=rhs.mptr;
		}
		return *this;
	}
	Weak_ptr<T> operator= (const Shared_ptr<T>& rhs)//��ָ��=ǿָ�븳ֵ������ֱ�ӷ���Shared_ptr��˽�г�Ա�����Դӹ��нӿڻ�ȡ
	{
		mptr=rhs.getptr();//������ֻ�ܵ��ó�����������getptr��Ҫ��const����
		return *this;
	}
	~Weak_ptr()
	{}
private:
	T* mptr;
};
class B;
class A
{
public:
	A()
	{
		std::cout<<"A()"<<std::endl;
	};
	~A()
	{
		std::cout<<"~A()"<<std::endl;
	}
	//Shared_ptr<B> spa;����ǿָ�뻥���������� 
	Weak_ptr<B> spa;
};
class B
{
public:
	B()
	{
		std::cout<<"B()"<<std::endl;
	};
	~B()
	{
		std::cout<<"~B()"<<std::endl;
	}
	Weak_ptr<A> spb;
};
int main()
{
	/*int* a = new int(10);
	Shared_ptr<int> s1(a);
	Shared_ptr<int> s2(a);
	Shared_ptr<int> s3(a);
	Shared_ptr<int> s4 = new int(20);
	Shared_ptr<int> s5=s4;
	s1=s5;
	s5.showma();
	*/
	//ȱ�ݣ�ǿָ���ڲ��Ļ������ã�ʹ����ָ���� 
	Shared_ptr<A> pa = new A();//A�ڲ�����ǿָ��
	Shared_ptr<B> pb = new B();//BҲ����
	pa->spa=pb;//����ָ��
	pb->spb=pa;//����ֻ������pa����ʱA���ɵĶ��ڴ���2��ָ��ָ�򣬵���ֻ������pa,�ڴ�鲻�ܱ��ͷţ���Ϊ����Ϊ1
}

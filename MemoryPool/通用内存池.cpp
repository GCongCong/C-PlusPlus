const int MEM_Size=10;
template<typename T>
class MEM_Pool
{
public:
	MEM_Pool()
	{
		pool=NULL;
		std::cout<<"����Poolָ��"<<std::endl;
	}
	void* Alloc(size_t size)
	{
		if(pool==NULL)
		{
			pool=(Node*)new char [(size+4)*10]();//����ָ�������Լ�4�ֽ�
			Node* pcur=pool;
			for(pcur;pcur<pool+MEM_Size-1;pcur=pcur+1)
			{
				pcur->pnext=pcur+1;
			}
			pcur->pnext=NULL;
			std::cout<<"�����ڴ��,��ʱpoolָ��ָ��"<<pool<<std::endl;
		}
		void* ptr=pool;
		pool=pool->pnext;
		std::cout<<"���ڴ���з���һ���ڴ棬poolָ��ָ��"<<pool<<std::endl;
		return ptr;

	}
	void Dealloc(void* ptr)
	{
		Node* q=(Node*)ptr;
		if(q==NULL)
		{
			return;
		}
		q->pnext=pool;
		pool=q;
		std::cout<<"�ڴ�ػ���һ���ڴ棬poolָ��ָ��"<<pool<<std::endl;
	}

private:
	class Node
	{
	public:
		Node(T data=T())
			:mdata(data),pnext(NULL)
		{
			std::cout<<"Node"<<std::endl;
		}
	public:
		T mdata;
		Node* pnext;
	};
	Node* pool;

};
class Student
{
public: 
	Student(std::string name,std::string id,int age)
		:mname(name),mid(id),mage(age)
	{}
	void* operator new(size_t size)//����new�������ڴ���е�new
	{
		return mm.Alloc(size);
	}
	void operator delete(void* ptr)
	{
		mm.Dealloc(ptr);
	}
private:
	std::string mname;
	std::string mid;
	int mage;
	static MEM_Pool<Student> mm;//ʵ����һ���ڴ�ض���
};
MEM_Pool<Student> Student::mm;

int main()
{
	Student* pstu1=new Student("zhangsan","001",20);
	Student* pstu2=new Student("wangwu","002",30);
	
	//delete pstu1;
	delete pstu2;

	return 0;

}

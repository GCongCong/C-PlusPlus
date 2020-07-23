const int MEM_Size=10;
template<typename T>
class MEM_Pool
{
public:
	MEM_Pool()
	{
		pool=NULL;
		std::cout<<"产生Pool指针"<<std::endl;
	}
	void* Alloc(size_t size)
	{
		if(pool==NULL)
		{
			pool=(Node*)new char [(size+4)*10]();//存在指针域，所以加4字节
			Node* pcur=pool;
			for(pcur;pcur<pool+MEM_Size-1;pcur=pcur+1)
			{
				pcur->pnext=pcur+1;
			}
			pcur->pnext=NULL;
			std::cout<<"开辟内存池,此时pool指针指向："<<pool<<std::endl;
		}
		void* ptr=pool;
		pool=pool->pnext;
		std::cout<<"从内存池中分配一块内存，pool指针指向："<<pool<<std::endl;
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
		std::cout<<"内存池回收一块内存，pool指针指向："<<pool<<std::endl;
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
	void* operator new(size_t size)//重载new，调用内存池中的new
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
	static MEM_Pool<Student> mm;//实例化一个内存池对象
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

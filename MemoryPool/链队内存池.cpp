const int  Node_count=10;
template<typename T>
class Queue;
template<typename T>
class Node
{
public:
	Node(T val=T())
		:mdata(val),pnext(NULL)
	{}
	void * operator new(size_t size)//重载关键字new，实现内存池的开辟，分配一块内存存放结点
	{
		if(pool==NULL)//表示现在内存池没有生成，所以开辟内存池
		{
			pool=(Node<T>*)new char[size*Node_count];
			Node<T>* pcur=pool;
			for(pcur;pcur<pool+Node_count-1;pcur=pcur+1)//通过加法让指针偏移，让内存池中所有结点指向下一个结点，串起来
			{
				pcur->pnext=pcur+1;
			}
			pcur->pnext=NULL;//内存池最后一个结点为NULL
		}
		void* ptr=pool;
		pool=pool->pnext;
		return ptr;
	}
	void operator delete(void* ptr)//重载关键字delete，将分配的结点插入内存池
	{
		Node<T>* q=(Node<T>*)ptr;
		q->pnext=pool;
		pool=q;
	}
private:
	T mdata;
	Node<T>* pnext;
	static Node<T>* pool;//指向内存池的开始
	template<typename T>
	friend class Queue;
};

template<typename T>
Node<T>* Node<T>::pool = NULL;

template<typename T>
class Queue
{
public:
	Queue()
	{
		phead=ptail=new Node<T>();//这时调用自己写的New，从内存池分配一块做队头
	}
	void push(T val)//队尾入队
	{
		Node<T>* pnewnode=new Node<T>(val);//插入数据，从内存池分配结点
		ptail->pnext=pnewnode;
		ptail=ptail->pnext;
	}
	bool empty()
	{
		return (phead==ptail)&&(phead!=NULL);
	}
	void pop()//队头出队
	{
		if(empty())
		{
			return;
		}
		Node<T>* pcur=phead->pnext;
		phead->pnext=pcur->pnext;
		delete pcur;//这时调用的是我们重载的delete，将结点还给内存池
	}
	T back()//获取队尾元素
	{
		if(empty())
		{
			throw std::exception("queue is empty!");
		}
		return ptail->mdata;
	}
	T front()//获取队头
	{
		if(empty())
		{
			throw std::exception("queue is empty!");
		}
		return phead->mdata;
	}
	void show()
	{
		Node<T>* pcur=phead;
		while(pcur!=NULL)
		{
			std::cout<<pcur->mdata<<" ";
			pcur=pcur->pnext;
		}
		std::cout<<std::endl;
	}
	~Queue()//循环删除每个结点，调用自己写的，即将每个结点还给内存池
	{
		Node<T>* pcur=phead;//删除每次指向的结点
		Node<T>* pnext;//往后走
		while(pcur!=NULL)
		{
			pnext=pcur->pnext;
			delete pcur;//还给内存池
			pcur=pnext;
		}
		phead=NULL;
	}
private:
	Node<T>* phead;//队头
	Node<T>* ptail;//队尾
};

int main()
{
	Queue<int> que;
	for(int i=0;i<5;i++)
	{
		que.push(i+1);
	}
	que.show();
	que.pop();
	que.show();
	auto qfront=que.front();
	auto qback=que.back();
	std::cout<<"front:"<<qfront<<std::endl;
	std::cout<<"back:"<<qback<<std::endl;
}

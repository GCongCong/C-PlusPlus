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
	void * operator new(size_t size)//���عؼ���new��ʵ���ڴ�صĿ��٣�����һ���ڴ��Ž��
	{
		if(pool==NULL)//��ʾ�����ڴ��û�����ɣ����Կ����ڴ��
		{
			pool=(Node<T>*)new char[size*Node_count];
			Node<T>* pcur=pool;
			for(pcur;pcur<pool+Node_count-1;pcur=pcur+1)//ͨ���ӷ���ָ��ƫ�ƣ����ڴ�������н��ָ����һ����㣬������
			{
				pcur->pnext=pcur+1;
			}
			pcur->pnext=NULL;//�ڴ�����һ�����ΪNULL
		}
		void* ptr=pool;
		pool=pool->pnext;
		return ptr;
	}
	void operator delete(void* ptr)//���عؼ���delete��������Ľ������ڴ��
	{
		Node<T>* q=(Node<T>*)ptr;
		q->pnext=pool;
		pool=q;
	}
private:
	T mdata;
	Node<T>* pnext;
	static Node<T>* pool;//ָ���ڴ�صĿ�ʼ
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
		phead=ptail=new Node<T>();//��ʱ�����Լ�д��New�����ڴ�ط���һ������ͷ
	}
	void push(T val)//��β���
	{
		Node<T>* pnewnode=new Node<T>(val);//�������ݣ����ڴ�ط�����
		ptail->pnext=pnewnode;
		ptail=ptail->pnext;
	}
	bool empty()
	{
		return (phead==ptail)&&(phead!=NULL);
	}
	void pop()//��ͷ����
	{
		if(empty())
		{
			return;
		}
		Node<T>* pcur=phead->pnext;
		phead->pnext=pcur->pnext;
		delete pcur;//��ʱ���õ����������ص�delete������㻹���ڴ��
	}
	T back()//��ȡ��βԪ��
	{
		if(empty())
		{
			throw std::exception("queue is empty!");
		}
		return ptail->mdata;
	}
	T front()//��ȡ��ͷ
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
	~Queue()//ѭ��ɾ��ÿ����㣬�����Լ�д�ģ�����ÿ����㻹���ڴ��
	{
		Node<T>* pcur=phead;//ɾ��ÿ��ָ��Ľ��
		Node<T>* pnext;//������
		while(pcur!=NULL)
		{
			pnext=pcur->pnext;
			delete pcur;//�����ڴ��
			pcur=pnext;
		}
		phead=NULL;
	}
private:
	Node<T>* phead;//��ͷ
	Node<T>* ptail;//��β
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

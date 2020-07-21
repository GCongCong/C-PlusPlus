//2.一个类作为另外一个类的私有变量



template<typename T>
class Clink
{
public:
	Clink()
	{
		phead=new Node();//类似于int *p=new int();
	}
	~Clink()
	{
		Node* p=phead->pnext;
		while(phead->pnext!=NULL)
		{
			phead->pnext=p->pnext;
			delete p;
			p=phead->pnext;
		}
		phead=NULL;
	}
	void insertHead(T val)//头插
	{
		Node* p=new Node(val);//申请结点
		p->pnext=phead->pnext;
		phead->pnext=p;
	}
	void insertTail(T val)//尾插
	{
		Node* p=new Node(val);
		Node* q=phead;//找尾巴
		while(q->pnext!=NULL)
		{
			q=q->pnext;
		}
		q->pnext=p;
		p->pnext=NULL;
	}
	void show()//打印
	{
		Node* p=phead->pnext;
		while(p!=NULL)
		{
			std::cout<<p->mdata<<" ";
			p=p->pnext;
		}
		std::cout<<std::endl;
	}
private:
	class Node//此时的Node为类名
	{
	public: 
		Node(T v=T())//设置零初始化默认值
		{
			mdata=v;
			pnext=NULL;
		}
		T mdata;//声明为public
		Node* pnext;
	};
	Node* phead;
};


int main()
{
	std::cout<<"-----int类型的链表-----"<<std::endl;
	Clink<int> c;
	for(int i=0;i<5;i++)
	{
		c.insertHead(i);
	}
	std::cout<<"****头插****"<<std::endl;
	c.show();
	std::cout<<"****头插****"<<std::endl;
	for(int i=0;i<5;i++)
	{
		c.insertTail(i);
	}
	std::cout<<"****尾插****"<<std::endl;
	c.show();
	std::cout<<"****尾插****"<<std::endl;

	std::cout<<"-----int类型的链表-----"<<std::endl;

    std::cout<<"-----double类型的链表-----"<<std::endl;
	Clink<double> c1;
	for(int i=0;i<5;i++)
	{
		c1.insertHead(0.1+i);
	}
	std::cout<<"****头插****"<<std::endl;
	c1.show();
	std::cout<<"****头插****"<<std::endl;
	for(int i=0;i<5;i++)
	{
		c1.insertTail(0.1+i);
	}
	std::cout<<"****尾插****"<<std::endl;
	c1.show();
	std::cout<<"****尾插****"<<std::endl;
	std::cout<<"-----double类型的链表-----"<<std::endl;
}

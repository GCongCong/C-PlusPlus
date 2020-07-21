/*2.单链表模板类*/
//1.友元关系表示


template<typename T>
class Clink;//声明模板
//结点模板类
template<typename T>
class Node//Node为模板名，Node<T>为类名
{
public: 
	Node(T v=T())//设置零初始化默认值
	{
		mdata=v;
		pnext=NULL;
	}
private: 
	T mdata;
	Node<T>* pnext;
	friend class Clink<T>;//友元关系，friend class 类名
};
//链表模板类
template<typename T>
class Clink
{
public:
	//类外实现
	Clink();
	~Clink();
	void insertHead(T val);//头插
	void insertTail(T val);//尾插
	bool empty();//清空
	void deleteHead();//删头
	void show();//打印
private:
	Node<T>* phead;
};

template<typename T>
Clink<T>::Clink()//类名::函数名，初始化
{
	phead=new Node<T>();//类似于int *p=new int();
}
template<typename T>
Clink<T>::~Clink()//删除所有结点
{
	Node<T>* p=phead->pnext;
	while(phead->pnext!=NULL)
	{
		phead->pnext=p->pnext;
		delete p;
		p=phead->pnext;
	}
	phead=NULL;
}
template<typename T>
void Clink<T>::insertHead(T val)//头插
{
	Node<T>* p=new Node<T>(val);//申请结点
	p->pnext=phead->pnext;
	phead->pnext=p;
}
template<typename T>
void Clink<T>::insertTail(T val)//尾插
{
	Node<T>* p=new Node<T>(val);
	Node<T>* q=phead;//找尾巴
	while(q->pnext!=NULL)
	{
		q=q->pnext;
	}
	q->pnext=p;
	p->pnext=NULL;
}
template<typename T>
bool Clink<T>::empty()
{
	return phead->pnext==NULL;
}
template<typename T>
void Clink<T>::deleteHead()
{
	if(empty())
	{
		return;
	}
	Node<T>*p=phead->pnext;
	phead->pnext=p->pnext;
	delete p;
}
template<typename T>
void Clink<T>::show()
{
	Node<T>* p=phead->pnext;
	while(p!=NULL)
	{
		std::cout<<p->mdata<<" ";
		p=p->pnext;
	}
	std::cout<<std::endl;
}
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
		c.deleteHead();
	}
	std::cout<<"****头删删除全部结点****"<<std::endl;
	c.show();
	std::cout<<"****头删删除全部结点****"<<std::endl;
	for(int i=0;i<5;i++)
	{
		c.insertTail(i);
	}
	std::cout<<"****尾插****"<<std::endl;
	c.show();
	std::cout<<"****尾插****"<<std::endl;
	c.deleteHead();
	std::cout<<"****头删一个结点****"<<std::endl;
	c.show();
	std::cout<<"****头删删除全部结点****"<<std::endl;
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
		c1.deleteHead();
	}
	std::cout<<"****头删删除全部结点****"<<std::endl;
	c1.show();
	std::cout<<"****头删删除全部结点****"<<std::endl;
	for(int i=0;i<5;i++)
	{
		c1.insertTail(0.1+i);
	}
	std::cout<<"****尾插****"<<std::endl;
	c1.show();
	std::cout<<"****尾插****"<<std::endl;
	c1.deleteHead();
	std::cout<<"****头删一个结点****"<<std::endl;
	c1.show();
	std::cout<<"****头删删除全部结点****"<<std::endl;
	std::cout<<"-----double类型的链表-----"<<std::endl;
}

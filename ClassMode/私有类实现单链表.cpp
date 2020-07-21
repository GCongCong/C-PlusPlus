//2.һ������Ϊ����һ�����˽�б���



template<typename T>
class Clink
{
public:
	Clink()
	{
		phead=new Node();//������int *p=new int();
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
	void insertHead(T val)//ͷ��
	{
		Node* p=new Node(val);//������
		p->pnext=phead->pnext;
		phead->pnext=p;
	}
	void insertTail(T val)//β��
	{
		Node* p=new Node(val);
		Node* q=phead;//��β��
		while(q->pnext!=NULL)
		{
			q=q->pnext;
		}
		q->pnext=p;
		p->pnext=NULL;
	}
	void show()//��ӡ
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
	class Node//��ʱ��NodeΪ����
	{
	public: 
		Node(T v=T())//�������ʼ��Ĭ��ֵ
		{
			mdata=v;
			pnext=NULL;
		}
		T mdata;//����Ϊpublic
		Node* pnext;
	};
	Node* phead;
};


int main()
{
	std::cout<<"-----int���͵�����-----"<<std::endl;
	Clink<int> c;
	for(int i=0;i<5;i++)
	{
		c.insertHead(i);
	}
	std::cout<<"****ͷ��****"<<std::endl;
	c.show();
	std::cout<<"****ͷ��****"<<std::endl;
	for(int i=0;i<5;i++)
	{
		c.insertTail(i);
	}
	std::cout<<"****β��****"<<std::endl;
	c.show();
	std::cout<<"****β��****"<<std::endl;

	std::cout<<"-----int���͵�����-----"<<std::endl;

    std::cout<<"-----double���͵�����-----"<<std::endl;
	Clink<double> c1;
	for(int i=0;i<5;i++)
	{
		c1.insertHead(0.1+i);
	}
	std::cout<<"****ͷ��****"<<std::endl;
	c1.show();
	std::cout<<"****ͷ��****"<<std::endl;
	for(int i=0;i<5;i++)
	{
		c1.insertTail(0.1+i);
	}
	std::cout<<"****β��****"<<std::endl;
	c1.show();
	std::cout<<"****β��****"<<std::endl;
	std::cout<<"-----double���͵�����-----"<<std::endl;
}

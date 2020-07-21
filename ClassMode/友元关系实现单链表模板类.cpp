/*2.������ģ����*/
//1.��Ԫ��ϵ��ʾ


template<typename T>
class Clink;//����ģ��
//���ģ����
template<typename T>
class Node//NodeΪģ������Node<T>Ϊ����
{
public: 
	Node(T v=T())//�������ʼ��Ĭ��ֵ
	{
		mdata=v;
		pnext=NULL;
	}
private: 
	T mdata;
	Node<T>* pnext;
	friend class Clink<T>;//��Ԫ��ϵ��friend class ����
};
//����ģ����
template<typename T>
class Clink
{
public:
	//����ʵ��
	Clink();
	~Clink();
	void insertHead(T val);//ͷ��
	void insertTail(T val);//β��
	bool empty();//���
	void deleteHead();//ɾͷ
	void show();//��ӡ
private:
	Node<T>* phead;
};

template<typename T>
Clink<T>::Clink()//����::����������ʼ��
{
	phead=new Node<T>();//������int *p=new int();
}
template<typename T>
Clink<T>::~Clink()//ɾ�����н��
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
void Clink<T>::insertHead(T val)//ͷ��
{
	Node<T>* p=new Node<T>(val);//������
	p->pnext=phead->pnext;
	phead->pnext=p;
}
template<typename T>
void Clink<T>::insertTail(T val)//β��
{
	Node<T>* p=new Node<T>(val);
	Node<T>* q=phead;//��β��
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
		c.deleteHead();
	}
	std::cout<<"****ͷɾɾ��ȫ�����****"<<std::endl;
	c.show();
	std::cout<<"****ͷɾɾ��ȫ�����****"<<std::endl;
	for(int i=0;i<5;i++)
	{
		c.insertTail(i);
	}
	std::cout<<"****β��****"<<std::endl;
	c.show();
	std::cout<<"****β��****"<<std::endl;
	c.deleteHead();
	std::cout<<"****ͷɾһ�����****"<<std::endl;
	c.show();
	std::cout<<"****ͷɾɾ��ȫ�����****"<<std::endl;
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
		c1.deleteHead();
	}
	std::cout<<"****ͷɾɾ��ȫ�����****"<<std::endl;
	c1.show();
	std::cout<<"****ͷɾɾ��ȫ�����****"<<std::endl;
	for(int i=0;i<5;i++)
	{
		c1.insertTail(0.1+i);
	}
	std::cout<<"****β��****"<<std::endl;
	c1.show();
	std::cout<<"****β��****"<<std::endl;
	c1.deleteHead();
	std::cout<<"****ͷɾһ�����****"<<std::endl;
	c1.show();
	std::cout<<"****ͷɾɾ��ȫ�����****"<<std::endl;
	std::cout<<"-----double���͵�����-----"<<std::endl;
}

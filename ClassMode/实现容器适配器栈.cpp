//��˳�����а�װ����װΪջ����ʱ��ջ���Ǵ��˳��������;typename�����Զ���ģ��
//˳���ģ���� 
template<typename T>
class Link
{
public:
	Link()
	{
		ptr=new T[2];
		cursize=0;
		length=2;
	}
	~Link()
	{
		delete []ptr;
		ptr=NULL;
		cursize=0;
		length=0;
	}
	void resize()
	{
		T* temp=new int[length*2]();
		memcpy(temp,ptr,sizeof(T)*length);
		delete [] ptr;
		ptr=temp;
		length*=2;
	}
	void insertTail(T val)
	{
		insertPos(cursize,val);
	}
	void insertPos(int pos,T val)
	{
		if(pos<0 || pos>cursize)
		{
			throw std::exception("Insert pos is error");
		}
		if(full())
		{
			resize();
		}
		for(int i=cursize;i>pos;i--)
		{
			ptr[i]=ptr[i-1];
		}
		ptr[pos]=val;
		cursize++;
	}
	void deleteTail()
	{
		deletePos(cursize-1);
	}
	void deletePos(int pos)
	{
		
		if(pos<0 || pos>cursize)
		{
			throw std::exception("delete pos is error");
		}
		if(empty())
		{
			throw std::exception("Link is empty");
		}
		for(int i=pos;i<cursize-1;i++)
		{
			ptr[i]=ptr[i+1];
		}
		cursize--;
	}
	T back()
	{
		if(empty())
		{
			throw std::exception("Link is empty");
		}
		return ptr[cursize-1];
	}
	void show()
	{
		for(int i=0;i<cursize;i++)
		{
			std::cout<<ptr[i]<<" " ;
		}
		std::cout<<std::endl;
	}
private:
	bool full()
	{
		return cursize==length;
	}
	bool empty()
	{
		return cursize==0;
	}
	T *ptr;//ָ��˳���
	int cursize;//��Ч���ݸ���
	int length;//�ܳ���
};

//������ 
template <typename T,
	      template<typename E> class MLink=Link>//ģ����
class Stack
{
public:
	Stack(){}
	~Stack(){}
	bool empty()
	{
		return c.empty();
	}
	void push(T val)
	{
		c.insertTail(val);
	}
	void pop()
	{
		c.deleteTail();
	}
	T top()
	{
		return c.back();
	}
private:
	MLink<T>c;//��Ա������˳���ģ�壬����Link<T>c
};
int main()
{
	Stack<int>st;
	std::cout<<"��ջ1~5"<<std::endl;
	for(int i=0;i<5;i++)
	{
		st.push(i+1);
		std::cout<<st.top()<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"��ȡջ��Ԫ��"<<std::endl;
	std::cout<<st.top()<<std::endl;
	std::cout<<"ɾ��ջ��Ԫ�غ󣬻�ȡջ��Ԫ��"<<std::endl;
	st.pop();
	std::cout<<st.top()<<std::endl;
}

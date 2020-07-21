//将顺序表进行包装，包装为栈，此时的栈就是存放顺序表的容器;typename还可以定义模板
//顺序表模板类 
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
	T *ptr;//指向顺序表
	int cursize;//有效数据个数
	int length;//总长度
};

//容器类 
template <typename T,
	      template<typename E> class MLink=Link>//模板类
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
	MLink<T>c;//成员变量是顺序表模板，类似Link<T>c
};
int main()
{
	Stack<int>st;
	std::cout<<"入栈1~5"<<std::endl;
	for(int i=0;i<5;i++)
	{
		st.push(i+1);
		std::cout<<st.top()<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"获取栈顶元素"<<std::endl;
	std::cout<<st.top()<<std::endl;
	std::cout<<"删除栈顶元素后，获取栈顶元素"<<std::endl;
	st.pop();
	std::cout<<st.top()<<std::endl;
}

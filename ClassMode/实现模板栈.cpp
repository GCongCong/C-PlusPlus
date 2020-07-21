/*5.实现模板栈,类似于数组定长，处理异常机制*/

const int Size=10;
template<typename T>
class stack
{
public:
	stack()
	{
		mtop=0;
	}
	void push(T val)
	{
		if(full())
		{
			throw std::exception("stack full!");
		}
		arr[mtop++]=val;
	}
	bool empty()
	{
		return mtop==0;
	}
	bool pop()//
	{
		if(empty())
		{
			throw std::exception("stack empty!");
		}
		mtop--;
		return true;
	}
	T top()
	{
		if(empty())
		{
			throw std::exception("top::stack empty!");
		}
		return arr[mtop-1];
	}

private:
	bool full()
	{
		return mtop==Size;
	}
	T arr[Size];
	int mtop;//栈顶，下标为数字，所以是int类型
};

int main()
{
	stack<int>st;
	try
	{
		st.top();
	}
	catch(std::exception& err)
	{
		std::cout<<err.what()<<std::endl;
	}
	st.push(10);
	std::cout<<"弹出栈顶元素:"<<std::endl;
	std::cout<<st.top()<<std::endl;
	return 0;
}

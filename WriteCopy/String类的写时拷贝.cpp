# include<iostream>

/*写时拷贝，修改时即[]深拷贝，拷贝构造，赋值浅拷贝*/
class String
{
public: 
	String(char* ptr)
	{
		mptr=new char[strlen(ptr)+1+4]();//+4是开辟引用计数的位置
		mptr+=4;//指向数据域
		strcpy_s(mptr,strlen(ptr)+1,ptr);
		getRef()=1;//此时一个指向
	}
	String(const String& rhs)
	{
		mptr=rhs.mptr;
		getRef()++;//增加
	}
	String& operator=(const String& rhs)
	{
		if(this != &rhs)
		{
			--getRef();
			if(getRef()==0)//假如A=B，那么A指向的内存块减一，如果此时减为0，需要释放此内存块
			{
				delete [] (mptr-4);//释放内存整个空间，现在mptr指向数据域，需要向前偏移
			}
			//不等于0，直接指向新的即可
			mptr=rhs.mptr;
			getRef()++;//新的计数加1
		}
		return *this;
	}
	//深拷贝,如果有多个对象指向这一块内存，那么修改的时候创建空间。如果只有一个对象指向，不用开辟内存
	char& operator[](int index)
	{
		if(getRef()>1)//多个对象，需要开辟空间
		{
			char* temp=new char[strlen(mptr)+1+4]();
			temp+=4;
			strcpy_s(temp,strlen(mptr)+1,mptr);
			--getRef();//把数据拷贝了再断开连接
			mptr=temp;//指向新开辟的内存
			getRef()=1;
		}
		return mptr[index];
	}
	//重载输出<<，写到类外
	friend std::ostream& operator <<(std::ostream& out,const String& rhs);
	~String()//引用计数为0，释放内存
	{
		--getRef();
		if(getRef()==0)
		{
			delete[] (mptr-4);
		}
		mptr=NULL;
	}
private:
	int& getRef()//获取引用计数值
	{
		return *(int*)(mptr-4);//mptr指向数据域，-4向前偏移指向引用计数域
	}
	char* mptr;

};
std::ostream& operator <<(std::ostream& out,const String& rhs)
{
	out<<rhs.mptr;
	return out;
}

int main()
{
	String str1("hello");
	String str2(str1);
	String str3(str2);
	String str4("world");
	str2[0]='a';
}

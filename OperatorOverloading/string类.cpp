/*3.string类*/
class String
{
public:
	String(char* ptr)
	{
		mptr=new char[strlen(ptr)+1]();
		strcpy_s(mptr,strlen(ptr)+1,ptr);
	}
	String(const String& rhs)
	{
		mptr=new char[strlen(rhs.mptr)+1]();
		strcpy_s(mptr,strlen(rhs.mptr)+1,rhs.mptr);
	}
	//1.重载对象+字符串
	const String operator+(char* str)
	{
		char* temp=new char[strlen(mptr)+strlen(str)+1]();
		strcpy_s(temp,strlen(mptr)+1,mptr);
		strcat(temp,str);
		String res(temp);
		delete [] temp;
		return res;
	}
	//2.重载字符串+对象，写到类外,声明友元
	friend const String operator+(char* str,String &rhs);
	//4. 重载对象+对象，左操作数为对象
	const String operator+(String &rhs)
	{
		char* temp=new char[strlen(rhs.mptr)+strlen(mptr)+1];
		strcpy_s(temp,strlen(mptr)+1,mptr);
		strcat(temp,rhs.mptr);
		String res(temp);
		delete [] temp;
		return res;
	}
	//5.重载<
	bool operator<(String &rhs)
	{
		return strcmp(mptr,rhs.mptr)<0;
	}
	//6.重载!=
	bool operator!=(String &rhs)
	{
		return strcmp(mptr,rhs.mptr)!=0;
	}
	//7.重载输出<<，写到类外
	friend std::ostream& operator <<(std::ostream& out,const String& rhs);
	//8.重载[]
	char& operator[](int index)
	{
		return mptr[index];
	}
	~String()
	{
		delete[] mptr;
		mptr=NULL;
	}
private:
	char* mptr;
};
//2.
const String operator+(char* str,String &rhs)
{
	char* temp=new char[strlen(rhs.mptr)+strlen(str)+1]();
	strcpy_s(temp,strlen(str)+1,str);
	strcat(temp,rhs.mptr);
	String res(temp);
	delete [] temp;
	return res;
}
//7.
std::ostream& operator <<(std::ostream& out,const String& rhs)
{
	out<<rhs.mptr;
	return out;
}
int main()
{
	String str1("hello");
	String str2=str1+"world";
	String str3="hi"+str1;
	String str4=str1+str2;

	if(str1<str2)
	{
		std::cout<<str1<<std::endl;
	}
	if(str3!=str4)
	{
		std::cout<<str4<<std::endl;
	}
	std::cout<<str1[0]<<std::endl;
}

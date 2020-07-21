template <typename T1,typename T2>
class Sum
{
public:
	Sum(T1 a,T2 b):ma(a),mb(b)
	{}
	T1 add()//普通函数
	{
		std::cout<<"Sum(T1,T2)"<<std::endl;
		return ma+mb;
	}
	//实现字符串相加函数模板特例化，需要先有模板
	template <typename S1,typename S2>
	S1 add()
	{
		std::cout<<"add<T>"<<std::endl;
		return ma+mb;
	}
	//特例化
	template<>
	char* add<char*,char*>()
	{
		std::cout<<"Sum<>"<<std::endl;
		char temp[100]={0};
		strcpy_s(temp,strlen(ma)+1,ma);
		strcat(temp,mb);
		return temp;//返回局部变量，结果会丢失
	}
private:
	T1 ma;
	T2 mb;
};

//针对字符串相加，进行类全特化
/*template <>
class Sum<char*,char*>
{
public:
	Sum(char* a,char* b):ma(a),mb(b)
	{}
	char* add()
	{
		std::cout<<"Sum(char*,char*)"<<std::endl;
		char temp[100]={0};
		strcpy_s(temp,strlen(ma)+1,ma);
		strcat(temp,mb);
		return temp;//返回局部变量，结果会丢失
	}
private:
	char* ma;
	char* mb;
};*/
//对一种类型进行处理，如指针，写为偏特化，只能写为类
template <typename T1,typename T2>
class Sum<T1*,T2*>
{
public:
	Sum(T1* a,T2* b):ma(a),mb(b)
	{}
	T1 add()//普通函数
	{
		std::cout<<"Sum(T1*,T2*)"<<std::endl;
		return (*ma)+(*mb);
	}
private:
	T1* ma;
	T2* mb;
};
int main()
{
	Sum<int,int> s1(10,20);
	s1.add();
	//Sum<char*,char*> s2("a","b");
	//s2.add();
	//Sum<char*,char*> s3("c","b");
	//s3.add<char*,char*>();
	int a=1;
	int b=2;
	Sum<int*,int*> s4(&a,&b);
	s4.add();

}

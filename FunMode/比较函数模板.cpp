# include<iostream>
# include<cstring>
/*3.比较大小*/
template <typename T>//函数模板
bool Compare( T a, T b)
{
	std::cout<<"Compare(T,T);"<<std::endl;
	return a>b;
}

//不能支持char* 类型字符串进行函数比较，所以进行函数模板全特化
template<>//函数模板全特化
bool Compare<char*>( char* a,   char*   b)
{
	std::cout<<"Compare<char*>;"<<std::endl;
	return strcmp(a,b)>0;
}

//普通函数
bool Compare(char* const a,  char* const b)
{
	std::cout<<"Compare(char*,char*);"<<std::endl;
	return strcmp(a,b)>0;
}
int main()
{

	Compare(1,2);//模板的实参推演
	Compare("a","b");//按照普通函数>特例化>函数模板
	std::cout<<typeid("a").name()<<std::endl;
	Compare<char*>("a","b");//调用char*类型的模板函数
	
}

# include<iostream>
# include<cstring>
/*3.�Ƚϴ�С*/
template <typename T>//����ģ��
bool Compare( T a, T b)
{
	std::cout<<"Compare(T,T);"<<std::endl;
	return a>b;
}

//����֧��char* �����ַ������к����Ƚϣ����Խ��к���ģ��ȫ�ػ�
template<>//����ģ��ȫ�ػ�
bool Compare<char*>( char* a,   char*   b)
{
	std::cout<<"Compare<char*>;"<<std::endl;
	return strcmp(a,b)>0;
}

//��ͨ����
bool Compare(char* const a,  char* const b)
{
	std::cout<<"Compare(char*,char*);"<<std::endl;
	return strcmp(a,b)>0;
}
int main()
{

	Compare(1,2);//ģ���ʵ������
	Compare("a","b");//������ͨ����>������>����ģ��
	std::cout<<typeid("a").name()<<std::endl;
	Compare<char*>("a","b");//����char*���͵�ģ�庯��
	
}

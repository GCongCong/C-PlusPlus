/*1.���������*/
template <typename T1,typename T2>
T1 TwoSum(T1 num1,T2 num2)
{
	return num1+num2;
}
/*2.���������--ʹ�ú���ģ��Ĭ��ֵ
vs2012��֧��c++11��׼�Ŀ��ԶԺ���ģ��ʹ��Ĭ�ϲ����Ĺ涨������������ģ����ʹ��Ĭ��ģ�����*/ 
template <typename R=int,typename T1,typename T2,typename T3>
R ThrSum(T1 num1,T2 num2,T3 num3)
{
	return num1+num2+num3;
}
int main()
{
	std::cout<<TwoSum<int,int>(1,2)<<std::endl;
	std::cout<<TwoSum<int,double>(1,2.2)<<std::endl;
	std::cout<<ThrSum<int,int,int>(1,2,3)<<std::endl;
	
}

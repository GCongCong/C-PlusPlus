/*1.两个数求和*/
template <typename T1,typename T2>
T1 TwoSum(T1 num1,T2 num2)
{
	return num1+num2;
}
/*2.三个数求和--使用函数模板默认值
vs2012不支持c++11标准的可以对函数模板使用默认参数的规定，仅允许在类模板上使用默认模板参数*/ 
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

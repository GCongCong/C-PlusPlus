int main()
{
	int a[]={3,2,1,5,4};
	int len=sizeof(a)/sizeof(a[0]);
	std::vector<int> vec(a,a+len);
	std::copy(vec.begin(),vec.end(),std::ostream_iterator<int>(std::cout,"+"));
	std::cout<<std::endl;

}


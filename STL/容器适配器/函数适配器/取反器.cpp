# include<iostream>
# include<deque>
# include<vector>
# include<list>
# include<algorithm>
# include<iterator>
# include<set>
# include<map>
# include<string>
#include <functional>
int main()
{
	int arr[]={5,3,23,54,7,9};
	int len=sizeof(arr)/sizeof(arr[0]);
	std::vector<int>vec(arr,arr+len);
	std::vector<int>::iterator fit=std::find_if(vec.begin(),vec.end(),std::bind2nd(std::not2(std::greater<int>()),10));
	if(fit!=vec.end())
	{
		std::cout<<"vec find : "<<*fit<<std::endl;
	}
	else
	{
		std::cout<<"vec no exist"<<std::endl;
	}
}



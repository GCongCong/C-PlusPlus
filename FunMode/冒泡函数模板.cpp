# include<iostream>
# include<cstring>
//4.√∞≈›≈≈–Ú
template <typename T,int len>
void Sort(T val[])
{
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j<len-i-2;j++)
		{
			T temp;
			if(val[j]>val[j+1])//¡Ω¡ΩΩªªª
			{
				temp=val[j];
				val[j]=val[j+1];
				val[j+1]=temp;
			}
		}
	}
}
template<typename T,int len>
void show(T val[])
{
	for(int i=0;i<len;i++)
	{
		std::cout<<val[i]<<" ";
	}
}
int main()
{

	
	int arr[]={1,3,2,5,9};
	show<int,5>(arr);
	std::cout<<std::endl;
	Sort<int,5>(arr);
	show<int,5>(arr);
	return 0;
}

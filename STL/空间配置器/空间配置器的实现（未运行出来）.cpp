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

//空间配置器
namespace CC
{
	//1.开辟内存函数
	template<typename T>
	T* _allocate(size_t _count,T*)
	{
		std::set_new_handler(0);//处理内存申请不足函数，传入0，代表没有处理函数
		T* ptmp=(T*)::operator new(_count* sizeof(T));//调用底层operator进行内存开辟,_count表示开辟个数
		if(ptmp==NULL)
		{
			std::cout<<"out of memory"<<std::endl;
			std::exit(0);
		}
		return ptmp;//返回开辟的内存地址
	}
	//2.构造函数
	template<typename T>
	void _construct(T* ptr)
	{
		new (ptr) T();//new重定位，在ptr指向的内存上调用构造函数，初始化对象
	}
	//3.析构函数
	template<typename T>
	void _destroy(T* ptr)
	{
		ptr->~T();
	}
	//4.释放内存
	template<typename T>
	void _deallocate(T* ptr)
	{
		::operator delete(ptr);
	}
	//空间配置器类
	template <typename _Ty>
	class Allocator
	{
	public:
		//重定义一些参数
		typedef Allocator<_Ty> _Myty;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef _Ty value_type;
		typedef _Ty* pointer;
		typedef const _Ty* const_pinter;
		typedef _Ty& reference;
		typedef const _Ty& const_reference;
		template<typename E>
		struct rebind
		{
			typedef Allocator<E> other;
		};
		//开辟
		pointer allocate(size_t size)
		{
			return CC::_allocate(size,(pointer)0);
		}
		//构造
		void construct(pointer ptr)
		{
			CC::_construct(ptr);
		}
		//析构
		void destroy(pointer ptr)
		{
			CC::_destroy(ptr);
		}
		//释放
		void deallocate(pointer ptr,size_t count)
		{
			CC::_deallocate(ptr);
		}
	};
}
int main()
{
	int arr[]={1,3,4,5,2};
	int len=sizeof(arr)/sizeof(arr[0]);
	std::vector<int,CC::Allocator<int>> vec(arr,arr+len);
	typedef std::vector<int,CC::Allocator<int>> vecty;
	vecty::iterator it=vec.begin();
	while(it!=vec.end())
	{
		std::cout<<*it<<" ";
		it++;
	}
	std::cout<<std::endl;
}

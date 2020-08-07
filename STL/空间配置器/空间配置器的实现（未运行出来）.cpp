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

//�ռ�������
namespace CC
{
	//1.�����ڴ溯��
	template<typename T>
	T* _allocate(size_t _count,T*)
	{
		std::set_new_handler(0);//�����ڴ����벻�㺯��������0������û�д�����
		T* ptmp=(T*)::operator new(_count* sizeof(T));//���õײ�operator�����ڴ濪��,_count��ʾ���ٸ���
		if(ptmp==NULL)
		{
			std::cout<<"out of memory"<<std::endl;
			std::exit(0);
		}
		return ptmp;//���ؿ��ٵ��ڴ��ַ
	}
	//2.���캯��
	template<typename T>
	void _construct(T* ptr)
	{
		new (ptr) T();//new�ض�λ����ptrָ����ڴ��ϵ��ù��캯������ʼ������
	}
	//3.��������
	template<typename T>
	void _destroy(T* ptr)
	{
		ptr->~T();
	}
	//4.�ͷ��ڴ�
	template<typename T>
	void _deallocate(T* ptr)
	{
		::operator delete(ptr);
	}
	//�ռ���������
	template <typename _Ty>
	class Allocator
	{
	public:
		//�ض���һЩ����
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
		//����
		pointer allocate(size_t size)
		{
			return CC::_allocate(size,(pointer)0);
		}
		//����
		void construct(pointer ptr)
		{
			CC::_construct(ptr);
		}
		//����
		void destroy(pointer ptr)
		{
			CC::_destroy(ptr);
		}
		//�ͷ�
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

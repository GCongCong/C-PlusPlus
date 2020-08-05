# include<iostream>
# include<vector>

template <typename T>
void show( std::vector<T>& vec)
{
	std::vector<T>::iterator it=vec.begin();
	while(it!=vec.end())
	{
		std::cout<<*it<<" ";
		it++;
	}
		std::cout<<std::endl;
}
int main()
{
	std::vector<int> ivec;//�޲ι���
	std::vector<double> dvec(10);//һ��int�����Ĺ���
	std::vector<char> cvec(10,'c');//����int�����Ĺ���
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	int len=sizeof(a)/sizeof(a[0]);
	std::vector<int> vec(a,a+len);//ͨ�����������乹��
	//1.�����ӡ�ַ�������
	for(int i=0;i< cvec.size();i++)
	{
		std::cout<<cvec[i]<<" ";
	}
	std::cout<<std::endl;
	//2.��������ӡ���͵�����
	show<int>(vec);
	//3.β��10
	vec.push_back(10);
	std::cout<<"β��10"<<std::endl;
	show<int>(vec);
	//4.������ָ����ʼλ�ã���vec��Ԫ�ز���2���±�
	std::vector<int>::iterator it=vec.begin();
	vec.insert(it+2,a,a+5);
	show<int>(vec);
	//5.��0���±����2��100
	vec.insert(it,2,100);//������󣬵�����ָ���λ�ñ��ˣ�������ʧЧ,��������ʹ��begin()��ʶλ��
	show<int>(vec);
	//6.ɾ��ǰ0~9֮���Ԫ��Ԫ��
	vec.erase(vec.begin(),vec.begin()+10);//ɾ��0~9
	show<int>(vec);
	//5.ɾ����2��Ԫ��
	vec.erase(vec.begin()+2);
	show<int>(vec);
	//6.ɾ��β��Ԫ��
	vec.pop_back();
	show<int>(vec);
	//7.���ݣ�����ռ䣬����ʼ��Ϊ0
	std::cout<<"ԭ����С��"<<vec.size()<<std::endl;
	vec.resize(20);//���ݵ�20����С
	std::cout<<"���ڴ�С��"<<vec.size()<<std::endl;
	show<int>(vec);
	//8.Ԥ���ռ䣬���þͲ���ʹ�ã�ԭ��С����
	std::cout<<"ԭ����С��"<<vec.size()<<std::endl;
	vec.reserve(40);//Ԥ��40����С
	std::cout<<"���ڴ�С��"<<vec.size()<<std::endl;
	show<int>(vec);
	//9.���
	vec.clear();
	show<int>(vec);
}

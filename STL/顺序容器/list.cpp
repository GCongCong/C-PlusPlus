# include<iostream>
# include<list>
template <typename T>
void show( std::list<T>& vec)
{
	std::list<T>::iterator it=vec.begin();
	while(it!=vec.end())
	{
		std::cout<<*it<<" ";
		it++;
	}
		std::cout<<std::endl;
}
int main()
{
	std::list<int> ilis;//�޲ι���
	std::list<double> dlis(10);//һ��int�����Ĺ���
	std::list<char> clis(10,'c');//����int�����Ĺ���
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	int len=sizeof(a)/sizeof(a[0]);
	std::list<int> lis(a,a+len);//ͨ�����������乹��
	//2.��������ӡ���͵�����
	show<int>(lis);
	//3.β��10
	lis.push_back(10);
	std::cout<<"β��10"<<std::endl;
	show<int>(lis);
	//ͷ��200
	lis.push_front(200);
	std::cout<<"β��200"<<std::endl;
	show<int>(lis);
	//4.������ָ����ʼλ�ã�������0~5��Ԫ�ز���0���±�
	std::list<int>::iterator it=lis.begin();//֧��˫������������Բ���it+i��ֻ��it++
	lis.insert(it,a,a+5);
	show<int>(lis);
	//5.��0���±����2��100
	lis.insert(lis.begin(),2,100);//������󣬵�����ָ���λ�ñ��ˣ�������ʧЧ,��������ʹ��begin()��ʶλ��
	show<int>(lis);
	//5.ɾ����2��Ԫ��
	lis.erase(lis.begin());
	show<int>(lis);
	//6.ɾ��β��Ԫ��
	lis.pop_back();
	show<int>(lis);
	//ɾ��ͷ��Ԫ��
	lis.pop_front();
	show<int>(lis);
	//7.���ݣ�����ռ䣬����ʼ��Ϊ0
	std::cout<<"ԭ����С��"<<lis.size()<<std::endl;
	lis.resize(20);//���ݵ�20����С
	std::cout<<"���ڴ�С��"<<lis.size()<<std::endl;
	show<int>(lis);
	//6.ɾ��ǰ��ʼ~��β֮���Ԫ��
	lis.erase(lis.begin(),lis.end());//ɾ��0~3
	show<int>(lis);
}

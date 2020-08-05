# include<iostream>
# include<deque>
template <typename T>
void show( std::deque<T>& deq)
{
	std::deque<T>::iterator it=deq.begin();
	while(it!=deq.end())
	{
		std::cout<<*it<<" ";
		it++;
	}
		std::cout<<std::endl;
}
int main()
{
	std::deque<int> ideq;//�޲ι���
	std::deque<double> ddeq(10);//һ��int�����Ĺ���
	std::deque<char> cdeq(10,'c');//����int�����Ĺ���
	int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	int len=sizeof(a)/sizeof(a[0]);
	std::deque<int> deq(a,a+len);//ͨ�����������乹��
	//1.�����ӡ�ַ�������
	for(int i=0;i< cdeq.size();i++)
	{
		std::cout<<cdeq[i]<<" ";
	}
	std::cout<<std::endl;
	//2.��������ӡ��������
	show<int>(deq);
	//3.β��10
	deq.push_back(10);
	std::cout<<"β��10"<<std::endl;
	show<int>(deq);
	//ͷ��200
	deq.push_front(200);
	std::cout<<"ͷ��200"<<std::endl;
	show<int>(deq);
	//4.������ָ����ʼλ�ã��������Ԫ�ز���2���±�
	std::deque<int>::iterator it=deq.begin();//������ɺ�ͻ�ʧЧ
	deq.insert(it+2,a,a+5);
	show<int>(deq);
	//5.��0���±����2��100
	std::deque<int>::iterator it1=deq.begin();
	deq.insert(it1,2,100);//it�������Ѿ�ʧЧ�ˣ��������¶��������
	show<int>(deq);
	//6.ɾ��ǰ0~9֮���Ԫ��Ԫ��
	deq.erase(deq.begin(),deq.begin()+10);//ɾ��0~9
	show<int>(deq);
	//5.ɾ����2��Ԫ��
	deq.erase(deq.begin()+2);
	show<int>(deq);
	//6.ɾ��β��Ԫ��
	deq.pop_back();
	show<int>(deq);
	//ɾ��ͷ��Ԫ��
	deq.pop_front();
	show<int>(deq);
	//7.���ݣ�����ռ䣬����ʼ��Ϊ0
	std::cout<<"ԭ����С��"<<deq.size()<<std::endl;
	deq.resize(20);//���ݵ�20����С
	std::cout<<"���ڴ�С��"<<deq.size()<<std::endl;
	show<int>(deq);
	//9.���
	deq.clear();
	show<int>(deq);
}

# include<iostream>
# include<deque>
# include<vector>
# include<list>
# include<algorithm>
# include<iterator>
# include<set>
# include<map>

template<typename Container>
void show(Container& con)
{
	typename Container::iterator it=con.begin();//iteratorΪ�������ƣ������������ͣ������������֪��
	for(;it!=con.end();it++)
	{
		std::cout <<it->first << "-" << it->second << " ";
	}
	std::cout<<std::endl;
}
int main()
{
	std::map<int,int> mymap;//�޲ι���
	//1.����pair����
	std::pair<int,int>p1(1,1);//pair����
	mymap.insert(p1);
	show(mymap);
	//2.���ɶ������
	std::map<int,int>::value_type p2(8,1);//������ʽpair����
	mymap.insert(p2);
	show(mymap);
	//3.ͨ����ֵ����
	mymap[9]=100;
	mymap[2]=6;
	mymap[3]=4;
	mymap[4]=5;
	mymap[2]=1;//��֮ǰ�����key��Ӧ��ֵvalue���棬����������2-1��������2-6����Ϊ������keyֵ�ظ�
	show(mymap);
	//4.ͨ��keyֵ��ӡ��
	std::map<int,int>::iterator it=mymap.begin();
	while(it!=mymap.end())
	{
		std::cout<<it->first<<"---"<<it->second<<" ";
		it++;
	}
	std::cout<<std::endl;
	//5.����Ԫ��1
	std::map<int,int>::iterator fit=mymap.find(1);
	if(fit!=mymap.end())
	{
		std::cout<<fit->first<<"-"<<fit->second<<std::endl;
	}
	else
	{
		std::cout<<"no"<<std::endl;
	}
	//6.ɾ����2��Ԫ�أ�
	std::map<int,int>::iterator it2=mymap.begin();//ָ��ʼ
	mymap.erase(++it2);
	show(mymap);
	//7.ɾ����ֵ1��Ӧ��ֵ
	mymap.erase(1);
	show(mymap);
	//8.ɾ��0~3�����Ԫ��,��0��1��2�±��
	std::map<int,int>::iterator it1=mymap.begin();
	++it1;++it1;++it1;
    mymap.erase(mymap.begin(),it1);
	show(mymap);
}


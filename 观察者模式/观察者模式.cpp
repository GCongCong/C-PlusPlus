# include<iostream>
# include<deque>
# include<vector>
# include<list>
# include<algorithm>
# include<iterator>
# include<set>
# include<map>
# include<string>
//�۲���ģʽ

class Listen//�����߳�����
{
public:
	Listen( std::string n)
		:name(n)
	{}
	virtual void Deal(int message)=0;
protected:
	 std:: string name;
};
class Listen1:public Listen//������1,��1��2�¼�����Ȥ
{
public:
	Listen1( std::string n)
		:Listen(n)
	{}
	void Deal(int message)//���Լ�����Ȥ���¼����д���
	{
		switch(message)
		{
		case 1:
			std::cout<<"Listen1 Deal message 1 !"<<std::endl;
			break;
		case 2:
			std::cout<<"Listen1 Deal message 1 !"<<std::endl;
			break;
		default:
			std::cout<<"Listen1 not intersting this message!"<<std::endl;
			break;
		}
	}
};
class Listen2:public Listen//������2,��2��3�¼�����Ȥ
{
public:
	Listen2( std::string n)
		:Listen(n)
	{}
	void Deal(int message)//���Լ�����Ȥ���¼����д���
	{
		switch(message)
		{
		case 2:
			std::cout<<"Listen2 Deal message 2 !"<<std::endl;
			break;
		case 3:
			std::cout<<"Listen2 Deal message 3 !"<<std::endl;
			break;
		default:
			std::cout<<"Listen2 not intersting this message!"<<std::endl;
			break;
		}
	}
};
class Listen3:public Listen//������3,��1��3�¼�����Ȥ
{
public:
	Listen3( std::string n)
		:Listen(n)
	{}
	void Deal(int message)//���Լ�����Ȥ���¼����д���
	{
		switch(message)
		{
		case 1:
			std::cout<<"Listen3 Deal message 1 !"<<std::endl;
			break;
		case 3:
			std::cout<<"Listen3 Deal message 3 !"<<std::endl;
			break;
		default:
			std::cout<<"Listen3 not intersting this message!"<<std::endl;
			break;
		}
	}
};

class Observe
{
public:
	typedef std::map<int,std::vector< Listen*>> mmap;//�����ض���
	typedef std::vector< Listen*> myvec;
	void registerM(int message, Listen* listen)//�������߸���Ȥ���¼�ע��
	{
		//1.�ȿ��¼��Ƿ����,ʹ�ò��Һ���
		mmap::iterator it=mymap.find(message);
		if(it!=mymap.end())
		{
			it->second.push_back(listen);//���ڣ����������߷��뼯�ϣ�second��vector
		}
		else//�����ڣ������Ϸ���map�У�ʹ��map[��ֵ]=���ϲ��뼴��
		{
			myvec vec;
			vec.push_back(listen);
			mymap[message]=vec;
		}
	}
	void notify(int message)//�¼�������֪ͨ������
	{
		//1.�������ϣ������Ƿ��жԴ��¼�����Ȥ�ļ�����
		mmap::iterator it=mymap.find(message);//����
		if(it!=mymap.end())//�жԴ��¼�����Ȥ�ļ����ߣ�ѭ������֪ͨ�����䴦��
		{
			myvec::iterator vit=it->second.begin();//��������ʼ�㿪ʼ
			while(vit!=it->second.end())
			{
				(*vit)->Deal(message);//�����б��������ָ�룬�����õõ�������ָ�룬���ô����������д���
				vit++;
			}
		}
		else//û�м����߶Դ��¼�����Ȥ
		{
			std::cout<<"no listen intersting "<<message<<"message"<<std::endl;
		}
	}
private:
	//���¼�-�����߼��Ϸ���map��,������vector�洢���洢�����߳�����ָ�룬���Է�����������ߣ�����ָ��ָ�����������
	std::map<int,std::vector< Listen*>> mymap;
};
int main()
{
	Listen1 L1("listen1");//const char[8]
	Listen2 L2("listen2");
	Listen3 L3("listen3");
	Observe ob;//����۲���
	//ע������߸���Ȥ���¼�
	ob.registerM(1,&L1);
	ob.registerM(2,&L1);
	ob.registerM(2,&L2);
	ob.registerM(3,&L2);
	ob.registerM(1,&L3);
	ob.registerM(3,&L3);
	std::cout<<"--------1���¼�����-----------"<<std::endl;
	ob.notify(1);//1���¼�������
	std::cout<<"--------3���¼�����-----------"<<std::endl;
	ob.notify(3);//3���¼�������
	std::cout<<"--------4���¼�����-----------"<<std::endl;
	ob.notify(4);

}


//����ΨһУ���ĵ���ģʽ
class Reactor
{
public:
	static Reactor* getReactor()//����Ψһ�Ķ���
	{
		return reactor;
	}
	static void show()//��ӡ������Ϣ
	{
		std::cout<<"-----ΨһУ����Ϣ--"<<std::endl;
		std::cout<<"name �� "<<reactor->name<<std::endl;
		std::cout<<"age  ��"<<reactor->age<<std::endl;
		std::cout<<"sex  ��"<<reactor->sex<<std::endl;
		std::cout<<"-------------------"<<std::endl;
	}
private:
	Reactor(char* n,int a,bool s)//���캯��
	{
		name=new char[strlen(n)+1]();
		strcpy_s(name,strlen(n)+1,n);
		age=a;
		sex=s;
		std::cout<<"Reactor finish"<<std::endl;
	}
	Reactor(const Reactor&);//�������캯��
	char* name;
	int age;
	bool sex;
	static Reactor* reactor;//ָ��Ψһ�Ķ���
};
Reactor* Reactor::reactor=new Reactor("cc",21,false);//����ģʽ����ǰ����Ψһ�Ķ���

int main()
{
	Reactor* r1=Reactor::getReactor();
	Reactor* r2=Reactor::getReactor();
	Reactor::show();//��ӡΨһ�������Ϣ
	std::cout<<"r1"<<r1<<std::endl;
	std::cout<<"r2"<<r2<<std::endl;
}

//3. 饿汉模式--线程安全
class HunSingleTon
{
public:
	static HunSingleTon* getIntance()//唯一的公有接口，返回已经生成好的唯一的对象
	{
		return Hun;//返回唯一的对象
	}

private:
	HunSingleTon()//私有构造
	{
		std::cout<<"create Hun object"<<std::endl;
	}
	HunSingleTon(const HunSingleTon&);//私有拷贝构造
	static HunSingleTon* Hun;//静态成员变量
};
HunSingleTon* HunSingleTon::Hun=new HunSingleTon();//生成唯一的对象
int main()
{

	HunSingleTon* Hun1=HunSingleTon ::getIntance();
	HunSingleTon* Hun2=HunSingleTon ::getIntance();
	
}

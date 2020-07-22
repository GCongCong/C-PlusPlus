# include<iostream>

/*дʱ�������޸�ʱ��[]������������죬��ֵǳ����*/
class String
{
public: 
	String(char* ptr)
	{
		mptr=new char[strlen(ptr)+1+4]();//+4�ǿ������ü�����λ��
		mptr+=4;//ָ��������
		strcpy_s(mptr,strlen(ptr)+1,ptr);
		getRef()=1;//��ʱһ��ָ��
	}
	String(const String& rhs)
	{
		mptr=rhs.mptr;
		getRef()++;//����
	}
	String& operator=(const String& rhs)
	{
		if(this != &rhs)
		{
			--getRef();
			if(getRef()==0)//����A=B����ôAָ����ڴ���һ�������ʱ��Ϊ0����Ҫ�ͷŴ��ڴ��
			{
				delete [] (mptr-4);//�ͷ��ڴ������ռ䣬����mptrָ����������Ҫ��ǰƫ��
			}
			//������0��ֱ��ָ���µļ���
			mptr=rhs.mptr;
			getRef()++;//�µļ�����1
		}
		return *this;
	}
	//���,����ж������ָ����һ���ڴ棬��ô�޸ĵ�ʱ�򴴽��ռ䡣���ֻ��һ������ָ�򣬲��ÿ����ڴ�
	char& operator[](int index)
	{
		if(getRef()>1)//���������Ҫ���ٿռ�
		{
			char* temp=new char[strlen(mptr)+1+4]();
			temp+=4;
			strcpy_s(temp,strlen(mptr)+1,mptr);
			--getRef();//�����ݿ������ٶϿ�����
			mptr=temp;//ָ���¿��ٵ��ڴ�
			getRef()=1;
		}
		return mptr[index];
	}
	//�������<<��д������
	friend std::ostream& operator <<(std::ostream& out,const String& rhs);
	~String()//���ü���Ϊ0���ͷ��ڴ�
	{
		--getRef();
		if(getRef()==0)
		{
			delete[] (mptr-4);
		}
		mptr=NULL;
	}
private:
	int& getRef()//��ȡ���ü���ֵ
	{
		return *(int*)(mptr-4);//mptrָ��������-4��ǰƫ��ָ�����ü�����
	}
	char* mptr;

};
std::ostream& operator <<(std::ostream& out,const String& rhs)
{
	out<<rhs.mptr;
	return out;
}

int main()
{
	String str1("hello");
	String str2(str1);
	String str3(str2);
	String str4("world");
	str2[0]='a';
}

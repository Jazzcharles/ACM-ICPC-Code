#include<bits/stdc++.h>
#include<windows.h>
#define CCriticalSection CRITICAL_SECTION 
using namespace std;

//version 1
class Singleton0{
	public:
		static Singleton0* getInstance(){
			if(instance == NULL)
				instance = new Singleton0();
			return instance;
		}
	private:
		Singleton0(){};
		static Singleton0 *instance;
};

//
class Singleton2{
	public:
		static Singleton2* getInstance(){
			if(instance == NULL)
				instance = new Singleton2();
			return instance;
		}
	private:
		Singleton2(){};
		static Singleton2 *instance;
		class Garbo{
			~Garbo(){
				if(Singleton2::getInstance())
					delete Singleton2::instance;
			}
		};
		static Garbo garbo;
};

//version 2
class CSingleton
{
	private:
		CSingleton()   //���캯����˽�е�
		{
		}
		CSingleton(const CSingleton &);
		CSingleton & operator = (const CSingleton &);
	public:
		static CSingleton & GetInstance()
		{
			static CSingleton instance;   //�ֲ���̬����
			return instance;
		}
};



class Lock
{
private:       
	CCriticalSection m_cs;
public:
	Lock(CCriticalSection  cs) : m_cs(cs)
	{
		//m_cs.Lock();
		EnterCriticalSection(&m_cs);
	}
	~Lock()
	{
		//m_cs.Unlock();
		LeaveCriticalSection(&m_cs);
	}
};

class Singleton
{
private:
	Singleton();
	Singleton(const Singleton &);
	Singleton& operator = (const Singleton &);

public:
	static Singleton *Instantialize();
	static Singleton *pInstance;
	static CCriticalSection cs;
};

Singleton* Singleton::pInstance = 0;

Singleton* Singleton::Instantialize()
{
	if(pInstance == NULL)
	{   //double check
		Lock lock(cs);           //��lockʵ���̰߳�ȫ������Դ�����࣬ʵ���쳣��ȫ
		//ʹ����Դ�����࣬���׳��쳣��ʱ����Դ���������ᱻ�������������Ƿ�������������Ϊ�쳣�׳��������������
		if(pInstance == NULL)
		{
			pInstance = new Singleton();
		}
	}
	return pInstance;
}

int main(){
//	Singleton *s1 = Singleton::getInstance();
//	Singleton *s2 = Singleton::getInstance();
//	if(s1 == s2) cout<<"Equals"<<endl;
	//CSingleton cs = CSingleton::GetInstance(); 
	
	return 0;
}

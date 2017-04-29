#include<bits/stdc++.h>
using namespace std;

class Mystring{
	public:
		//Mystring();
		Mystring(char *pdata = NULL){m_pdata = pdata;};
		Mystring(const Mystring & ms){
			m_pdata = new char[strlen(ms.m_pdata)+1];
			strcpy(m_pdata,ms.m_pdata);
		};
		Mystring & operator = (const Mystring &ms); 
		~Mystring(void){ delete []m_pdata; };
		void show(){
			char *p = m_pdata ;
			while(*p!='\0') cout<<*p++;
			cout<<endl;
		}
	private:
		char *m_pdata;
};


Mystring & Mystring::operator = (const Mystring &ms){
	if(this != &ms){
		Mystring temp(ms);
		
		char *pt = temp.m_pdata;
		temp.m_pdata = m_pdata;
		m_pdata = pt;	
	}
	cout<<123<<endl;
	return *this;
}


int main(){
	char *s = new char[10];
	cin>>s;
	Mystring a(s);
	a.show();
	//cout<<123123<<endl;
	Mystring b;
	b = a;
	//cout<<555<<endl;
	b.show();
	
	return 0;
} 

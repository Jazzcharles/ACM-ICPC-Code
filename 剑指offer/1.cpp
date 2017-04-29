#include<bits/stdc++.h>
using namespace std;
class A{
	public:
		A(char *p = NULL);
		A(const A & str);
		~A(void);
		A& operator  = (const A& str){
			if(this == &str) return *this;
			delete []pdata;
			pdata = NULL;
			pdata = new char(strlen(str.pdata)+1);
			strcpy(pdata,str.pdata);
			return *this;
		};
	private:
		char *pdata; 
} ;
int main(){
	
	
	
	
	return 0;
} 

#include<iostream>
using namespace std;

int main(){
	int d1,d2,h1,h2,m1,m2,s1,s2;
	while(cin>>d1>>h1>>m1>>s1)
	{
		cin>>d2>>h2>>m2>>s2;
		s2+=s1;
		if(s2>=60) {
			s2-=60;m2++;
		}
		m2+=m1;
		if(m2>=60){
			m2-=60;h2++;
		}
		h2+=h1;
		if(h2>=24){
			d2++;h2-=24;
		}
		d2+=d1;
		cout<<d2<<' '<<h2<<' '<<m2<<' '<<s2<<endl;
	}
	
	return 0;
} 

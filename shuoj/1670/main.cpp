#include<iostream>
using namespace std;
int main()
{
	int R,v1,v2;
	while(cin>>R>>v1>>v2)
	{
		double t1=R*3.1415926/v2;
		double t2=R*1.0/v1;
		if(t2<t1)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}

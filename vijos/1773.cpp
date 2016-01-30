#include<iostream>
using namespace std;
long long a,b;
int main()
{
    cin>>a;
    for(int i=a-1;i>0;i--)
      if(a%i==0){
	  	cout<<i;break;
	  }
	return 0;
}

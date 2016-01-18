#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int a,b,c,cnt=0;
	char ch1,ch2;
	while(scanf("%d%c%d%c%d",&a,&ch1,&b,&ch2,&c)){
		if(ch1=='+' && a+b==c)
		  cnt++;
		else if(ch1=='-' && a-b==c)
		  cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}

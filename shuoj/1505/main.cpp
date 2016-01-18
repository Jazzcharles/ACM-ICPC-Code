#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	string a;
	getline(cin,a);
	int len=a.length();
	stack<double> s;
	int temp=0,index=1;
	for(int i=len-1;i>=0;i--){
		if(isdigit(a[i])){
			temp=temp+(a[i]-'0')*index;
			index*=10;
		}
		else if(a[i]=='.'){
			temp/=index;
			index=1;
		}
		else if(a[i]==' '){
			s.push(temp);
			temp=0;index=1;
			continue;
		}
		else if(a[i]=='+' ||a[i]=='-' || a[i]=='*' || a[i]=='/'){
			double x=s.top();s.pop();
			double y=s.top();s.pop();
			if(a[i]=='+'){
				x+=y;s.push(x);
			}
			if(a[i]=='-'){
				x-=y;s.push(x);
			}
			if(a[i]=='*'){
				x*=y;s.push(x);
			}
			if(a[i]=='/'){
				x/=y;s.push(x);
			}
			i--;
		}
	}
	printf("%.4f\n",s.top());
	return 0;
}

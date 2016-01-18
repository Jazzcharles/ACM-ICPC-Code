#include <bits/stdc++.h>
using namespace std;
const int maxn=5003;
string a[maxn];

string add(string str1,string str2){
	string str;
	int len1=str1.length();
	int len2=str2.length();
	if(len1<len2)
		for(int i=0;i<len2-len1;i++)
			str1="0"+str1;
	else
		for(int i=0;i<len1-len2;i++)
			str2="0"+str2;
	len1=str1.length();
	int temp=0,up=0;
	for(int i=len1-1;i>=0;i--){
		temp=str1[i]-'0'+str2[i]-'0'+up;
		up=temp/10;temp%=10;
		str=char(temp+'0')+str;
	}
	if(up) str=char(up+'0')+str;
	return str;
}

int main(int argc, char** argv) {
	int n;
	a[0]=a[1]='1';
	for(int i=2;i<maxn;i++){
		a[i]=add(a[i-1],a[i-2]);
	}
	while(scanf("%d",&n)!=EOF){
		getchar();
		cout<<a[n-1]<<endl;
	}
	return 0;
}

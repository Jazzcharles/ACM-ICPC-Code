#include<iostream>
#include<algorithm>
using namespace std;
int n,len;
bool ok(int a[]){
	for(int i=0;i<len;i++){
		if(a[i]!=a[len-i-1]) return 0;
	}
	return 1;
}
int main(){
	int cnt=0;
	string s;
	cin>>n>>s;
	len=s.length();
	int a[100]={0},b[100]={0};
	for(int i=0;i<s.length();i++){
		if(isdigit(s[i])) a[i]=s[i]-'0';
		else a[i]=s[i]-'A'+10;
	}
	while(!ok(a)){
		for(int i=0;i<len;i++) b[i]=a[len-i-1];	
		for(int i=0;i<len;i++){
			a[i+1]+=(a[i]+b[i])/n;
			a[i]=(a[i]+b[i])%n;
		}	
		cnt++;
		if(a[len]>0) len++;
		if(cnt>=30) break;
	//	for(int i=0;i<len;i++) cout<<a[i];cout<<endl;
	}
	if(cnt>=30) printf("Impossible!\n");
	else printf("STEP=%d\n",cnt);
	return  0;
}


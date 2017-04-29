#include<bits/stdc++.h>
using namespace std;


void print(char *a,int len){
	int i=0;
	if(len<=0) return ;
	while(i<len && a[i]=='0')i++;
	for(int j=i;j<len;j++) printf("%c",a[j]);
	printf(" ");
}

void sett(char *a,int len,int id){
	if(id == len-1){
		print(a,len);
		return ;
	}
	for(int i = 0; i < 10; i++){
		a[id+1] = i + '0';
		sett(a,len,id+1);
	}
}

int main(){
	int n;
	cin>>n;
	char *s = new char[n+1];
	for(int i=0; i<10; i++){
		s[0] = i + '0';
		sett(s,n,0);
	}
	
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+500;
char s[maxn];
int a[maxn];
queue<int> q;
int main(){
	int n;
	cin>>n;
	scanf("%s",s);//D->1 , R->2  
	for(int i=0;i<n;i++){
		if(s[i]=='D') q.push(1);
		else q.push(2);
	}
	int ans=0,d=0,r=0;
	while(q.size()>1){
		int top=q.front();
		q.pop();
		if(q.size()==d || q.size()==r) break;
		if(top==1){
			if(d==0) {
				r++;
				q.push(top);	
			}
			else d--;
		}
		else{
			if(r==0) {
				d++;	
				q.push(top);
			}
			else r--;
		}
	//	cout<<top<<' '<<d<<' '<<r<<endl;
	}
	cout<<(q.front()==1?'D':'R')<<endl;
	
	return 0;
} 
/*
5
DDRRR

6
DDRRRR
*/ 

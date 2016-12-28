#include<bits/stdc++.h>
using namespace std;

queue<int> q1;
queue<int> q2;
int main(){
	int n;
	int p,q;
	cin>>n;
	cin>>p;
	for(int i=0;i<p;i++){
		int x;cin>>x;
		q1.push(x);
	}
	cin>>q;
	for(int i=0;i<q;i++){
		int x;cin>>x;
		q2.push(x);
	}
	int ans=0,tot=(1<<n),cnt=0;
	while(!q1.empty() && !q2.empty() && cnt<=tot){
		int p1=q1.front();q1.pop();
		int p2=q2.front();q2.pop();
		if(p1<p2){
			q2.push(p1);
			q2.push(p2);
		}
		else{
			q1.push(p2);
			q1.push(p1);
		}
		cnt++;
	}
	if(cnt>tot){
		cout<<-1<<endl;
	}
	else if(q1.empty()){
		cout<<cnt<<' '<<2<<endl;
	}
	else if(q2.empty()){
		cout<<cnt<<' '<<1<<endl;
	}
	return 0;
} 
/*
4
2 1 3
2 4 2

3
1 2
2 1 3

2
1 1
1 2



10
3 7 10 8
7 4 6 9 2 5 1 3

*/

 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 const int maxn=2e5+500;
 struct node{
 	ll s,d,id;
 }a[maxn];
 
 ll ans[maxn];
 int main(){
 	int n,m;
 	cin>>n>>m;
	ll ct=0,cur=0,fin=0;//cur:当前时间，fin:结束时间 
	queue<node> q;
	for(int i=0;i<n;i++) {
		ll s,d;
		cin>>a[i].s>>a[i].d;
		a[i].id=i;
	}
	for(int i=0;i<n;i++){
		ll s=a[i].s,d=a[i].d;
		if(fin<=s){
			if(q.empty())
			{
//				cout<<111<<endl;
				ans[i]=s+d;
				fin=s+d;				
			}
			else{
//				cout<<222<<endl;
				node t=q.front();q.pop();
				if(fin<t.s) fin=t.s;
				fin+=t.d;
				ans[t.id]=fin;
				//ct--;			
				q.push(a[i]);	
			}

		}	
		else{
			if(ct<m){
//				cout<<333<<endl;
				q.push(a[i]);
				ct++;			
			}
			else{
//				cout<<444<<endl;
				ans[i]=-1;
			}
		}	
		//cout<<fin<<' '<<ct<<endl;
			
	}
	while(!q.empty()){
		node t=q.front();q.pop();
		if(fin<t.s) fin=t.s;
		ans[t.id]=fin+t.d;
		fin+=t.d;
	//	cout<<666<<endl;
	}
 	
 	for(int i=0;i<n;i++){
 		if(i==n-1) cout<<ans[i]<<endl;
		else cout<<ans[i]<<' ';	
	}
 	
 	
 	
 	return 0;
 }
 /*
5 1

2 9
4 8
10 9
15 2
19 1

4 1
2 8
4 8
10 9
15 2


4 3
999999996 1000000000
999999997 1000000000
999999998 1000000000
999999999 1000000000



10 60000

65515 2778

286889 2039

411491 2492

519302 2637

554728 2818

669869 4454

688768 5352

756046 1623

757102 28

882151 1584






883735
*/

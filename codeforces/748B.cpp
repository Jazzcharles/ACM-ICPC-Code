#include<bits/stdc++.h>
using namespace std;
typedef pair<char,char> PII;
set<PII> s;
set<char> ss; 
int f[1005];
int main(){
	string a,b;
	cin>>a>>b;
	int cnt=0,ff=0,n=a.length();
	for(int i=0;i<n;i++){
		char p=a[i];
		char q=b[i];
		int flag=0;
		for(int j=i+1;j<n;j++){
			if(b[j]==p && a[j]!=q) ff=1;
			if(b[j]!=p && a[j]==q) ff=1;
		}
		if(ff) break;
		if(p!=q && !s.count(make_pair(a[i],b[i])) && !s.count(make_pair(b[i],a[i]))) {
			if(ss.count(a[i]) || ss.count(b[i])) {ff=1;break;}
			s.insert(make_pair(a[i],b[i])),cnt++;
			ss.insert(a[i]);ss.insert(b[i]);
		}
	}
	if(ff) cout<<-1<<endl;
	else{
		cout<<cnt<<endl;
		set<PII> :: iterator it=s.begin();
		for(;it!=s.end();it++){
			cout<<it->first<<' '<<it->second<<endl;
		}
	}
	
	
	return 0;
} 

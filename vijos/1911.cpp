#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
int a[105];
int main(){
	int n;
	cin>>n;
	set<int> s;
	map<int,int> m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m[a[i]]=1;
	}
	int cnt=0;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(m[a[i]+a[j]])
				s.insert(a[i]+a[j]);
		}
	}
	cout<<s.size()<<endl;
	return 0;
}

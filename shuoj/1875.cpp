#include<iostream>
#include<cstring>
#include<set>
using namespace std;
long long a[105],n,f;
int dfs(int cnt,long long ans){
	ans=ans^a[cnt];		
//	cout<<ans<<' '<<cnt<<endl;
	if(!ans) f=1;
	for(int i=cnt+1;i<n;i++)
		dfs(i,ans);
}
int main(){
	while(cin>>n)
	{
		f=0;
		int ff=0;
		memset(a,0,sizeof(a));
		multiset<long long> s;
		for(int i=0;i<n;i++){
				scanf("%d",&a[i]);
				s.insert(a[i]);
		}
		for(multiset<long long> :: iterator it=s.begin();it!=s.end();it++){
			if(s.count(*it)>=2) ff=1;
		}
		if(ff) {
			printf("YES\n");continue;
		}
		dfs(1,a[0]);
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 

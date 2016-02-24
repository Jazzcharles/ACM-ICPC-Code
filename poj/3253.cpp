#include<iostream>
#include<queue>
#include<cstdio> 
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
int a[maxn];
int main(){
	priority_queue<int,vector<int>,greater<int> > q;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		int x;scanf("%d",&x);
		q.push(x); 
	}
	LL ans=0;
	while(!q.empty()){
        int temp=q.top();
        q.pop();
        if(q.empty())
          break;
        temp+=q.top();
        q.pop();
        ans+=temp;
        q.push(temp);
    }
	printf("%lld\n",ans);
	return 0;
}

#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>L;X--)
#define DEP2(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1
typedef long long LL;  
const int N=1e5+5; 
int add[N<<2];  
int sum[N<<2]; 
int Max[N<<2]; 
void PushUP(int rt)  
{  
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
    sum[rt]=min(sum[rt<<1],sum[rt<<1|1]);  
}  
  
void PushDown(int rt,int m)  
{  
    if(add[rt])  
    {  
        add[rt<<1]+=add[rt];  
        add[rt<<1|1]+=add[rt];  
        sum[rt<<1]+=(m-(m>>1))*add[rt];  
        sum[rt<<1|1]+=(m>>1)*add[rt];  
        add[rt]=0;  
    }  
}  
  
void Build(int l,int r,int rt)  
{  
    add[rt]=0;  
    if(l==r)  
    {  
        scanf("%I64d",&sum[rt]);  
        Max[rt]=sum[rt];
		return;  
    }  
    int m=(l+r)>>1;  
    Build(lson);  
    Build(rson);  
    PushUP(rt);  
}  
  
void Update(int L,int R,int c,int l,int r,int rt)  
{  
    if(L<=l&&R>=r)  
    {  
        add[rt]+=c;  
        sum[rt]+=(LL)c*(r-l+1);  
        return;  
    }  
    PushDown(rt,r-l+1);  
    int m=(l+r)>>1;  
    if(L<=m)  
        Update(L,R,c,lson);  
    if(R>m)  
        Update(L,R,c,rson);  
    PushUP(rt);  
}  
  
int Query(int L,int R,int l,int r,int rt)  
{  
    if(L<=l&&R>=r)  
        return Max[rt];  
    PushDown(rt,r-l+1);  
    int m=(l+r)>>1;  
    int ret=0;  
    if(L<=m)   ret=max(ret,Query(L,R,lson));  
    if(R>m)    ret=max(ret,Query(L,R,rson));  
    return ret;  
}  

int query(int L,int R,int l,int r,int rt)  
{  
    if(L<=l&&R>=r)  
        return sum[rt];  
    PushDown(rt,r-l+1);  
    int m=(l+r)>>1;  
    int ret=INF;  
    if(L<=m)   ret=min(ret,query(L,R,lson));  
    if(R>m)    ret=min(ret,query(L,R,rson));  
    return ret;  
}  


int main(){
	int t,ca=1;
	scanf("%d",&t);
	while(t--){
		int n,q;
		scanf("%d%d",&n,&q);
		Build(1,n,1);
		printf("Case %d:",ca++);
		int ans=0;
		for(int i=1;i+q-1<=n;i++){
			int l=i,r=i+q-1;
		//	cout<<ans<<' '<<Query(l,r,1,n,1)<<' '<<query(l,r,1,n,1)<<endl;
			ans=max(ans,Query(l,r,1,n,1)-query(l,r,1,n,1));
		}
		printf(" %d\n",ans);
	}
	return 0;
}
/*
3
6 2
6 0 8 8 8 4
8 3
19 8 4 13 12 1 0 13
2 2
1 1
*/

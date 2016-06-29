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
LL add[N<<2];  
LL sum[N<<2];  
void PushUP(int rt)  
{  
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
  
LL Query(int L,int R,int l,int r,int rt)  
{  
    if(L<=l&&R>=r)  
        return sum[rt];  
    PushDown(rt,r-l+1);  
    int m=(l+r)>>1;  
    LL ret=INF;  
    if(L<=m)   ret=min(ret,Query(L,R,lson));  
    if(R>m)    ret=min(ret,Query(L,R,rson));  
    return ret;  
}  


int main(){
	int t,ca=1;
	scanf("%d",&t);
	while(t--){
		int n,q;
		scanf("%d%d",&n,&q);
		Build(1,n,1);
		printf("Case %d:\n",ca++);
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",Query(l,r,1,n,1));
		}
	}
	return 0;
}
/*
2
5 3
78 1 22 12 3
1 2
3 5
4 4
 
1 1
10
1 1
*/

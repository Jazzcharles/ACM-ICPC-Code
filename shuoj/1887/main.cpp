#include <bits/stdc++.h>
using namespace std;
#define LL long long  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
const int maxn=1e5;  
LL add[maxn<<2];  
LL sum[maxn<<2];  
  
void PushUP(int rt)  
{  
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];  
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
        scanf("%lld",&sum[rt]);  
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
    LL ret=0;  
    if(L<=m)   ret+=Query(L,R,lson);  
    if(R>m)    ret+=Query(L,R,rson);  
    return ret;  
}  
int main(int argc, char** argv) {
	int n,m;
	scanf("%d%d",&n,&m);
	Build(1,n,1);
	while(m--){
		int q;
		scanf("%d",&q);
		if(q==1){
			int l,r,p;
			scanf("%d%d%d",&l,&r,&p);
			Update(l,r,p,1,n,1);
		}
		if(q==2){
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",Query(l,r,1,n,1));
		}
	}
	return 0;
}

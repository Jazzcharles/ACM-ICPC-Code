#include <iostream>
using namespace std;
#define LL long long  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
const int N=1e5+5;  
LL add[N<<2];  
LL sum[N<<2];  
  
void PushUP(int rt)  
{  
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];  
}  
  
void PushDown(int rt,int m)  
{  
    if(add[rt])  
    {  
        add[rt<<1]=add[rt];  
        add[rt<<1|1]=add[rt];  
        sum[rt<<1]=(m-(m>>1))*add[rt];  
        sum[rt<<1|1]=(m>>1)*add[rt];  
        add[rt]=0;  
    }  
}  
  
void Build(int l,int r,int rt)  
{  
    add[rt]=0;  
    if(l==r)  
    {  
        sum[rt]=1; 
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
        add[rt]=c;  
        sum[rt]=(LL)c*(r-l+1);  
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
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		Build(1,n,1);
		int q;
		scanf("%d",&q);
		while(q--){
			int l,r,op;
			scanf("%d%d%d",&l,&r,&op);
			Update(l,r,op,1,n,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",ca++,Query(1,n,1,n,1));
	}

	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
#define LL long long  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
const int N=2e5+5;  
LL add[N<<2];  
LL sum[N<<2];  
LL low[N<<2];
LL tall[N<<2];  
LL Max,Min;
void PushUP(int rt)  
{  
    sum[rt]=sum[rt<<1]+sum[rt<<1|1]; 
	low[rt]=min(low[rt<<1],low[rt<<1|1]);
	tall[rt]=max(tall[rt<<1],tall[rt<<1|1]); 
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
        scanf("%d",&low[rt]);  
        tall[rt]=low[rt];
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
	//cout<<L<<' '<<R<<' '<<l<<' '<<r<<' '<<rt<<endl;
    if(L<=l&&R>=r){
    //	 cout<<rt<<' '<<l<<' '<<r<<endl;
    	 Max=max(Max,tall[rt]);
		 Min=min(Min,low[rt]);  
		 return 0;
	}  
    //PushDown(rt,r-l+1);  
    int m=(l+r)>>1;  
    int ret=0;  
    if(L<=m)   ret=max(ret,Query(L,R,lson));  
    if(R>m)    ret=max(ret,Query(L,R,rson));  
    return ret;  
}  

int main(){
	int n,q;
	while(~scanf("%d%d",&n,&q))
	{
		memset(low,0,sizeof(low));
		memset(tall,0,sizeof(tall));
		Build(1,n,1);
		while(q--)
		{
			Max=0,Min=INF;
			int l,r;
			scanf("%d%d",&l,&r);
			Query(l,r,1,n,1);
			printf("%d\n",Max-Min);
		}
	
	}
	
	return 0;
}

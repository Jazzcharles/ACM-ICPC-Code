#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;
#define LL long long  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
const int N=1e5+5;  
LL add[N<<2];  
LL sum[N<<2];  
LL f[N<<2];
int flag,k;  
void PushUP(int rt)  
{  
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	f[rt]=f[rt<<1]+f[rt<<1|1];  
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
	if(m==2 && sum[rt<<1]>k) f[rt<<1]=1; else f[rt<<1]=0;
	if(m==2 && sum[rt<<1|1]>k) f[rt<<1|1]=1;  else f[rt<<1|1]=0;
	if(m==3 && sum[rt<<1|1]>k) f[rt<<1|1]=1;  else f[rt<<1|1]=0;
}  
  
void Build(int l,int r,int rt)  
{  
    add[rt]=0;
	f[rt]=0;  
    if(l==r)  
    {  
        sum[rt]=0;  
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
    	if(c<0 && f[rt]) f[rt]=0;
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
    if(L<=l&&R>=r){
    	 if(f[rt]) flag=1;
    	 return sum[rt];  
	}  
    PushDown(rt,r-l+1);  
    int m=(l+r)>>1;  
    LL ret=0;  
    if(L<=m)   ret+=Query(L,R,lson);  
    if(R>m)    ret+=Query(L,R,rson);  
    return ret;  
}  
int main()
{
    int n,m;
    scanf("%d%d%d",&n,&m,&k);
    while(m--)
    {
    	int l,r;
    	scanf("%d%d",&l,&r);
    	Update(l,r-1,1,1,n,1);
    	Query(l,r-1,1,n,1);
    	for(int i=1;i<=4*n;i++)
    		cout<<sum[i]<<' ';
    	cout<<endl;
    		for(int i=1;i<=4*n;i++)
    		cout<<f[i]<<' ';
    	cout<<endl;
    	if(!flag)
    		printf("Yes\n");
		else{
			Update(l,r-1,-1,1,n,1);
			//Query(l,r-1,1,n,1);
			flag=0;
			printf("No\n");
		}    	
		for(int i=1;i<=4*n;i++)
    		cout<<sum[i]<<' ';
    	cout<<endl;
    	for(int i=1;i<=4*n;i++)
    		cout<<f[i]<<' ';
    	cout<<endl;
	
	}
	return 0;
}

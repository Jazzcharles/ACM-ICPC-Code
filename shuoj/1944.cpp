#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
const int N=1e5+5;  
LL add[N<<2];  
LL sum[N<<2];  

LL gcd(LL a,LL b){
	if(!b) return a;
	else return gcd(b,a%b);
}  

void PushUP(int rt)  
{  
    sum[rt]=gcd(sum[rt<<1],sum[rt<<1|1]);  
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
  
LL Query(int L,int R,int l,int r,int rt)  
{  
    if(L<=l&&R>=r)  
        return sum[rt];  
    //PushDown(rt,r-l+1);  
    int m=(l+r)>>1;  
    LL ret=0;  
    if(L<=m)   ret=gcd(ret,Query(L,R,lson));  
    if(R>m)    ret=gcd(ret,Query(L,R,rson));  
    return ret;  
}  

int main(){
	ios::sync_with_stdio(false);
	int n,q;
	scanf("%d%d",&n,&q);
	Build(1,n,1);
	//for(int i=1;i<=n*2;i++) cout<<sum[i]<<' ';cout<<endl;
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		cout<<Query(l,r,1,n,1)<<endl;
	}
	return 0;
}

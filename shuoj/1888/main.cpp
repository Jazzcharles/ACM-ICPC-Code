#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
#define LL long long  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
  
LL add[maxn<<2];
LL bdd[maxn<<2];  
LL sum[maxn<<2];  
bool flag[maxn<<2];
  
void PushUP(int rt)  
{  
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];  
}  
  
void PushDown(int rt,int m)  
{
    if(flag[rt])  
    {  
		sum[rt<<1]=(m-(m>>1))*bdd[rt];  
        sum[rt<<1|1]=(m>>1)*bdd[rt];
		bdd[rt]=0; 
   // 	cout<<rt<<' '<<sum[rt<<1]<<' '<<sum[rt<<1|1]<<endl;  
    	flag[rt]=0;
	}  
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
	bdd[rt]=0; 
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
  
void Update(int L,int R,ll c,int l,int r,int rt)  
{  
    if(L<=l&&R>=r)  
    {  
        add[rt]+=c;  
        sum[rt]+=(LL)c*(r-l+1);  
 //       cout<<123456<<endl;
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
void Updata(int L,int R,ll c,int l,int r,int rt)  
{  
    if(L<=l&&R>=r)  
    {  
        bdd[rt]=c;
		flag[rt]=1;  
        sum[rt]=(LL)c*(r-l+1);  
     //   cout<<rt<<' '<<sum[rt]<<endl;
        return;  
    }
	if(flag[rt]) PushDown(rt,r-l+1);  
    PushDown(rt,r-l+1);  
    int m=(l+r)>>1;  
    if(L<=m)  
        Updata(L,R,c,lson);  
    if(R>m)  
        Updata(L,R,c,rson);  
    PushUP(rt);  
}
  
LL Query(int L,int R,int l,int r,int rt)  
{  
    if(L<=l&&R>=r){
    //	if(flag[rt]) 
    	return sum[rt]; 
	}
	if(flag[rt]) PushDown(rt,r-l+1);   
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
	while(m--)
	{
		int q;
		scanf("%d",&q);
		if(q==1){
			int k,l,r;
			ll b;
			scanf("%d%d%lld%d",&l,&r,&k,&b);
			if(k)
				Update(l,r,b,1,n,1);	
			else{
				Updata(l,r,b,1,n,1);
		/*		for(int i=1;i<=4*n;i++){
					cout<<sum[i]<<' ';
				}
				cout<<endl;
		*/	}	
		}
		if(q==2){
			int l,r;scanf("%d%d",&l,&r);
			printf("%lld\n",Query(l,r,1,n,1));
		/*	for(int i=1;i<=4*n;i++){
					cout<<sum[i]<<' ';
			}
			cout<<endl;
		*/}
	}
	return 0;
}

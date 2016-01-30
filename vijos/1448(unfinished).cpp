#include<iostream>
using namespace std;
#define LL long long  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
const int N=2e6+5;  
LL add[N<<2];  
LL sum[N<<2];
LL Max[N<<2];
LL maxl[N<<2];
LL maxr[N<<2];
void PushUP(int rt)  
{  
	if(maxl[rt<<1|1] )
}
  
void Build(int l,int r,int rt)  
{  
    add[rt]=0;  
    if(l==r)  
    {  
        scanf("%I64d",&sum[rt]);  
 		max[rt]=maxl[rt]=maxr[rt]=sum[rt];
        return;  
    }  
    int m=(l+r)>>1;  
    Build(lson);  
    Build(rson);  
    PushUP(rt);  
}  
  
void Update(int L,int R,int c,int l,int r,int rt)  
{  
    if(L==l&&R==r)  
    {  
        //add[rt]+=c;  
        
        sum[rt]=c;  
        return;  
    } 
  //  PushDown(rt,r-l+1);  
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
		return sum[rt];
	}
    PushDown(rt,r-l+1);  
    int m=(l+r)>>1;  
    LL ret=0;  
    if(L<=m && R>m){
    	int a=Query(L,R,lson),b=Query(L,R,rson);
    	if(a>0 && b>0) ret+=(a+b);
		else ret=max(a,b);   	
	}
    else{
		if(L<=m)   ret+=Query(L,R,lson);  
		if(R>m)    ret+=Query(L,R,rson);  	
	}	
    return ret;  
}  

int main(){
	int n,m;
	cin>>n>>m;
	Build(1,n,1);
	while(m--){
		//for(int i=1;i<=n*2;i++) cout<<sum[i]<<' ';cout<<endl;
		int q,x,y;
		cin>>q>>x>>y;		
		if(q==2){
			Update(x,x,y,1,n,1);
		} 
		else{
			if(x>y) swap(x,y);
			cout<<Query(x,y,1,n,1)<<endl;
		}
	}
	return 0;
}

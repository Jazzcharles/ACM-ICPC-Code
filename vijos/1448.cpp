#include<iostream>
using namespace std;
#define LL long long  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
const int N=1e5+5;  
LL add[N<<2];  
LL sum[N<<2];
//LL tag[N<<2];  
int k;  
void PushUP(int rt)  
{  
    sum[rt]++;  
}  
  
void PushDown(int rt,int m)  
{  
    if(add[rt])  
    {  
        //add[rt<<1]+=add[rt];  
        //add[rt<<1|1]+=add[rt];  
        sum[rt<<1]++;  
        sum[rt<<1|1]++;  
        add[rt]=0;  
    }  
}  
  
void Build(int l,int r,int rt)  
{  
    add[rt]=0;  
    if(l==r)  
    {  
       // scanf("%I64d",&sum[rt]);  
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
        add[rt]++;  
        sum[rt]++;
	//	tag[rt]=k;  
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

int main(){
	int n,m;
	cin>>n>>m;
	Build(1,n,1);
	while(m--)
	{
		int q,l,r;
		cin>>q>>l>>r;
		if(q==1){
			Update(l,r,1,1,n,1);
			k++;
		}
		else{
			cout<<Query(l,r,1,n,1)<<endl;
		}
		for(int i=1;i<=n*4;i++) cout<<sum[i]<<' ';cout<<endl;
	}
	
	return 0;
}

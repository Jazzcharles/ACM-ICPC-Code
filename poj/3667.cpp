#include<iostream>
#include<cstdio>
using namespace std;
#define LL long long  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
const int N=1e5+5;  
LL add[N<<2];  
LL sum[N<<2],lsum[N<<2],rsum[N<<2];  
  
void PushUP(int rt,int m)  
{  
	lsum[rt]=(lsum[rt<<1]==(m-(m>>1)))?lsum[rt<<1]+lsum[rt<<1|1]:lsum[rt<<1];
    rsum[rt]=(rsum[rt<<1|1]==(m>>1))?rsum[rt<<1]+rsum[rt<<1|1]:rsum[rt<<1|1];
	sum[rt]=max(max(sum[rt<<1],sum[rt<<1|1]),rsum[rt<<1]+lsum[rt<<1|1]);
}  
  
void PushDown(int rt,int m)  
{  
    if(add[rt]!=-1)  
    {
    	add[rt<<1]=add[rt];
    	add[rt<<1|1]=add[rt];
    	sum[rt<<1]=lsum[rt<<1]=rsum[rt<<1]=add[rt]?0:m-(m>>1);
    	sum[rt<<1|1]=lsum[rt<<1|1]=rsum[rt<<1|1]=add[rt]?0:(m>>1);
		add[rt]=-1;   
	}  
}  
  
void Build(int l,int r,int rt)  
{  
    add[rt]=-1;  
    sum[rt]=lsum[rt]=rsum[rt]=r-l+1;
	if(l==r)  
    { 
	//	sum[rt]=lsum[rt]=rsum[rt]=1; 
    //    scanf("%I64d",&sum[rt]);  
        return;  
    }  
    int m=(l+r)>>1;  
    Build(lson);  
    Build(rson);  
 //   PushUP(rt,r-l+1);  
}  
  
void Update(int L,int R,int c,int l,int r,int rt)  
{  
    if(L<=l&&R>=r)  
    {  
        sum[rt]=lsum[rt]=rsum[rt]=c?0:r-l+1;
		add[rt]=c;  
        return;  
    }  
    PushDown(rt,r-l+1);  
    int m=(l+r)>>1;  
    if(L<=m)  
        Update(L,R,c,lson);  
    if(R>m)  
        Update(L,R,c,rson);  
    PushUP(rt,r-l+1);  
}  
  
LL Query(int num,int l,int r,int rt)  
{  
    if(l==r)  
        return l;  
    PushDown(rt,r-l+1);  
    int m=(l+r)>>1;  
    if(sum[rt<<1]>=num)   return Query(num,lson);  
    else if(rsum[rt<<1]+lsum[rt<<1|1]>=num)    return m-rsum[rt<<1]+1;  
    else return Query(num,rson);  
}  


int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	Build(1,n,1);
	while(m--)
	{		

		int q;
		scanf("%d",&q);
		if(q==1){
			int len;
			scanf("%d",&len);
			if(sum[1]<len) printf("0\n");
			else{
				int loc=Query(len,1,n,1);
				printf("%d\n",loc);
				Update(loc,loc+len-1,1,1,n,1);
			}	
		}
		else{
			int l,num;
			scanf("%d%d",&l,&num);
			Update(l,l+num-1,0,1,n,1);
		}
	    //for(int i=1;i<=n*2;i++) cout<<sum[i]<<' ';cout<<endl;
	    //for(int i=1;i<=n*2;i++) cout<<lsum[i]<<' ';cout<<endl;
	    //for(int i=1;i<=n*2;i++) cout<<rsum[i]<<' ';cout<<endl;
	}
	return 0;
}

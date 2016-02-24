#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long  
#define INF 0x3f3f3f3f
#define CLR(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
const int N=1e5+5;  
LL add[N<<2];  
LL sum[N<<2],lsum[N<<2],rsum[N<<2],ans,ansl,ansr,col[N<<2];  
  
void PushUP(int rt,int m)  
{  
	rsum[rt]=(rsum[rt<<1|1]==(m>>1))?rsum[rt<<1]+rsum[rt<<1|1]:rsum[rt<<1|1];
	lsum[rt]=(lsum[rt<<1]==m-(m>>1))?lsum[rt<<1]+lsum[rt<<1|1]:lsum[rt<<1];
	sum[rt]=max(max(sum[rt<<1],sum[rt<<1|1]),rsum[rt<<1]+lsum[rt<<1|1]);  
}  
  
void PushDown(int rt,int m)  
{  
    if(add[rt]!=-1)  
    {  
        add[rt<<1]=add[rt];  
        add[rt<<1|1]=add[rt];
		lsum[rt<<1]=rsum[rt<<1]=sum[rt<<1]=add[rt]?(m-(m>>1)):0;
		lsum[rt<<1|1]=rsum[rt<<1|1]=sum[rt<<1|1]=add[rt]?(m>>1):0;
		add[rt]=-1;    
    }  
}  
  
void Build(int l,int r,int rt)  
{  
    add[rt]=-1;  
    if(l==r)  
    {  
        //scanf("%I64d",&sum[rt]);  
        lsum[rt]=rsum[rt]=sum[rt]=0;
		return;  
    }  
    int m=(l+r)>>1;  
    Build(lson);  
    Build(rson);  
    PushUP(rt,r-l+1);  
}  
  
void Update(int L,int R,int c,int l,int r,int rt)  
{  
    if(L<=l&&R>=r)  
    {  
        add[rt]=c;  
        for(int i=l;i<=r;i++) col[i]=c;  
        lsum[rt]=rsum[rt]=sum[rt]=c?(r-l+1):0;
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

void init(){
	CLR(sum,0);
	CLR(lsum,0);
	CLR(rsum,0);
	CLR(add,-1);
}
struct node{
	int l,r,id;
}a[maxn];
int main(){
	int n;
	Build(1,2000,1);
	while(~scanf("%d",&n))
	{
		init();
		for(int i=0;i<n;i++){
			int l,r;char s[5];
			scanf("%d%d%s",&l,&r,s);
			if(s[0]=='w'){
				Update(l,r,1,1,2000,1);
			}
			else{
				Update(l,r,0,1,2000,1);
			}
		}
		int ansl=INF,left=INF,ansr=0,right=0,cnt=0;
	//	for(int i=1;i<=11*2;i++) cout<<col[i]<<' ';cout<<endl;
		for(int i=1;i<=2000;i++){
			if(col[i]) {
				cnt++;
				left=min(left,i);
				right=max(right,i);
	//			cout<<cnt<<endl;
			}
			else if(!col[i]){
				if(cnt==sum[1] && ansl>left){
					ansl=left;
					ansr=right;
				}
				left=INF,right=0,cnt=0;
			} 
		}
		if(ansl==INF && !ansr) printf("Oh,my god\n");
		else printf("%d %d\n",ansl,ansr);
	}
	return 0;
}

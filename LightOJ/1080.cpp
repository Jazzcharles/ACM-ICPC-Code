#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>L;X--)
#define DEP2(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1

typedef long long LL;  
const int N=1e5+5; 
LL add[N<<2];  
LL sum[N<<2]; 
LL a[N<<2],cnt;
char s[N<<2]; 
void PushUP(int rt)  
{  
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];  
}  
  
void PushDown(int rt,int m)  
{  
    //if(add[rt])  
    //{  
    //    add[rt<<1]+=add[rt];  
   //     add[rt<<1|1]+=add[rt];  
        sum[rt<<1]+=sum[rt];  
        sum[rt<<1|1]+=sum[rt];  
  		sum[rt]=0;
   //     add[rt]=0;  
   // }  
}  
  
void Build(int l,int r,int rt)  
{  
    add[rt]=0;
	sum[rt]=0;  
    if(l==r)  
    {  
        //scanf("%I64d",&sum[rt]);  
        //sum[rt]=a[cnt++];
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
        sum[rt]+=(LL)c;  
        return;  
    }  
    PushDown(rt,r-l+1);  
    int m=(l+r)>>1;  
    if(L<=m)  
        Update(L,R,c,lson);  
    if(R>m)  
        Update(L,R,c,rson);  
//    PushUP(rt);  
}  
  
LL Query(int L,int R,int l,int r,int rt)  
{  
    if(L<=l&&R>=r)  
        return sum[rt];  
    PushDown(rt,r-l+1);  
    int m=(l+r)>>1;  
    LL ret=0;  
    if(L<=m)   ret=Query(L,R,lson);  
    if(R>m)    ret=Query(L,R,rson);  
    return ret;  
}  


int main(){
	int t,ca=1;
	scanf("%d",&t);
	getchar(); 
//	getchar();
	while(t--){
		CLR(sum,0);
		cnt=0;
		string s;
		getline(cin,s);
		s=" "+s;
		int n=s.length();
		//Build(1,n,1);
		//for(int i=1;i<n*2;i++) cout<<sum[i]<<' ';cout<<endl; 
		int q;
		scanf("%d",&q);
		getchar();	
		//getchar();
		printf("Case %d:\n",ca++);
		while(q--){
			char op[5];
			scanf("%s",op);
			if(op[0]=='I'){
				int l,r;
				scanf("%d%d",&l,&r);
				getchar();
				Update(l,r,1,1,n,1);
			}
			else{
				int x;
				scanf("%d",&x);
				//getchar();	
				getchar();
				int ans=Query(x,x,1,n,1);
				if(ans&1){
					if(s[x]=='1') printf("0\n");
					else printf("1\n");
				}
				else printf("%c\n",s[x]);
			}
		//	for(int i=1;i<n*2;i++) cout<<sum[i]<<' ';cout<<endl; 
		}
		
	}
	return 0;
}
/*
2
0011001100
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5
1011110111
6
I 1 10
I 2 7
Q 2
Q 1
Q 7
Q 5


2
00110
5
I 1 5
Q 1
Q 3
I 1 3
Q 2
*/

#include<iostream>
#include<cstring>
#define lowbit(i) (i&(-i))
using namespace std;
const int maxn=1000;
int bit[1000][1000];
int query(int x,int y)
{
	int s=0;
	for(int i=x;i>0;i-=lowbit(i)){
		for(int j=y;j>0;j-=lowbit(j)) {
			s+=bit[i][j];			
		}	
	}
	return s;
}
void add(int x,int y,int d)
{
	for(int i=x;i<=maxn;i+=lowbit(i))
	{
		for(int j=y;j<=maxn;j+=lowbit(j)){
			bit[i][j]+=d;
		}
		
	}
}


int main(){
	int n,h,w;
	while(scanf("%d",&n) && n){
		memset(bit,0,sizeof(bit));
		scanf("%d%d",&w,&h);
		for(int i=0;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y,1);
		}
		int s,t,ans=0;
		scanf("%d%d",&s,&t);
		for(int i=s;i<=w;i++){
			for(int j=t;j<=h;j++){
				ans=max(ans,query(i,j)+query(i-s,j-t)-query(i-s,j)-query(i,j-t));
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
} 

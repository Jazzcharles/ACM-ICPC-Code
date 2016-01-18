#include <bits/stdc++.h>
#define MP(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> PII;
const int maxn=1e4+1;
int a,b,t[4];
bool phi[maxn],vis[maxn];
void prime(){
	memset(phi,1,sizeof(phi));
	for(int i=2;i<=maxn;i++){
    	if(phi[i])
    		for(int j=2*i;j<=maxn;j+=i){
    			phi[j]=0;
			}
	}
}

int bfs(){
	int step;
	queue<PII>q;
	q.push(MP(a,0));
	while(!q.empty()){
		PII num=q.front();
		q.pop();
		int x=num.first;step=num.second;
		if(x==b) break;
		t[3]=x%10,t[2]=x/10%10,t[1]=x/100%10,t[0]=x/1000;
		for(int i=0;i<4;i++){
			int a=t[i];
			for(int j=0;j<10;j++){
				if(i==0 && j==0) continue;
				t[i]=j;
				int temp=t[0]*1000+t[1]*100+t[2]*10+t[3];
				if(!vis[temp] && phi[temp]){
					q.push(MP(temp,step+1));
					vis[temp]=1;
				}
			}
			t[i]=a;
		}
	}
	return step;
}
int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	prime();
	while(t--){
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&a,&b);
		cout<<bfs()<<endl;
	}
	return 0;
}

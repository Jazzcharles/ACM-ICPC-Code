#include <bits/stdc++.h>
using namespace std;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define EPS 1e-8
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define lowbit(i) (i&(-i))
#define IT iterator
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
#define pi 3.1415927
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int maxn=1e5+5;
const int mod=1e9+7;
const int B=1031;
const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int dp[105];
PII v[105];
int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--){
		CLR(dp,INF);
		int n;
		cin>>n;
		REP(i,n){
   		    int x,y;
			scanf("%d%d",&v[i].X,&v[i].Y);
		}
		dp[0]=0;
		REP(i, n) {
            int r = v[i].X + 1;
            REP2(j, i, n-1) {
                if (v[j].X < r) {
                    dp[j+1] = min(dp[j+1], dp[i]+1);
                    r = max(r, v[j].X+v[j].Y);
                } 
				else 
				    break;
            }
            int l = v[i].X;
            REP2(j, i, n-1) {
                if (v[j].X - v[j].Y < l) {
                    dp[j+1] = min(dp[j+1], dp[i]+1);
                    l = v[j].X;
                }
            }
        }	
        cout<<dp[n]<<endl;
	}
	
	return 0;
}





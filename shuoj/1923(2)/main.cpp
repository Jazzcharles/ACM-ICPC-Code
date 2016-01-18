#include <bits/stdc++.h>
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define X first
#define Y second
using namespace std;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
int dp[25][25][15],dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}},sx,sy,fx,fy,m,n,k;
char a[25][25];
void bfs(){
		memset(dp, INF, sizeof(dp));
        dp[sx][sy][k] = 0;
        queue<PIII> q;
        q.push(MP(MP(sx, sy), k));
        while(!q.empty()) {
            PIII p = q.front();
            q.pop();
            int d = dp[p.X.X][p.X.Y][p.Y];
            for(int i=0;i<4;i++) {
                int tx = p.X.X + dir[i][0];
                int ty = p.X.Y + dir[i][1];
                int tk = p.Y;
                if(tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
                if(a[p.X.X][p.X.Y] == 'x') {
                    if(a[tx][ty] == 'x') continue;
                    else tk--;
                }
                if(dp[tx][ty][tk] >= d+1 && tk>=0) {
                    dp[tx][ty][tk] = d + 1;
                    q.push(MP(MP(tx,ty),tk));
                }
            }
        }
}

int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		getchar();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%c",&a[i][j]);
				if(a[i][j]=='S') 
					sx=i,sy=j;
				if(a[i][j]=='T')
					fx=i,fy=j;
			}
			getchar();
		}
		bfs();
		int ans=INF;
		for(int i=0;i<=k;i++){
			ans=min(ans,dp[fx][fy][i]);
		}
		if(ans==INF) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}

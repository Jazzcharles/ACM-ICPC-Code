#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define REP(X,N) for(int X=0;X<N;X++)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;
#define X first
#define Y second

char s[25][25];
int dis[25][25][15],dir[4][2] = {0,1,0,-1,1,0,-1,0};
int main()
{
    int t;
   	scanf("%d",&t);
    while(t--) {
        int n,m,k,si=-1,sj,ei=-1,ej;
        scanf("%d%d%d",&n,&m,&k);
        REP(i,n) {
            scanf("%s",s[i]);
            REP(j,m) {
                if(s[i][j] == 'S')
				{
                    si = i; sj = j;
                }
				if(s[i][j] == 'T')
				{
                    ei = i; ej = j;
                }
            }
        }
        memset(dis, 0x3f, sizeof(dis));
        dis[si][sj][k] = 0;
        queue<PIII> q;
        q.push(MP(MP(si, sj), k));
        while(!q.empty()) {
            PIII p = q.front();
            q.pop();
            int d = dis[p.X.X][p.X.Y][p.Y];
            REP(i,4) {
                int tx = p.X.X + dir[i][0];
                int ty = p.X.Y + dir[i][1];
                int tk = p.Y;
                if(tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
                if(s[p.X.X][p.X.Y] == 'x') {
                    if(s[tx][ty] == 'x') continue;
                    else tk--;
                }
                if(tk<0) continue;
                if(dis[tx][ty][tk] > d+1) {
        //        	cout<<tx<<' '<<ty<<' '<<tk<<endl;
                    dis[tx][ty][tk] = d + 1;
                    q.push(MP(MP(tx,ty),tk));
                }
            }
        }
        int ans = INF;
        for(int i = 0; i <= k; i++) {
            ans = min(ans, dis[ei][ej][i]);
        }
        if(ans==INF) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}

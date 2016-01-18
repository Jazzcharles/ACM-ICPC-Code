#include<bits/stdc++.h>
#define MP(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> PII;
typedef	pair<int,PII> PIII;
typedef vector<PIII> VIII; 
const int INF=9999999;
char a[25][25];
int flag[25][25][25];
int n,m,k;
int kx,ky,ex,ey;
int b[4][2]={1,0,-1,0,0,1,0,-1};

int bfs(int xx,int yy)
{
	flag[xx][yy][k]=0;
    priority_queue<PIII,VIII,greater<PIII> > q;
	q.push(MP(flag[xx][yy][k],MP(xx*25+yy,k)));
    while(!q.empty())
    {
        PIII t=q.top();
	    q.pop();
        int d=t.first;
        int T=t.second.first;
        int K=t.second.second;
        int x=T/25;
        int y=T%25;
        if(K<0) continue;
        if(x==ex&&y==ey)
        {
           // cout<<ex<<' '<<ey<<' '<<K<<endl;
            return flag[ex][ey][K];
        }
        for(int i=0;i<4;++i)
        {
            int tx=x+b[i][0];
            int ty=y+b[i][1];
            if(tx<0||tx>=n||ty<0||ty>=m||(a[x][y]=='x'&&a[tx][ty]=='x'))continue;
        	if(a[tx][ty]!='x'&& flag[tx][ty][K]>flag[x][y][K]+1)
            {
     //       	cout<<tx<<' '<<ty<<' '<<K<<endl;
                flag[tx][ty][K]=flag[x][y][K]+1;
                q.push(MP(flag[tx][ty][K],MP(tx*25+ty,K)));
            }
            else if(a[tx][ty]=='x' && K>0 &&a[x][y]!='x' && flag[tx][ty][K-1]>flag[x][y][K]+1)
        	{
     //   		cout<<tx<<' '<<ty<<' '<<K<<endl;
        		flag[tx][ty][K-1]=flag[x][y][K]+1;
        		q.push(MP(flag[tx][ty][K-1],MP(tx*25+ty,K-1)));	
        	}
    	}
	}
	return -1;
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(flag,INF,sizeof(flag));
        for(int i=0;i<n;++i)scanf("%s",a[i]);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
            	if(a[i][j]=='S')
                {
                    kx=i;
                    ky=j;                   
                }
                else if(a[i][j]=='T')
                {
                    ex=i;
                    ey=j; 
                } 
            }
        }
		int ans=bfs(kx,ky);        
        if(ans!=-1)printf("%d\n",ans);
        else puts("-1");

    }
    return 0;
} 

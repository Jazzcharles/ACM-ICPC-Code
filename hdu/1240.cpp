#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#define max 11
using namespace std;
char map[max][max][max];
int vis[max][max][max];
int n;
int st1,st2,st3,en1,en2,en3;
int step;
int x[6]={1,-1,0,0,0,0};
int y[6]={0,0,1,-1,0,0};
int z[6]={0,0,0,0,1,-1};
 
struct Q
{

    int x,y,z;
    int step;
};
void bfs()
{
    step=0;
    memset(vis,0,sizeof(vis));
    queue<Q> q;
    Q temp,now;
    temp.x=st1,temp.y=st2,temp.z=st3,temp.step=0;
    vis[temp.x][temp.y][temp.z]=1;
    q.push(temp);
    int i,j,k;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        int a,b,c;
        for(i=0;i<6;i++)
        {
            a=now.x+x[i];b=now.y+y[i];c=now.z+z[i];
            if(a==en1&&b==en2&&c==en3)
            {
                step=now.step+1;
                return;
            }
            if(a>=0&&b>=0&&c>=0&&a<n&&b<n&&c<n&&vis[a][b][c]==0&&map[a][b][c]=='O')
            {
                vis[a][b][c]=1;
                temp.x=a,temp.y=b,temp.z=c,temp.step=now.step+1;
                q.push(temp);
            }
        }
        
        
    }
    
}
int main()
{

    int i,j;
    while(scanf("%*s%d",&n)!=EOF)
    {
        memset(map,0,sizeof(map));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%s",map[i][j]);
            }
        }
        scanf("%d%d%d%d%d%d",&st1,&st2,&st3,&en1,&en2,&en3);
        char ch= getchar();
       	scanf("%*s"); 
       	if(st1==en1&&st2==en2&&st3==en3)
       	{
			printf("%d %d\n",n,0);
       		continue;
       	}
       	bfs();
       	if(step)
       	{
       		printf("%d %d\n",n,step);
       	}
       	else{
       		printf("NO ROUTE\n");
       }
    }
    return 0;
}

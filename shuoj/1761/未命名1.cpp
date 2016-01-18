#include <iostream>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
int par[maxn],head[maxn],headq[maxn],used[maxn],ans[maxn],cnt,cntq;
struct edge{
	int to,next,id;
}e[maxn<<1],query[maxn<<1];

void init(){
	memset(head,-1,sizeof(head));
	memset(headq,-1,sizeof(headq));
	memset(used,0,sizeof(used));
	memset(par,-1,sizeof(par));
	memset(ans,0,sizeof(ans));
}

void add_edge(edge *ed,int *he,int &ct,int u,int v,int num=0){
	ed[ct].to=v;
	ed[ct].next=he[u];
	ed[ct].id=num;
//	cout<<ct<<' '<<ed[ct].next<<' '<<ed[ct].id;
	he[u]=ct++;
//	cout<<' '<<he[u]<<endl;
}

int find(int u){
	if(par[u]==-1) return u;
	else return par[u]=find(par[u]);
}

void dfs(int u,int fa)
{
    used[u]=1;
    for(int j=headq[u];j!=-1;j=query[j].next)
    {
        int v=query[j].to;
        if(used[v])
            ans[query[j].id]=find(v);
    }
    for(int j=head[u];j!=-1;j=e[j].next)
    {
        int v=e[j].to;
        if(v!=fa)
            dfs(v,u);
    }
    par[u]=fa;
}
int main(){
	int t,ca=1;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		init();
		for(int i=1;i<=n;i++){
			int x,y;scanf("%d%d",&x,&y);
			add_edge(e,head,cnt,x,y,0);
			add_edge(e,head,cnt,y,x,0);
		}
		int q;
		cin>>q;
		for(int i=1;i<=q;i++){
			int x,y;scanf("%d%d",&x,&y);
			add_edge(query,headq,cntq,x,y,i);
			add_edge(query,headq,cntq,y,x,i);
		}
		dfs(0,-1);
		printf("Case %d:\n",ca++);
		for(int i=1;i<=q;i++){
			if(i!=1) putchar(' ');
			printf("%d",ans[i]);
		}
		cout<<endl;
	}

	return 0;
}

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#define L(x) ( x<<1 )
#define R(x) ( x<<1|1 )

using namespace std;

const int MAX = 20010;

struct Tnode{ int col,l,r;};
struct NODE{int x,y;};
NODE p[MAX/2];
Tnode node[MAX*4];
bool col[MAX/2];
int x[MAX];
void init()
{
	memset(col,0,sizeof(col));
	memset(node,0,sizeof(node));
}
void Build(int t,int l,int r)
{
	node[t].l = l;
	node[t].r = r;
	node[t].col = -1;
	if( l == r - 1 ) return ;
	int mid = ( l + r ) >> 1;
	Build(L(t), l, mid);
	Build(R(t), mid, r);
}

void Updata(int t,int l,int r,int col)
{
	if( l <= node[t].l && node[t].r <= r )
	{
		node[t].col = col;
		return ;
	}
//	cout<<t<<endl;
	if( node[t].col > 0 )
	{
		node[R(t)].col = node[L(t)].col = node[t].col;
		node[t].col = -1;
	}
	int mid = (node[t].r + node[t].l) >> 1;
	if( l >= mid )
		Updata(R(t),l,r,col);
	else
		if( r <= mid )
			Updata(L(t),l,r,col);
		else
		{
			Updata(L(t),l,mid,col);
			Updata(R(t),mid,r,col);
		}
}
void Compute(int t,int l,int r)
{
	if( node[t].col > 0 )
	{
		col[node[t].col] = true;
		return ;
	}
	if( l == r - 1 ) return ;
	int mid = (node[t].r + node[t].l) >> 1;
	if( l >= mid )
		Compute(R(t),l,r);
	else
		if( r <= mid )
			Compute(L(t),l,r);
		else
		{
			Compute(L(t),l,mid);
			Compute(R(t),mid,r);
		}
}
void TT(int t)
{
	if( node[t].l == node[t].r )
		return ;
	cout << node[t].l << ' ' << node[t].r << ' ' << node[t].col << endl;
		TT(L(t));
	TT(R(t));
}
void solve(int *x,int cnt,int n)
{
	init();	
	Build(1,0,cnt+1);
	for(int i=0; i<n; i++)
	{
		int xx = lower_bound(x,x+cnt,p[i].x) - x+1;
		int yy = lower_bound(x,x+cnt,p[i].y) - x+1;
		cout<<xx<<' '<<yy<<endl;
		Updata(1,xx,yy,i+1);
	//	TT(1); system("pause");
	}
	Compute(1,0,cnt+1);
	int ans = 0;
	for(int i=1; i<=n; i++)
		if( col[i] ) ans++;
	printf("%d\n",ans);
}
int main()
{
	int ncases,n;
	
	scanf("%d",&ncases);
	
	while( ncases-- )
	{
		scanf("%d",&n);
		int cnt = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			p[i].y++;
			x[cnt++] = p[i].x;
			x[cnt++] = p[i].y;
		}
		sort(x,x+cnt);
		cnt = unique(x,x+cnt) - x;
		solve(x,cnt,n);
	}
return 0;
}

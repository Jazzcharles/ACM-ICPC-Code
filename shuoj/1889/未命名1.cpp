#include <iostream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define XINF INT_MAX
#define INF 0x3f3f3f3f
#define MAXN 100000+10
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define sqr(a) ((a)*(a))
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define PF(X) push_front(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define PI  acos(-1.0)
#define test puts("OK");
#define lowbit(X) (X&(-X))
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef pair<int,int> PII;
typedef priority_queue<int,vector<int>,greater<int> > PQI;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
 
int a[MAXN];
 
const int null=-1;
int cnt,root;
 
struct node
{
    int key;
    int par;
    int sum;
    int size;
    int cld[2];
} ts[MAXN];
 
void init()
{
    cnt=0;
    root=null;
}
 
void debug(int x)
{
    if(x==null)
        return ;
    int l=ts[x].cld[0],r=ts[x].cld[1];
    debug(l);
    printf("id:%2d key:%2d par:%2d lcd:%2d(%2d) rcd:%2d(%2d) sum:%2d size:%2d\n",x,ts[x].key,ts[x].par,l,(l==null?-1:ts[l].key),r,(r==null?-1:ts[r].key),ts[x].sum,ts[x].size);
    debug(r);
}
 
void track()
{
    printf("root : %d\n",root);
    debug(root);
    puts("");
}
 
int new_node(int key,int par)
{
    ts[cnt].key=key;
    ts[cnt].par=par;
    ts[cnt].size=1;
    ts[cnt].cld[0]=ts[cnt].cld[1]=null;
    return cnt++;
}
 
void push_up(int x)
{
    ts[x].sum=ts[x].key;
    ts[x].size=1;
    if(ts[x].cld[0]!=null)
    {
        ts[x].sum+=ts[ts[x].cld[0]].sum;
        ts[x].size+=ts[ts[x].cld[0]].size;
    }
    if(ts[x].cld[1]!=null)
    {
        ts[x].sum+=ts[ts[x].cld[1]].sum;
        ts[x].size+=ts[ts[x].cld[1]].size;
    }
}
 
void rotate(int x,int k)
{
    int y=ts[x].par,z=ts[y].par;
    ts[y].cld[!k]=ts[x].cld[k];
    push_up(y); 
    if(ts[x].cld[k]!=null)
        ts[ts[x].cld[k]].par=y;
    ts[x].par=z;
    if(z!=null)
        ts[z].cld[(y==ts[z].cld[1])]=x;
    ts[y].par=x;
    ts[x].cld[k]=y;
}
 
void splay(int x,int S)
{
    while(ts[x].par!=S)
    {
        int y=ts[x].par;
        if(ts[y].par==S)
            rotate(x,ts[y].cld[0]==x);
        else
        {
            int d=(ts[ts[y].par].cld[0]==y);
            if(ts[y].cld[d]==x)
                rotate(x,!d),rotate(x,d);
            else
                rotate(y,d),rotate(x,d);
        }
    }
    push_up(x);
    if(S==-1)
        root=x;
}
 
int build(int p,int l,int r)
{
    if(r<l)
        return -1;
    int mid=(l+r)>>1;
    int t=new_node(a[mid],p);
    if(p==null)
        root=t;
    ts[t].cld[0]=build(t,l,mid-1);
    ts[t].cld[1]=build(t,mid+1,r);
    push_up(t);
    return t;
}
 
//查找中序遍历第k个节点，转到goal下 
void find_kth(int k,int goal)
{
    int r=root,ls;
    while(r!=null)
    {
        ls=(ts[r].cld[0]==null?0:ts[ts[r].cld[0]].size);
        if(k<=ls)
            r=ts[r].cld[0];
        else if(k==ls+1)
        {
            splay(r,goal);
            return ;
        }
        else
        {
            k-=(ls+1);
            r=ts[r].cld[1];
        }
    }
}
 
int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m); 
    a[0]=a[n+1]=0;
    REP2(i,1,n)
        scanf("%d",&a[i]);
    build(null,0,n+1);
    REP(k,m)
    {
        int t,l,r,x;
        scanf("%d%d%d",&t,&l,&r);
        if(t==1)
        {
            find_kth(l,null);
            find_kth(r+2,root);
            printf("%d\n",ts[ts[ts[root].cld[1]].cld[0]].sum);
        }
        else
        {
            scanf("%d",&x);
            find_kth(l,null);
            find_kth(r+2,root);
            int temp=ts[ts[root].cld[1]].cld[0];
            ts[ts[root].cld[1]].cld[0]=null;
            splay(ts[root].cld[1],null);
            if(x>r)
                x-=(r-l+1);
            find_kth(x+1,null);
            find_kth(x+2,root);
            ts[temp].par=ts[root].cld[1];
            ts[ts[root].cld[1]].cld[0]=temp;
            splay(ts[root].cld[1],null);
        }
    }
    return 0;
}


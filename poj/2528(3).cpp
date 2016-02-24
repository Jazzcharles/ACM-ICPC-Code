#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define Maxn 12000

int tol[Maxn<<4],segT[Maxn<<4],li[Maxn],ri[Maxn];
bool vis[Maxn];
int ans;

int Binsearch(int key,int r,int tol[])
{
    int l = 1,m;
    while (l <= r)
    {
        m = (l+r) >> 1;
        if (tol[m] > key)
            r = m - 1;
        else if (tol[m] < key)
            l = m + 1;
        else
            return m;
    }
}

void PushDown(int rt)
{
    if (segT[rt])
    {
        segT[rt<<1] = segT[rt<<1|1] = segT[rt];
        segT[rt] = 0;
    }
}

void update(int L,int R,int color,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
    	cout<<l<<' '<<r<<' '<<rt<<endl;
        segT[rt] = color;
        return ;
    }
    PushDown(rt);
    int m = (l+r) >> 1;
    if (L <= m)
        update(L,R,color,lson);
    if (R > m)
        update(L,R,color,rson);
}

void query(int l,int r,int rt)
{
    if (segT[rt])
    {
        if (!vis[segT[rt]])
        {
            ++ans;
            vis[segT[rt]] = true;
        }
        return ;
    }
    if (l == r) return ;
    int m = (l+r) >> 1;
    query(lson);
    query(rson);
}

int main()
{
    int c,n,i,k;
    while (~scanf("%d",&c))
    {
        while (c--)
        {
            scanf("%d",&n);
            k = 1;
            for (i = 1; i <= n; ++i)
            {
                scanf("%d%d",&li[i],&ri[i]);
                tol[k++] = li[i];
                tol[k++] = ri[i];
            }
            sort(tol+1,tol+k);
            int m = 2;
            for (i = 2; i < k; ++i)
            {
                if (tol[i] != tol[i-1])
                    tol[m++] = tol[i];
            }
            for (i = m - 1; i > 1; --i)
            {
                if (tol[i] != tol[i-1]+1)
                    tol[m++] = tol[i-1] + 1;
            }
            sort(tol+1,tol+m);
            memset(segT,0,sizeof(segT));
            for (i = 1; i <= n; ++i)
            {
                int a = Binsearch(li[i],m-1,tol);
                int b = Binsearch(ri[i],m-1,tol);
                cout<<a<<' '<<b<<' '<<i<<endl;
                update(a,b,i,1,m-1,1);
            }
            ans = 0;
            memset(vis,false,sizeof(vis));
            query(1,m-1,1);
            printf("%d\n",ans);
        }
    }
    return 0;
}

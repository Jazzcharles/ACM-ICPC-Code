/*
HDU 2528 Mayor's posters
本题大意：给定一些海报，可能相互重叠，告诉你每个海报
的宽度（高度都一样的）和先后叠放顺序，问没有被完全盖住的有多少张？
海报最多10000张，但是墙有10000000块瓷砖长，海报不会落在瓷砖中间。
如果直接建树，就算不TLE,也会MLE。即单位区间长度太多。
其实10000张海报，有20000个点，最多有19999个区间。对各个区间编号，就是离散化。然后建数。
其实浮点数也是一样离散化的。

writer:kuangbin
*/
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int MAXN=10010;
struct Cpost
{
    int l,r;
}posters[MAXN];
int x[MAXN*2];
int hash[10000005];
struct Node
{
    int l,r;
    bool bCovered;//标记是否被完全覆盖 
}segTree[MAXN*8];//这里必须开到线段数的四倍，？？ 
void Build(int i,int l,int r)//建立线段树 
{
    segTree[i].l=l;
    segTree[i].r=r;
    segTree[i].bCovered=false;
    if(l==r)return;
    int mid=(l+r)>>1;
    Build(i<<1,l,mid);
    Build(i<<1|1,mid+1,r);
}    
bool Post(int i,int l,int r)//贴上一个好报，同时判断是否被完全覆盖 
{
    if(segTree[i].bCovered)  return false;
    if(segTree[i].l==l&&segTree[i].r==r)
    {
        segTree[i].bCovered=true;
        return true;
    }    
    bool bResult;
    int mid=(segTree[i].l+segTree[i].r)>>1;
    if(r<=mid)  bResult=Post(i<<1,l,r);
    else if(l>mid)
       bResult=Post(i<<1|1,l,r);
    else
    {
        bool b1=Post(i<<1,l,mid);
        bool b2=Post(i<<1|1,mid+1,r);
        bResult=b1||b2;//不能直接或上去，因为如果前面的真，后面的会不做的 
    }
    //这个很重要，要反馈回原结点，如果左右儿子都被完全覆盖了，自然也完全覆盖了 
if(segTree[i<<1].bCovered && segTree[i<<1|1].bCovered)
        segTree[i].bCovered=true;    
    return bResult;
}    
int main()
{
    int T;
    int i,j,k;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int nCount=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&posters[i].l,&posters[i].r);
            x[nCount++]=posters[i].l;
            x[nCount++]=posters[i].r;
        }    
        sort(x,x+nCount);//先排序 
        nCount=unique(x,x+nCount)-x;//合并掉相同的项 
for(i=0;i<nCount;i++)
          hash[x[i]]=i;
        Build(1,0,nCount-1);
        int res=0;
        for(i=n-1;i>=0;i--)//要从上面开始看。 
if(Post(1,hash[posters[i].l],hash[posters[i].r]))
            res++;
        printf("%d\n",res);
    }    
    return 0;
}

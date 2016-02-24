/*
HDU 2528 Mayor's posters
������⣺����һЩ�����������໥�ص���������ÿ������
�Ŀ�ȣ��߶ȶ�һ���ģ����Ⱥ����˳����û�б���ȫ��ס���ж����ţ�
�������10000�ţ�����ǽ��10000000���ש���������������ڴ�ש�м䡣
���ֱ�ӽ��������㲻TLE,Ҳ��MLE������λ���䳤��̫�ࡣ
��ʵ10000�ź�������20000���㣬�����19999�����䡣�Ը��������ţ�������ɢ����Ȼ������
��ʵ������Ҳ��һ����ɢ���ġ�

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
    bool bCovered;//����Ƿ���ȫ���� 
}segTree[MAXN*8];//������뿪���߶������ı������� 
void Build(int i,int l,int r)//�����߶��� 
{
    segTree[i].l=l;
    segTree[i].r=r;
    segTree[i].bCovered=false;
    if(l==r)return;
    int mid=(l+r)>>1;
    Build(i<<1,l,mid);
    Build(i<<1|1,mid+1,r);
}    
bool Post(int i,int l,int r)//����һ���ñ���ͬʱ�ж��Ƿ���ȫ���� 
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
        bResult=b1||b2;//����ֱ�ӻ���ȥ����Ϊ���ǰ����棬����Ļ᲻���� 
    }
    //�������Ҫ��Ҫ������ԭ��㣬������Ҷ��Ӷ�����ȫ�����ˣ���ȻҲ��ȫ������ 
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
        sort(x,x+nCount);//������ 
        nCount=unique(x,x+nCount)-x;//�ϲ�����ͬ���� 
for(i=0;i<nCount;i++)
          hash[x[i]]=i;
        Build(1,0,nCount-1);
        int res=0;
        for(i=n-1;i>=0;i--)//Ҫ�����濪ʼ���� 
if(Post(1,hash[posters[i].l],hash[posters[i].r]))
            res++;
        printf("%d\n",res);
    }    
    return 0;
}

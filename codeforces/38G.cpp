#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>L;X--)
#define DEP2(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)
const int MAXN=1e5+5;
#define key_value ts[ts[root].cld[1]].cld[0]

int n;
int a[MAXN];
int St[MAXN],top;

const int null=-1;
int cnt,root,flag;//flag==1树中已有该点

struct node
{
    int par,cld[2];  //父节点，cld[0]左儿子，cld[1]右儿子
    int val,sum,ct; //当前值，子树和
    int size; //子树元素个数
    bool rev,same; //相同，翻转标记
    int maxl,maxr,maxm; //左起连续最大和，右起连续最大和，连续最大和
} ts[MAXN];
 
int newnode(int key,int par)
{
	int r;
	if(top)
		r=St[--top];
	else
		r=cnt++;
    ts[r].val=ts[r].sum=key;
    ts[r].par=par;
    ts[r].size=1;
    ts[r].cld[0]=ts[r].cld[1]=null;
    return r;
}

void push_down(int x){
	
}

void push_up(int x){
	
}
//旋转，0左旋，1右旋 
void rotate(int x,int k)
{
    int y=ts[x].par,z=ts[y].par;
    push_down(y);push_down(x);
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

//将x伸展至S下方 
void splay(int x,int S)
{
    for(push_down(x);ts[x].par!=S;)
    {
        int y=ts[x].par,z=ts[y].par;
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
    if(S==null)
        root=x;
}

//获取中序遍历第k位的节点编号 
int get_kth(int x,int k)
{
	push_down(x);
	int ls=(ts[x].cld[0]==null?0:(ts[ts[x].cld[0]].size));
	if(k==ls+1)
		return x;
	else if(k<=ls)
		return get_kth(ts[x].cld[0],k);
	else
		return get_kth(ts[x].cld[1],k-ls-1);
}
 
//在p下插入l到r个数 
int build(int p,int l,int r)
{
    if(r<l)
        return null;
    int mid=(l+r)>>1;
    int t=newnode(a[mid],p);
    if(p==null)
        root=t;
    ts[t].cld[0]=build(t,l,mid-1);
    ts[t].cld[1]=build(t,mid+1,r);
    push_up(t);
	return t;
}

void init()
{
	top=cnt=0;
	root=null;
	root=newnode(-1,null);
	ts[root].cld[1]=newnode(INF,root);
	//key_value=build(ts[root].cld[1],1,n);
	key_value=null;
	push_up(ts[root].cld[1]);
	push_up(root);
}
//输出结点信息
void printMess(int x)
{
	printf("id:%2d ",x);
	printf("fa:%2d ",ts[x].par);
	printf("lc:%2d ",ts[x].cld[0]);
	printf("rc:%2d ",ts[x].cld[1]);
	printf("va:%2d ",ts[x].val);
	printf("sz:%2d ",ts[x].size);
	puts("");
}
//中序遍历
void track(int x)
{
	if(x!=null)
	{
		track(ts[x].cld[0]);
		printMess(x);
		track(ts[x].cld[1]);
	}
}

void debug()
{
	printf("root : %2d\n",root);
	track(root);
	puts("");
}


//a[i]==x,c[i]==num
int insert(int x,int num)
{
    int r=root,pre=null;
    if(!root) num++;
    int ct=0,lflag=0,rflag=0;
    while(r!=null){
        if(ts[r].val<x && num>0){
			//if(num<=0) break;
			pre=r;
			r=ts[r].cld[1];
			num--;
			rflag=1,lflag=0; 
        }
        else{
        	pre=r;
        	r=ts[r].cld[0];
        	lflag=1,rflag=0;
		}
        ct++;
//        pre=r;
//        r=ts[r].cld[ts[r].val<x]; 
//     
    }
    //cout<<pre<<' '<<r<<' '<<ct<<' '<<num<<' '<<lflag<<' '<<rflag<<endl;
    //int &t=ts[pre].cld[ts[pre].val<x];
    int loc;
    if(lflag) {
    	int &t=ts[pre].cld[0];
		loc=newnode(x,pre);
	    t=loc;
	    splay(t,null);    	
	}
	else{
		int &t=ts[pre].cld[1];
		loc=newnode(x,pre);
	    t=loc;
	    splay(t,null);   
	}
    //debug(); 
    return loc;
}

//int seekpre(int x,int id){
//	if(x==null) return null;
//	if(ts[x].id>=id) return seekpre(ts[x].cld[0],id);
//	else{
//		int temp=seekpre(ts[x].cld[1],id);
//		if(temp==null) return x;
//		else return temp;
//	}
//}
//
//int seekafter(int x,int id){
//	if(x==null) return null;
//	if(ts[x].id<=id) return seekafter(ts[x].cld[1],id);
//	else{
//		int temp=seekafter(ts[x].cld[0],id);
//		if(temp==null) return x;
//		else return temp;
//	}
//}
void show(int r){
	if(r!=null){
		show(ts[r].cld[1]);
		if(r>1) printf("%d ",r-1);
		show(ts[r].cld[0]);
	}
}


int main(){
	scanf("%d",&n);
	init();
	//debug();
	for(int i=1;i<=n;i++){
		int a,c;
		scanf("%d%d",&a,&c);
		//c++;
		insert(a,c);
		//splay(get_kth(root,1),null);
		//splay(get_kth(root,i+2),root);
		//show(root);
		//cout<<endl;
		debug();
		show(root);cout<<endl;
	}
	//debug();
	//cout<<get_kth(root,1)<<' '<<get_kth(root,n+2)<<endl;
	//splay(get_kth(root,1),null);
	//splay(get_kth(root,n+2),root);
	//cout<<555<<endl;
	show(root); 
	return 0;
}
/*
2
1 0
2 1


3
1 3
2 3
3 3


5
2 3
1 4
4 3
3 1
5 2
*/

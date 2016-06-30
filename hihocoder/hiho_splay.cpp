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
const int MAXN=3e5;
#define key_value ts[ts[root].cld[1]].cld[0]

int n,flag;
int a[MAXN];
int St[MAXN],top;

const int null=-1;
int cnt,root;
 
struct node
{
    int par,cld[2];  //父节点，cld[0]左儿子，cld[1]右儿子
    int val,sum; //当前值，子树和
    int size; //子树元素个数
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

//旋转，0左旋，1右旋 
void rotate(int x,int k)
{
    int y=ts[x].par,z=ts[y].par;
  //  push_down(y);push_down(x);
    ts[y].cld[!k]=ts[x].cld[k];
  //  push_up(y); 
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
    for(;ts[x].par!=S;)
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
    //push_up(x);
    if(S==null)
        root=x;
}

//获取中序遍历第k位的节点编号 
int get_kth(int x,int k)
{
	//push_down(x);
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
    //cout<<ts[t].cld[0]<<' '<<ts[t].cld[1]<<' '<<ts[t].par<<' '<<ts[1].cld[0]<<endl; 
    //push_up(t);
	return t;
}

void init()
{
	top=cnt=0;
	root=null;
	root=newnode(-1,null);
	ts[root].cld[1]=newnode(INF,root);
	key_value=build(ts[root].cld[1],1,n);
//	push_up(ts[root].cld[1]);
//	push_up(root);
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

//删除节点，回收内存 
void erasenode(int x)
{
	if(x!=null)
	{
		St[top++]=x;
		erasenode(ts[x].cld[0]);
		erasenode(ts[x].cld[1]);
	}
}


void erase(int prea,int aftb)
{
	splay(prea,null);
	splay(aftb,root);
	//debug();
	erasenode(key_value);
	ts[key_value].par=null;
	key_value=null;
//	push_up(ts[root].cld[1]);
//	push_up(root);
}

//查找num的父节点 
int search(int num,int cur,int par){
	if(cur==null) return par;
	if(ts[cur].val==num) return cur;
	else if(num<ts[cur].val) search(num,ts[cur].cld[0],cur);
	else search(num,ts[cur].cld[1],cur);
}
//r为当前节点，loc为其父节点 ，flag=1树内已经有该节点 
int add(int key){
	int r;
	int par=search(key,root,null);
	if(key<ts[par].val){
		r=build(par,1,1);
		ts[par].cld[0]=r;
		ts[r].par=par;
	}
	else if(key>ts[par].val){
		r=build(par,1,1);
		ts[par].cld[1]=r;
		ts[r].par=par;
	}
	else r=par,flag=1;
	splay(r,null);
	return r;
}

int seekmax(int x){
	if(x==null) return null;
	else if(ts[x].cld[1]==null) return x;
	else return seekmax(ts[x].cld[1]);
} 

int seekmin(int x){
	if(x==null) return null;
	else if(ts[x].cld[0]==null) return x;
	else return seekmin(ts[x].cld[0]);
}

int seekpre(int x){
	if(ts[x].cld[0]!=null){
		return seekmax(ts[x].cld[0]);
	}
	
	int y=ts[x].par;
	while(y!=null && x==ts[y].cld[0]){
		x=y;
		y=ts[y].par;
	}
	return y;
}

int seekafter(int x){
	if(ts[x].cld[1]!=null){
		//cout<<66666666666<<endl;
		return seekmin(ts[x].cld[1]);
	}
	
	int y=ts[x].par;
	while(y!=null && x==ts[y].cld[1]){
		x=y;
		y=ts[y].par;
	}	
	return y;
}
int main(){
	n=0;
	cnt=0;
	init();
	//debug();
	int q;
	scanf("%d",&q);
	while(q--){
		char op[5];
		scanf("%s",op);

		if(op[0]=='I'){
			int num;
			scanf("%d",&num);
			a[1]=num;
			add(num);
		}
		if(op[0]=='Q'){		
			flag=0;
			int num;
			scanf("%d",&num);
			a[1]=num;
			int r=add(num);	
		//	debug();
		//	cout<<loc<<endl;
			int pre=seekpre(r);
			int aft=seekafter(r);
		//	cout<<aft<<endl;
			if(flag) printf("%d\n",num);	
			else {
				printf("%d\n",ts[pre].val);	
				erase(pre,aft);
			}
		}
		if(op[0]=='D'){
			int x,y;
			scanf("%d%d",&x,&y);
			a[1]=x;
			int ra=add(x);
		//	debug();
			a[1]=y;
			int rb=add(y);			
		//	debug();
			int prea=seekpre(ra);
			int aftb=seekafter(rb);
			erase(prea,aftb);
		}
	//	debug();
	}
	return 0;
}
/*
6
I 1
I 2
I 3
Q 4
D 2 2
Q 2



100
I 1
I 2
I 3
D 0 1

*/ 

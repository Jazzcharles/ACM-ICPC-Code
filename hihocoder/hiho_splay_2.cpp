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

ll n;
ll St[MAXN],top;

const int null=-1;
ll cnt,root,flag;

struct node
{
    ll par,cld[2];  //父节点，cld[0]左儿子，cld[1]右儿子
    ll val,sum,add; //当前值，子树和
    ll size,id; //子树元素个数,id
} ts[MAXN];
 
ll newnode(ll id,ll key,ll par)
{
	ll r;
	if(top)
		r=St[--top];
	else
		r=cnt++;
    ts[r].val=ts[r].sum=key;
    ts[r].par=par;
    ts[r].size=1;
    ts[r].cld[0]=ts[r].cld[1]=null;
    ts[r].id=id;
    ts[r].add=0;
    return r;
}


void update_add(ll x,ll v){
	ts[x].val+=v;
	ts[x].add+=v;
	ts[x].sum+=(ll)ts[x].size*v;
}

void push_up(ll x)
{
	ll l=ts[x].cld[0],r=ts[x].cld[1];
    if(l!=null && r==null)
    {
    	ts[x].sum=ts[x].val+ts[l].sum;
    	ts[x].size=1+ts[l].size;
    }
    else if(l==null && r!=null)
    {
        ts[x].sum=ts[x].val+ts[r].sum;
    	ts[x].size=1+ts[r].size;
    }
    else if(l!=null && r!=null)
    {
        ts[x].sum=ts[x].val+ts[l].sum+ts[r].sum;
    	ts[x].size=1+ts[l].size+ts[r].size;
    }
    else
    {
    	ts[x].sum=ts[x].val;
    	ts[x].size=1;
    }
}

void push_down(ll x)
{
	ll l=ts[x].cld[0],r=ts[x].cld[1];
	if(ts[x].add){
		if(l!=null) update_add(l,ts[x].add);
		if(r!=null) update_add(r,ts[x].add);
		ts[x].add=0;
	}
}
 
//旋转，0左旋，1右旋 
void rotate(ll x,int k)
{
    ll y=ts[x].par,z=ts[y].par;
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
void splay(ll x,ll S)
{
    for(push_down(x);ts[x].par!=S;)
    {
        ll y=ts[x].par,z=ts[y].par;
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


void init()
{
	n=top=0;
	cnt=0;
	root=null;
	root=newnode(-1,0,null);
	ts[root].cld[1]=newnode(INF,0,root);
	push_up(ts[root].cld[1]);
	push_up(root);
}
//输出结点信息
void printMess(int x)
{
	printf("code:%2d ",x);
	printf("id:%2d ",ts[x].id);
	printf("fa:%2d ",ts[x].par);
	printf("lc:%2d ",ts[x].cld[0]);
	printf("rc:%2d ",ts[x].cld[1]);
	printf("va:%2d ",ts[x].val);
	printf("sum:%2d ",ts[x].sum);
	printf("add:%2d ",ts[x].add);
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
void erasenode(ll x)
{
	if(x!=null)
	{
		St[top++]=x;
		erasenode(ts[x].cld[0]);
		erasenode(ts[x].cld[1]);
	}
}

//获取从pos开始连续tot个数的和 
ll get_sum(ll pre,ll aft)
{
	splay(pre,null);
	splay(aft,root);
	if (key_value==null) return 0;
	return ts[key_value].sum;
}

ll insert(ll id,ll num){
    ll r=root,pre=null;
    while(r!=null){    
		push_down(r);   //从根到节点的路径上所有标记要在新插入节点之前更新完 
        if(ts[r].id==id){
            splay(r,null);//如果直接找到的话就不新建节点，直接splay
			flag=1;     
            return r;
        }
        else{
            pre=r;
            r=ts[r].cld[ts[r].id<id];
        }
    }
    ll &t=ts[pre].cld[ts[pre].id<id];
    ll loc=newnode(id,num,pre);
    t=loc;
    splay(t,null);
    return loc;
}

ll seekpre(ll x,ll id){
	if(x==null) return null;
	if(ts[x].id>=id) return seekpre(ts[x].cld[0],id);
	else{
		ll temp=seekpre(ts[x].cld[1],id);
		if(temp==null) return x;
		else return temp;
	}
}

ll seekafter(ll x,ll id){
	if(x==null) return null;
	if(ts[x].id<=id) return seekafter(ts[x].cld[1],id);
	else{
		ll temp=seekafter(ts[x].cld[0],id);
		if(temp==null) return x;
		else return temp;
	}
}

void erase(ll pre,ll aft)
{
	splay(pre,null);
	splay(aft,root);
	erasenode(key_value);
	ts[key_value].par=null;
	key_value=null;
	push_up(ts[root].cld[1]);
	push_up(root);
}

void update(ll pre,ll aft,ll num){
	splay(pre,null);
	splay(aft,root);
	update_add(key_value,num);
	push_up(ts[root].cld[1]);
	push_up(root);
}	

int main(){
	int q;
	cin>>q;
	getchar();
	init();
	while(q--)
	{
		char op[5];
		scanf("%s",op);
		if(op[0]=='I'){
			ll id;
			ll x;
			cin>>id>>x;
			insert(id,x);	
		}
		if(op[0]=='Q'){
			ll a,b;
			cin>>a>>b;
			ll pre=seekpre(root,a);
			ll aft=seekafter(root,b);		
			cout<<get_sum(pre,aft)<<endl;
		} 
		if(op[0]=='M'){
			ll a,b;
			ll c;
			cin>>a>>b>>c;
			ll pre=seekpre(root,a);
			ll aft=seekafter(root,b);			 
			update(pre,aft,c);
		}
		if(op[0]=='D'){
			ll a,b;
			cin>>a>>b;
			ll pre=seekpre(root,a);
			ll aft=seekafter(root,b);
			erase(pre,aft);
		}
	//	debug();
	}
	

	return 0;
}
/*
15
I 1 1
I 2 2
I 3 3
Q 0 3
D 0 1
D 3 5
I 1 2
Q 1 3
M 1 2 2
Q 1 3
D 2 3
I 4 2
Q 1 4



90
I 1 1
I 2 2
I 3 3
Q 1 3
M 0 2 -2
M 1 3 3
Q 0 1
Q 0 0



D 2 3
I 4 2
Q 1 4


5
I 1 1
M 1 2 1
Q 0 0

*/

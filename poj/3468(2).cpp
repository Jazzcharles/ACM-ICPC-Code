#include<iostream>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
struct node{
	int l,r,num;
	int lazy;
}tree[maxn<<2];
int a[maxn];
void pushup(int rt){
	tree[rt].num=tree[rt<<1].num+tree[rt<<1|1].num;
}


void build(int l,int r,int rt){
	tree[rt].l=l;
	tree[rt].r=r;
	if(l==r){
		tree[rt].num=a[l];
	}
	int mid=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}

void add(int l,int r,int rt,int k){
	if(tree[rt].l==l && tree[rt].r==r){
		tree[rt].num+=k;
		return ;
	}
	int mid=(tree[rt].l+tree[rt].r)>>1;
	if(r<=mid) add(l,r,rt<<1,k);
	else if(l>mid) add(l,r,rt<<1|1,k);
	else{
		add(l,mid,rt<<1,k);
		add(mid+1,r,rt<<1|1,k);
	}
	pushup(rt);
}

void pushdown(int rt,int m){
	if(tree[rt].lazy){
		tree[rt<<1].lazy+=tree[rt].lazy;
		tree[rt<<1|1].lazy+=tree[rt].lazy;
		tree[rt].lazy=0;
	}
}
int query(int l,int r,int rt){
	if(tree[rt].l==l && tree[rt].r==r){
		return tree[rt].num+(l-r+1)*tree[rt].lazy;
	}
	pushdown(rt,r-l+1);
	int mid=(tree[rt].l+tree[rt].r)>>1;
	int ret=0;
	if(r<=mid) return ret+=query(l,r,rt<<1);
	else if(l>mid) return ret+=query(l,r,rt<<1|1);
	else return ret+=query(l,mid,rt<<1)+query(mid+1,r,rt<<1|1);
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,n,1);
	while(m--){
		char s[5];int l,r,w;
		scanf("%s",s);
		if(s[0]=='C'){
			scanf("%d%d%d",&l,&r,&w);
			add(l,r,1,w);
		}
		else{
			scanf("%d%d",&l,&r);
			cout<<query(l,r,1)<<endl;
		}
	}	
	return 0;
}

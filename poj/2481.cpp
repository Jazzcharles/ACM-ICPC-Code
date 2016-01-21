#include<iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#define lowbit(i) (i&(-i))
using namespace std;
const int maxn=1e5+5;

int n,bit[maxn],ans[maxn];
struct node{
	int x,y,id;			//(x,y)表示每一个点的坐标，id排序时用来记录每个点原来顺序 
}a[maxn];

bool cmp(node a,node b){
	return (a.y==b.y?a.x<b.x:a.y>b.y);   //按照纵坐标从高到低排序，相同时按照横坐标由小到大排序 
}

void add(int i,int x){
	while(i<=maxn){
		bit[i]+=x;
		i+=lowbit(i);
	}
}

int query(int i){
	int sum=0;
	while(i>0){
		sum+=bit[i];
		i-=lowbit(i);
	}
	return sum;
}

int main(){
	while(~scanf("%d",&n) && n){
		memset(bit,0,sizeof(bit));
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);	
			a[i].id=i;
			a[i].x++;a[i].y++;		//树状数组下标从1开始，输入的点横纵坐标都++ 
		}
		sort(a,a+n,cmp);
		ans[a[0].id]=0;		
		add(a[0].x,1);
		for(int i=1;i<n;i++){
			if(a[i].x==a[i-1].x && a[i].y==a[i-1].y)	//若两个连续点重复，则当前点的值等于前一个点的值 
				ans[a[i].id]=ans[a[i-1].id];		
			else
				ans[a[i].id]=query(a[i].x);		//否则看当前点之前（左边）的点（都比当前点高）的和（个数） 
			add(a[i].x,1);			//更新当前点（横坐标x,个数1） 
		}
		for(int i=0;i<n;i++){ 
			if(i) printf(" ");
			printf("%d",ans[i]);
		}
		cout<<endl;
	}
	return 0;
}

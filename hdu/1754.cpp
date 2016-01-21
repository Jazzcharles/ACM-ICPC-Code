#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
int num[200001];
using namespace std; 
struct node
{
	int sum;
};
node t[800005];
int creat(int x, int left, int right)
{
	if (left == right)		
	{
		t[x].sum = num[left];
		return t[x].sum;
	}
	int a=creat(x * 2, left, (left + right) / 2);		//左半区间
	int b=creat(x * 2 + 1, (left + right) / 2 + 1, right);		//右半区间
	return t[x].sum = max(a, b);
}
void add(int x, int left, int right, int lb, int rb, int q)
{
	if (left == lb && right == rb)		//找到要修改的节点
	{
		t[x].sum = q;
		return;
	}
	if (rb <= (left + right) / 2)		//如果要修改的位置在左边一半
		add(x * 2, left, (left + right) / 2, lb, rb, q);
	else if(lb > (left+right) / 2 )		//如果要修改的位置在右边一半
		add(x * 2 + 1, (left + right) / 2 + 1, right, lb, rb, q);
	else{
		add(x*2, left, (left+right)/2, lb, (left+right)/2, q);
		add(x*2+1,(left+right)/2+1, right, (left+right)/2+1 , rb, q); 
	} 
		
	t[x].sum = max(t[x * 2].sum , t[x * 2 + 1].sum);		//子区间的值发生变化，上一层区间的值也要变化
}
int count(int x, int left, int right, int lb, int rb)
{
	if (left == lb && right == rb)		//要求的左右边界与当前搜索到的区间完全吻合
		return t[x].sum;
	if (rb <= (left + right) / 2)		//要求的左右边界全部在当前区间的左半部分
		return count(x * 2, left, (left + right) / 2, lb, rb);
	else if (lb > (left + right) / 2)		//要求的左右边界全部在当前区间的右半部分
		return count(x * 2 + 1, (left + right) / 2 + 1, right, lb, rb);
	else{	
		int a=count(x * 2, left, (left + right) / 2, lb, (left + right) / 2);
		int b=count(x * 2 + 1, (left + right) / 2 + 1, right, (left + right) / 2 + 1, rb);	//要求的左右边界在当前区间的左右两半部分都有涉及，要切分开来计算
		return max( a,b );
	}
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)) 
	{
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++){
			scanf("%d",&num[i]);
		}
		creat(1,1,n);
		getchar();
	//	for(int i=1;i<=2*n;i++){
	//		cout<<t[i].sum<<' ';
	//	}
	//	cout<<endl;	
		while(m--){
			char ch[10];int l,r;
			scanf("%s",ch);	
			if(ch[0]=='U'){
				scanf("%d%d",&l,&r);
				add(1,1,n,l,l,r);
		//		for(int i=1;i<=2*n;i++){
		//			cout<<t[i].sum<<' ';
		//		}
		//		cout<<endl;
			}
			if(ch[0]=='Q'){
				scanf("%d%d",&l,&r);
				printf("%d\n",count(1,1,n,l,r));
			}
		}
	}
	 
	
	return 0;
}

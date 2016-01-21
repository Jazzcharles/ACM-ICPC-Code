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
	int a=creat(x * 2, left, (left + right) / 2);		//�������
	int b=creat(x * 2 + 1, (left + right) / 2 + 1, right);		//�Ұ�����
	return t[x].sum = max(a, b);
}
void add(int x, int left, int right, int lb, int rb, int q)
{
	if (left == lb && right == rb)		//�ҵ�Ҫ�޸ĵĽڵ�
	{
		t[x].sum = q;
		return;
	}
	if (rb <= (left + right) / 2)		//���Ҫ�޸ĵ�λ�������һ��
		add(x * 2, left, (left + right) / 2, lb, rb, q);
	else if(lb > (left+right) / 2 )		//���Ҫ�޸ĵ�λ�����ұ�һ��
		add(x * 2 + 1, (left + right) / 2 + 1, right, lb, rb, q);
	else{
		add(x*2, left, (left+right)/2, lb, (left+right)/2, q);
		add(x*2+1,(left+right)/2+1, right, (left+right)/2+1 , rb, q); 
	} 
		
	t[x].sum = max(t[x * 2].sum , t[x * 2 + 1].sum);		//�������ֵ�����仯����һ�������ֵҲҪ�仯
}
int count(int x, int left, int right, int lb, int rb)
{
	if (left == lb && right == rb)		//Ҫ������ұ߽��뵱ǰ��������������ȫ�Ǻ�
		return t[x].sum;
	if (rb <= (left + right) / 2)		//Ҫ������ұ߽�ȫ���ڵ�ǰ�������벿��
		return count(x * 2, left, (left + right) / 2, lb, rb);
	else if (lb > (left + right) / 2)		//Ҫ������ұ߽�ȫ���ڵ�ǰ������Ұ벿��
		return count(x * 2 + 1, (left + right) / 2 + 1, right, lb, rb);
	else{	
		int a=count(x * 2, left, (left + right) / 2, lb, (left + right) / 2);
		int b=count(x * 2 + 1, (left + right) / 2 + 1, right, (left + right) / 2 + 1, rb);	//Ҫ������ұ߽��ڵ�ǰ������������벿�ֶ����漰��Ҫ�зֿ�������
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

#include<iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#define lowbit(i) (i&(-i))
using namespace std;
const int maxn=1e5+5;

int n,bit[maxn],ans[maxn];
struct node{
	int x,y,id;			//(x,y)��ʾÿһ��������꣬id����ʱ������¼ÿ����ԭ��˳�� 
}a[maxn];

bool cmp(node a,node b){
	return (a.y==b.y?a.x<b.x:a.y>b.y);   //����������Ӹߵ���������ͬʱ���պ�������С�������� 
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
			a[i].x++;a[i].y++;		//��״�����±��1��ʼ������ĵ�������궼++ 
		}
		sort(a,a+n,cmp);
		ans[a[0].id]=0;		
		add(a[0].x,1);
		for(int i=1;i<n;i++){
			if(a[i].x==a[i-1].x && a[i].y==a[i-1].y)	//�������������ظ�����ǰ���ֵ����ǰһ�����ֵ 
				ans[a[i].id]=ans[a[i-1].id];		
			else
				ans[a[i].id]=query(a[i].x);		//���򿴵�ǰ��֮ǰ����ߣ��ĵ㣨���ȵ�ǰ��ߣ��ĺͣ������� 
			add(a[i].x,1);			//���µ�ǰ�㣨������x,����1�� 
		}
		for(int i=0;i<n;i++){ 
			if(i) printf(" ");
			printf("%d",ans[i]);
		}
		cout<<endl;
	}
	return 0;
}

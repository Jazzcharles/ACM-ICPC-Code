#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int num[50001];
struct node
{
	//int left, right;		//由于在creat、add和count函数中，每一个树节点的区间都被当作了参数，随着递归的深入，左右区间边界也会进去。所以无需在每个节点再存left和right
	int sum;
};
node t[200001];
void creat(int x, int left, int right)
{
	if (left == right)		//单节点区间
	{
		t[x].sum = num[left];
		return;
	}
	creat(x * 2, left, (left + right) / 2);		//左半区间
	creat(x * 2 + 1, (left + right) / 2 + 1, right);		//右半区间
	t[x].sum = t[x * 2].sum + t[x * 2 + 1].sum;
}
void add(int x, int left, int right, int lb, int rb, int q)
{
	if (left == lb && right == rb)		//找到要修改的节点
	{
		t[x].sum += q;
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
		
	t[x].sum = t[x * 2].sum + t[x * 2 + 1].sum;		//子区间的值发生变化，上一层区间的值也要变化
}
int count(int x, int left, int right, int lb, int rb)
{
	if (left == lb && right == rb)		//要求的左右边界与当前搜索到的区间完全吻合
		return t[x].sum;
	if (rb <= (left + right) / 2)		//要求的左右边界全部在当前区间的左半部分
		return count(x * 2, left, (left + right) / 2, lb, rb);
	else if (lb > (left + right) / 2)		//要求的左右边界全部在当前区间的右半部分
		return count(x * 2 + 1, (left + right) / 2 + 1, right, lb, rb);
	else		//要求的左右边界在当前区间的左右两半部分都有涉及，要切分开来计算
		return count(x * 2, left, (left + right) / 2, lb, (left + right) / 2) + count(x * 2 + 1, (left + right) / 2 + 1, right, (left + right) / 2 + 1, rb);
}
int main(void)
{
	int i, j;
	int T;
	int n;
	char op[10];
	int t1, t2;
	scanf("%d", &T);
	for (i = 1; i <= T; i++)
	{
		scanf("%d", &n);
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &num[j]);
		}
		creat(1, 1, n);
		printf("Case %d:\n", i);
		while (1)
		{
			scanf("%s", op);
			if (op[0] == 'E')
			{
				break;
			}
			else if (op[0] == 'A')
			{
				scanf("%d %d", &t1, &t2);
				add(1, 1, n, t1,t1, t2);
			}
			else if (op[0] == 'S')
			{
				scanf("%d %d", &t1, &t2);
				add(1, 1, n, t1,t1, -t2);		//减少t2个士兵就相当于增加-t2个士兵
			}
			else if (op[0] == 'Q')
			{
				scanf("%d %d", &t1, &t2);
				printf("%d\n", count(1, 1, n, t1, t2));
			}
		}
	}
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int num[50001];
struct node
{
	//int left, right;		//������creat��add��count�����У�ÿһ�����ڵ�����䶼�������˲��������ŵݹ�����룬��������߽�Ҳ���ȥ������������ÿ���ڵ��ٴ�left��right
	int sum;
};
node t[200001];
void creat(int x, int left, int right)
{
	if (left == right)		//���ڵ�����
	{
		t[x].sum = num[left];
		return;
	}
	creat(x * 2, left, (left + right) / 2);		//�������
	creat(x * 2 + 1, (left + right) / 2 + 1, right);		//�Ұ�����
	t[x].sum = t[x * 2].sum + t[x * 2 + 1].sum;
}
void add(int x, int left, int right, int lb, int rb, int q)
{
	if (left == lb && right == rb)		//�ҵ�Ҫ�޸ĵĽڵ�
	{
		t[x].sum += q;
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
		
	t[x].sum = t[x * 2].sum + t[x * 2 + 1].sum;		//�������ֵ�����仯����һ�������ֵҲҪ�仯
}
int count(int x, int left, int right, int lb, int rb)
{
	if (left == lb && right == rb)		//Ҫ������ұ߽��뵱ǰ��������������ȫ�Ǻ�
		return t[x].sum;
	if (rb <= (left + right) / 2)		//Ҫ������ұ߽�ȫ���ڵ�ǰ�������벿��
		return count(x * 2, left, (left + right) / 2, lb, rb);
	else if (lb > (left + right) / 2)		//Ҫ������ұ߽�ȫ���ڵ�ǰ������Ұ벿��
		return count(x * 2 + 1, (left + right) / 2 + 1, right, lb, rb);
	else		//Ҫ������ұ߽��ڵ�ǰ������������벿�ֶ����漰��Ҫ�зֿ�������
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
				add(1, 1, n, t1,t1, -t2);		//����t2��ʿ�����൱������-t2��ʿ��
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

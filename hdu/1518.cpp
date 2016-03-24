#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
const int MAXN = 1e5+5;
int save[MAXN];
bool used[MAXN];
int sum,l,n,flag;
void Dfs(int now, int len, int index)//now:第几条边  len:该边现在组成的长度 index:用来优化时间
{
    if (now > 4)
    {
        flag = 1;
        return ;
    }
    if (len == sum)
    {
        Dfs(now + 1, 0, 0);
        if (flag)//优化时间
        {
            return ;
        }
    }
    for (int i = index; i < n; i++)//从index开始优化时间
    {
        if (!used[i] && save[i] + len <= sum)
        {
            used[i] = 1;
            Dfs(now, save[i] + len, i + 1);
            if (flag)//优化时间
            {
                return;
            }
            used[i] = 0;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {        
        sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", save + i);
            sum += save[i];
        }        
        if (sum % 4 != 0)//简答的优化
        {
            puts("no");
            continue;
        }
        sum = sum / 4;
		flag = 0;
        for (int i = 0; i < n; i++)//有比边长大的边就不行
        {
            if (save[i] > sum)
            {
                flag=1;break;
            }
        }
        if (flag)
        {
            puts("no");
            continue;
        }
        memset(used, 0, sizeof(used));
        Dfs(1, 0, 0);
        if (flag) puts("yes");
        else puts("no");
    }
    return 0;
}

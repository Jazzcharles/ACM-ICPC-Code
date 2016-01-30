#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
int a[100010];
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    	scanf("%d",&a[i]);
    sort(a,a+n);
    printf("%d",a[n-k]);
    return 0;
}

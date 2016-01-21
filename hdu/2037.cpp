#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
PII a[105];
int cmp(PII x,PII y)
{
	return (x.second==y.second)?(x.first<y.first):(x.second<y.second);
}
int main(int argc, char** argv) {
	int n;
	while(~scanf("%d",&n) && n)	
	{
		int cnt=1;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].first,&a[i].second);
	//		printf("%d %d\n",a[i].first,a[i].second);
		}
		sort(a,a+n,cmp);
	/*	for(int i=0;i<n;i++)
		{
			printf("%d %d\n",a[i].first,a[i].second);
		}	
	*/	int temp=a[0].second;
		for(int i=1;i<n;i++)
		{
			if(a[i].first>=temp)
			{
				cnt++;
				temp=a[i].second;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

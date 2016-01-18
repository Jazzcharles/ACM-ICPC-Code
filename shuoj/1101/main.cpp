#include<stdio.h>
#include<iostream>
using namespace std;
int f(int a)
{
	int i,sum=0;
	for(i=2;i<a;i++)
	if(a%i==0) sum=sum+i;
	return sum;
} 
int main()
{ 
	int i,j,k,flag[3000]={0};
	for(i=2;i<3000;i++)
	{
		int s=f(f(i));
			if((i==s) && (!flag[s]))
			{
				flag[i]=flag[f(i)]=1;
				printf("(%d,%d)",i,f(i));	
			}
	}
	
	getchar();
	return 0;
}


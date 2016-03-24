#include<stdio.h>
#include<iostream>
using namespace std;
char s[105][105];
int sum=0;
int n,m,cnt=0;
void dfs(int a,int b){
	s[a][b]='.';
    for(int x=-1;x<=1 ;x++)
		for(int y=-1;y<=1 ;y++)
			{
			int ax=a+x;
		    int by=b+y;
			if(ax>=0 && ax<n && by>=0 && by<m && s[ax][by]=='W')
				dfs(ax,by);
		}

	return ;
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>s[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='W')
	           { dfs(i,j);	
				 cnt++;}
	cout<<cnt<<endl;
	
	
	return 0;
}

#include<iostream>
#include<string.h>
using namespace std;
int N;
int value[200];
int dp[200][200];
int max(int a,int b){return a>b?a:b;}

void init()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>value[i];
        value[N+i]=value[i];
    }
    memset(dp,0,sizeof(dp));
}

int maxValue(int start,int end)
{
    int pauseMaxvalue;
    if(dp[start][end]!=0)
    {
        pauseMaxvalue=dp[start][end];
    }
    else if(start==end)
    {
        pauseMaxvalue=dp[start][end];
    }else if(start+1==end)
    {
        pauseMaxvalue=value[start]*value[end]*value[end+1];
    }
    else
    {
        pauseMaxvalue=0;
        for(int k=start;k<end;k++)
        {
            int leftvalue=maxValue(start,k);
            int rightvalue=maxValue(k+1,end);
            int totalvalue=leftvalue+rightvalue+value[start]*value[k+1]*value[end+1];
            pauseMaxvalue=max(pauseMaxvalue,totalvalue);
        }
    }
    dp[start][end]=pauseMaxvalue;
    return pauseMaxvalue;
}

void show()
{
    int MAX=0;
    for(int i=0;i<N;i++)
    {
        MAX=max(MAX,maxValue(i,N+i-1));
    }
    cout<<MAX<<endl;
}
int main()
{
    init();
    show();
    return 0;
}

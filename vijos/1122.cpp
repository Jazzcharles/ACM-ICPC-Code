#include <iostream>
using namespace std;
int dp[20];
int main()
{
    int n;
    cin>>n;
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=n;i++)
       for(int j=0;j<i;j++)
          dp[i]+=dp[j]*dp[i-j-1];
          cout<<dp[n]<<endl;
    return 0;
}

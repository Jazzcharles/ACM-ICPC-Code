#include <bits/stdc++.h>
using namespace std;
#define max(a,b) (a>b)?a:b

int Max(int a,int b,int c){
     return max(max(a,b),c);
} 
int a[80][80],dp[80][80]; 
int main(int argc, char** argv) {
    int n;
    while(cin>>n && n){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<2*i+1;j++){
                scanf("%d",&a[i][j]);
            }
        }
        dp[0][0]=a[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<2*i+1;j++){
                if(j==0) dp[i][j]=dp[i-1][j]+a[i][j];
                else if(j==1) dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i-1][j-1]+a[i][j]);
                else if(j==2*i) dp[i][j]=max(dp[i-1][j-1]+a[i][j],dp[i-1][j-2]+a[i][j]);
                else if(j==2*i+1) dp[i][j]=dp[i-1][j-2]+a[i][j];
                else dp[i][j]=Max(a[i][j]+dp[i-1][j],a[i][j]+dp[i-1][j-1],a[i][j]+dp[i-1][j-2]);
                cout<<dp[i][j]<<' ';
            }
//          cout<<endl;
        }
        int ans=0;
        for(int j=0;j<2*n+1;j++)
           ans=max(ans,dp[n-1][j]);
        cout<<ans<<endl;
    }
     
    return 0;
}

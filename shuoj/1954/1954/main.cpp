#include <iostream>
#include <cstring>
using namespace std;
int dp[1000][1000][4];
char a[1000][1000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%s",a[i]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                if(a[i][j]=='x') continue;
                if(a[i][j-1]=='.') dp[i][j][0]=dp[i][j-1][0]+1;
                if(i>0 && a[i-1][j]=='.') dp[i][j][2]=dp[i-1][j][2]+1;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(a[i][j]=='x') continue;
                if(a[i][j+1]=='.') dp[i][j][1]=dp[i][j+1][1]+1;
                if(i<n-1 && a[i+1][j]=='.') dp[i][j][3]=dp[i+1][j][3]+1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='x') continue;
                int cnt=0;
                for(int k=0;k<4;k++){
                    cnt+=dp[i][j][k];
                }
                ans=max(ans,cnt);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

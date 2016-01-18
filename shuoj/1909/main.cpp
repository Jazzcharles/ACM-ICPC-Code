#include <bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
int dp[5][9],dir[4][2]={{-2,-2},{2,-2},{-2,2},{2,2}};
int main(int argc, char** argv) {
	int sx,sy,tx,ty;
	while(scanf("%d%d%d%d",&sx,&sy,&tx,&ty)!=EOF){
		memset(dp,0,sizeof(dp));
		dp[sx][sy]=-1;
		if(sx+2<=4 && sy+2<=8) dp[sx+2][sy+2]=-1;
		if(sx+2<=4 && sy-2>=0) dp[sx+2][sy-2]=-1; 
		if(sx-2>=0 && sy-2>=0) dp[sx-2][sy-2]=-1;
		if(sx-2>=0 && sy+2<=8) dp[sx-2][sy+2]=-1;
		for(int i=0;i<=4;i++){
			if(dp[i][0]==-1){
				dp[i][0]=0;break;
			}
			else
				dp[i][0]=1;
		}
		for(int j=0;j<=8;j++){
			if(dp[0][j]==-1){
				dp[0][j]=0;break;
			}
			else
				dp[0][j]=1;
		}
	/*	for(int i=0;i<5;i++)
		{
			for(int j=0;j<9;j++){
				cout<<dp[i][j]<<' ';
			}cout<<endl;
		}
*/
		for(int i=0;i<5;i++){
			for(int j=0;j<9;j++){
				if(dp[i][j]==-1)
					dp[i][j]=0;
				else if(i>0 && j>0)
					dp[i][j]=dp[i-1][j]+dp[i][j-1];
//				cout<<dp[i][j]<<' ';
			}
//			cout<<endl;
		}
		cout<<dp[tx][ty]<<endl;
	}
	return 0;
}

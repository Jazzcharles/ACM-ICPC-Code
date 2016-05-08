#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>L;X--)
#define DEP2(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

char a[1005],temp[1005];
char s[1005][1005];
int dp[1005][1005],vis[1005][1005];
int num[1005];
//dp[i][j]:从第i块的第j位排在最后最小的和 
//dp[i][j]=min(dp[i-1][p,1<p<k]+num[i]-s[i][j]==s[i-1][p]) 
int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k;
		scanf("%d%s",&k,a);
		CLR(dp,INF);
		CLR(num,0);
		CLR(vis,0);
		int n=strlen(a)/k;
		REP(i,n){
			for(int j=i*k+1,cnt=0;j<=(i+1)*k-1;cnt++,j++){
				vis[i][a[j-1]]++;
				s[i][cnt]=a[j-1];
			}
			vis[i][a[(i+1)*k-1]]++;
			s[i][k-1]=a[(i+1)*k-1];
		}
		REP(i,n){
			CLR(temp,0);
			memcpy(temp,s[i],sizeof(temp));
			sort(temp,temp+k);
		//	puts(temp);
			num[i]=1;
			REP2(j,1,k-1){
				if(temp[j]!=temp[j-1]) {
					num[i]++;	
				}	
			}
		}
//		REP(i,n){
//			REP(j,k){
//				cout<<s[i][j];
//			}
//			cout<<endl;
//		}
//		REP(i,n) cout<<num[i]<<endl;
		REP(j,k) dp[0][j]=num[0];
		REP2(i,1,n){
			REP(j,k){
				char last=s[i][j];
				REP(p,k){
					char first=s[i-1][p];
					if(vis[i][first] && (first!=last || num[i]==1))
						dp[i][j]=min(dp[i][j],dp[i-1][p]+num[i]-1);
					else
						dp[i][j]=min(dp[i][j],dp[i-1][p]+num[i]);
				}	
			//	cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<dp[i-1][j]+num[i]<<' '<<(s[i][0]==s[i-1][j]?1:0)<<endl;
			}
		}
		int ans=INF;
		REP(j,k) ans=min(ans,dp[n-1][j]);
		printf("%d\n",ans);
	}
	return 0;
} 

/*
2
5 helloworld
7 thefewestflops
*/

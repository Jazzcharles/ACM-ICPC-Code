#include <bits/stdc++.h>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define EPS 1e-8
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define lowbit(i) (i&(-i))
#define IT iterator
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
#define pi 3.1415927
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int maxn=1e5+5;
const int mod=1e9+7;
const int B=1031;
const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int dp[100][100];
string a[100],b[100],c;
int main(int argc, char** argv) {
	int t;
	cin>>t;
	int ca=0;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n,i,j,m;
		cin>>n>>m;
		getchar();
		REP(i,n){
			cin>>a[i];
		}
	//	REP(i,n)
	//	   cout<<a[i]<<' ';
	//	cout<<endl;
		REP(i,m){
			cin>>b[i];
		}
	//	REP(i,n)
	//	   cout<<b[i]<<' ';
	//	cout<<endl;
	    for(int i = 0; i < n; i++) {  
            for(int j = 0; j < m; j++) {  
               if(a[i] == b[j]) {  
                 if(i > 0 && j > 0) dp[i][j] = dp[i-1][j-1] + 1;  
                 else dp[i][j] = 1;  
               }  
               if(i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);  
               if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);  
             }  
        }   
		cout<<"Case "<<++ca<<endl;
		cout<<dp[n-1][m-1]<<endl;    
	}
	return 0;
}


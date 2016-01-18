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

int a[12][12],i,j;

void output(int n)
{
    for(i=0;i<n;i++)
    {
        a[i][i]=1;
        a[i][0]=1;
    }
 

    for(i=2;i<n;i++)
    {
        for(j=1;j<i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    }
     

    for(i=n-1;i>=0;i--)
    {

        for(int k=0;k<=n-1-i;k++)
            cout<<setw(2)<<"";
         

        for(j=0;j<=i;j++)
            cout<<a[i][j]<<setw(4);
        cout<<endl;
    }
}
int main(){
	int n;
	while(cin>>n){
		output(n);
	}
}

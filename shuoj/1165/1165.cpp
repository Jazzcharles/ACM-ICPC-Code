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

int a[50][50];
string b[10];
void output(int n){
	a[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++)
		{
			if(!j || j==i) a[i][j]=1;
			else if(i>=1 && j>=1)a[i][j]=a[i-1][j]+a[i-1][j-1];
		}		
	}
	for(int i=0;i<n;i++){
	   for(int j=0;j<n-i-1;j++){
	       	b[i]+=' ';
	   }
	   b[i]+='1';
	   for(int j=1;j<=i;j++){
	   	  b[i]+=' ';
	   	  if(a[i][j]<=9)
	   	     b[i]+=(a[i][j]+'0');
	   	  else if(a[i][j]<=99){
	   	  	 b[i]+=(a[i][j]/10+'0');
	   	  	 b[i]+=(a[i][j]%10+'0');
		  }
		  else{
		  	 b[i]+=(a[i][j]/100+'0');
		  	 b[i]+=(a[i][j]/10%10+'0');
		  	 b[i]+=(a[i][j]%10+'0');
		  }
	   	     
	   }  
	}
	  
	for(int i=n-1;i>=0;i--){
		cout<<b[i]<<endl;
	}
	
	
	
	
/*	REP(i,n){
		REP2(j,0,i){
	       cout<<a[i][j]<<' ';	    
	  }
	  cout<<endl;
	}
*/	  
	
	
	
	
	
	
}




int main(int argc, char** argv) {
	int n;
	while(cin>>n){
		
		output(n);
		REP(i,n)
		   b[i]=""; 
	}
	
	return 0;
}





#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int maxn=1e5+5;
const int mod=1e9+7;
const int B=1031;


int a2[5]={6,2,4,8,6};
int a3[5]={1,3,9,7,1};
int a7[5]={1,7,9,3,1};
int a8[5]={6,8,4,2,6};
int main(int argc, char** argv) {
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n%10==1 || n%10==5 || n%10==6 || n%10==9){
			printf("%d\n",n%10);continue;
		}
		else if(n%10==4)
		    printf("6\n");
		else if(n%10==2){
		    printf("%d\n",a2[n%4]);
		}
		else if(n%10==3){
		    printf("%d\n",a3[n%4]);
		}
		else if(n%10==7){
		    printf("%d\n",a7[n%4]);
		}
		else if(n%10==8){
		    printf("%d\n",a8[n%4]);
		}
		else if(n%10==0){
			printf("0\n");
		}
	}
	
	
	
	
	
	return 0;
}

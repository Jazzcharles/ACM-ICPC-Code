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
const int NUM=121; 
 
 
ll a[150],b[150],c[150]; 
 
void Multi()
{
    memset(c, 0, sizeof(c));
    REP(i,NUM)
    {
        for(int j=0;j+i<NUM;j++) 
        {
            c[i+j]+=a[i]*b[j];
        }
    }
}

void cnt()
{
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    REP(i,NUM) a[i]=1;
    REP2(j,2,NUM)
    {
        memset(b, 0, sizeof(b));
        for(int i=0;i<=NUM;i+=j)
        {
            b[i] = 1;
        }
        Multi();    
        memcpy(a,c,sizeof(c));
    }
}


int main(){
	int n;
	cnt();
	while(cin>>n){
		cout<<c[n]<<endl;
	}
	return 0;
}

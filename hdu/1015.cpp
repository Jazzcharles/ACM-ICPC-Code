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

char ch[100];
int  visit[1000];
int flag, len, N;
char str[150];

void dfs(int n,int sum){
	 int j, t;
     
     if (flag)
         return;
         
     if ( sum == N && n == 5) {
           puts(ch);
           flag = 1;
           return ;
     }
     else {
         for(j = len - 1;  j >= 0; j--){
             if ( !visit[j] ) {
                 visit[j] = 1;
             t = str[j] - 'A' + 1;
             if (n == 0) {
                 ch[n] = str[j];
                 dfs(n + 1, sum + t);
             }
             else if ( n == 1) {
                 ch[n] = str[j];
                 dfs(n + 1, sum - t  * t);
             }
             else if ( n == 2) {
                 ch[n] = str[j];
                 dfs( n + 1,sum + t * t * t);
             }
             else if ( n == 3) {
                ch[n] = str[j];
                 dfs (n + 1,sum - t * t * t  *  t) ;
             }
             else if ( n == 4) {
                 ch[n] = str[j];
                 dfs (n + 1,sum + t * t * t  *  t * t);
             }
             visit[j] = 0;
             }
        }
     }
}
int main(int argc, char** argv) {
	while(~scanf("%d%s",&N,str)!=EOF){
		if(N==0 && !strcmp(str,"END"))
		  break;
		memset(visit, 0, sizeof(visit));
    len = strlen(str), flag = 0;
	sort(str, str + len);
	dfs(0,0);
	if(!flag)
	   puts("no solution");
	}
	return 0;
}

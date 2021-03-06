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


priority_queue<int,VI,greater<int> >q;
int main(int argc, char** argv) {
	int n;
	cin>>n;
		REP(i,n){
			int x;
			scanf("%d",&x);
			q.push(x);
		}
        int ans=0;
		while(!q.empty()){
			int a=q.top();
			q.pop();
			if(q.empty())
			  break;
			int b=q.top();
			q.pop();
			ans+=a+b;
			q.push(a+b);
	//		cout<<ans<<' ';
		}
	//	cout<<endl;
		printf("%I64d\n",ans);	
	

	return 0;
}

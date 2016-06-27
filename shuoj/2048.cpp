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
const int maxn=1e5+5;

int main(){
	int a,b,c,ca=1;
	char ch,op;
	string s;
	while(~scanf("%d %c %d = %d",&a,&op,&b,&c))
	{
		printf("Case %d: ",ca++);
		if(op=='+' && a+b==c) 
			cout<<"Yes"<<endl;
		else if(op=='-' && a-b==c)
			cout<<"Yes"<<endl;
		else if(op=='*' && a*b==c)
			cout<<"Yes"<<endl;
		else if(op=='/' && a/b==c && a%b==0)
			cout<<"Yes"<<endl;
		else 
			cout<<"No"<<endl;
		 
	}
	return 0;
}

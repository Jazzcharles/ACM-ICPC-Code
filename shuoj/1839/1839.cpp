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
const string base="0123456789";

int main(int argc, char** argv) {
	string a,b,s;
	while(cin>>a>>b){
		bool cnt=0;
		int lena=a.length()-1;
		int lenb=b.length()-1;
		while(lena>=0 || lenb>=0){
			int temp=0;
			if(lena>=0) 
			  temp+=a[lena]-'0';
			if(lenb>=0)
			  temp+=b[lenb]-'0';
			temp+=cnt;
//			cout<<temp<<endl;
			cnt=temp/10;
			s+=base[temp%10];
			lena--;lenb--;
		}
		if(cnt) s+=base[cnt];
		reverse(s.begin(),s.end());
		cout<<a<<'+'<<b<<'='<<s<<endl;
		s.clear();
	}
	return 0;
}

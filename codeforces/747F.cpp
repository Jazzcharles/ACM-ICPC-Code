#include<bits/stdc++.h>
using namespace std;

int dp[10][20];
//dp[i][j]:长度为i以j开头的interesting数字 

int main(){
	int k,t;
	cin>>k>>t;
	for(int i=1;i<=10;i++){//i位数 
		for(int j=1;j<16;j++){//最高位是j 
			
		}
	} 
	
	
	
	
	return 0;
} 

/*
#include <stdio.h>
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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
#define rep2(X,L,R) for(int X=L;X<=R;X++)
#define dep(X,R,L) for(int X=R;X>=L;X--)
#define clr(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
typedef long long ll;
typedef  unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

int can[110];
ll C[170][11];
vector<ll> dp(170);
const ll maxx = 2e9 + 7;

ll DP(int n){
    for(int i = 0; i <= n; i++)dp[i] = 0;
    dp[0] = 1;
    for(int i = 0 ; i < 16 ; i ++){
        for(int len = n ; len >= 0; len --){
            for(int j = 1 ; j <= can[i]; j ++){
                dp[len + j] += dp[len] * min(maxx,C[len + j][j]);
                dp[len + j] = min(dp[len + j],maxx);
            }
        }
    }
    return dp[n];
}

void output(int p){
    if(p < 10)cout << p;
    else cout << char(p - 10 + 'a');
}

void dfs(int n,int p,ll k){
    output(p);
    if(!n){
        cout << endl;
        return;
    }
    for(int i = 0; i < 16 ; i ++){
        if(can[i] == 0)continue;
        can[i]--;
        ll cnt = DP(n - 1);
        if(cnt >= k){
            dfs(n - 1, i, k);
            return;
        }
        k -= cnt;
        can[i]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    ll k;
    int t;
    for(int i = 0 ; i < 170 ; i ++){
        C[i][0] = 1;
        for(int j = 1;  j <= min(i,10) ; j ++){
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] = min(C[i][j],maxx);
        }
    }
    
    cin >> k >> t;
    for(int i = 0 ; i < 16 ; i++){
        can[i] = t;
    }
    for(int len = 1 ; ; len ++){
        for(int i = 1; i < 16 ; i ++){
            can[i]--;
            ll cnt = DP(len - 1);
            if(cnt >= k){
                dfs(len - 1,i,k);
                return 0;
            }
            k-= cnt;
            can[i]++;
        }
    }
    
    
    return 0;
}
*/ 

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
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
 
 
int a[1000];
int main(){
        while(~scanf("%d",&a[0])){
            if(getchar()=='\n')
            {
                cout<<a[0]<<endl;
                continue;
            }               
            int i=0;
            while(1){
                scanf("%d",&a[++i]);
                if(getchar()=='\n')
                    break;
            }
            int n=i+1;
            REP(i,n)
              for(int j=i+1;j<n;j++)
                  if(a[i]==a[j])
                    {
                        for(int k=j;k<n-1;k++)
                         a[k]=a[k+1];
                          j--;n--;
                    }
            cout<<a[0];
            REP2(i,1,n-1)
              cout<<' '<<a[i];
            cout<<endl;
        }
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
    return 0;
}
 
 
 
 
 
 

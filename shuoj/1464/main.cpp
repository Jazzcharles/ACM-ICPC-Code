#include<bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef long long ll;
priority_queue<int,VI,greater<int> >q;
int main(int argc, char** argv) {
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            ll x;
            scanf("%lld",&x);
            q.push(x);
        }
        ll ans=0;
        while(!q.empty()){
            ll temp=q.top();
            q.pop();
            if(q.empty())
              break;
            temp+=q.top();
            q.pop();
            ans+=temp;
            q.push(temp);
    //      cout<<ans<<' ';
        }
    //  cout<<endl;
        printf("%lld\n",ans);     
    }
    return 0;
}

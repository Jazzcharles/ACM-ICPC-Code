#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4;
int a[maxn];
int main(int argc, char** argv) {
    int n,k;
    scanf("%d%d",&n,&k);
  //  multiset<int> s;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int max=-1;
    int money=0;
    int min=1e8;
    for(int i=a[0];i<=a[n-1];i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(a[j]>=i){
                cnt++;
            }
        }
        if(cnt>=k) 
        cnt=k;
		money=(i)*cnt;
	//	if(money==4) cout<<123<<endl;
        if(money>max)
        {
        max=money;
        min=i;
       
        }
       
    }
/*  int n,k;
    multiset<int> s;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            s.insert(a[i]);
    }
    sort(a,a+n);
    int t=0,ans;    
    for(int i=n-1;i>=0;i--){
        int num=s.count(a[i]);
        if(num<=k){
            if(t<=a[i]*num){
                ans=a[i];
                t=a[i]*num;
            }
        }
    }*/
    printf("%d %d\n",min,max);
    return 0;
}

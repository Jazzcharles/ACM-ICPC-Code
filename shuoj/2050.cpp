#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

int main(){
	int ca=1,n;
	while(cin>>n)
	{		
		int ans=n,cnt=1;
		if(getchar()=='\n') {printf("Case %d: %d, %d\n",ca++,cnt,ans);continue;	}
		while(cin>>n){
			ans+=n;cnt++;
			if(getchar()=='\n') break;			
		}
		printf("Case %d: %d, %d\n",ca++,cnt,ans);
	}
	return 0;
}

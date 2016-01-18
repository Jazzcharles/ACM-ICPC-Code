#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int n,ca=1,ans=0;
	char a[101];
	while(scanf("%d",&n)!=EOF){
		getchar();
		for(int i=0;i<n;i++){
			gets(a);int s=0;
			for(int j=0;a[j];j++){
				s+=a[j];
//				cout<<s<<endl;
			}
			ans=max(ans,s);
		}
		printf("Case %d: %d\n",ca++,ans);
	}
	return 0;
}

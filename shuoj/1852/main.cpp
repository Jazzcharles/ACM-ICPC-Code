#include <bits/stdc++.h>
using namespace std;
set<string>s;
char str[11];
int main(int argc, char** argv) {
	int n;
	ios::sync_with_stdio(false);
	while(~scanf("%d",&n))
	{
		getchar();
		s.clear();
		memset(str,0,sizeof(str));
		while(n--){
			scanf("%s",str);
			s.insert(str);	
		}
		printf("%d\n",s.size());
		for(set<string>::iterator it=s.begin();it!=s.end();it++){
			cout<<*it<<endl;
		}
	}

	return 0;
}

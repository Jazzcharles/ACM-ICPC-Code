#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--){
		int x,y,xx,yy,p,q,pp,qq;
		scanf("%d%d%d%d%d%d%d%d",&x,&y,&xx,&yy,&p,&q,&pp,&qq);
		double s1=sqrt((x-p)*(x-p)+(y-q)*(y-q))+sqrt((xx-p)*(xx-p)+(yy-q)*(yy-q));
		double s2=sqrt((x-pp)*(x-pp)+(y-qq)*(y-qq))+sqrt((xx-pp)*(xx-pp)+(yy-qq)*(yy-qq));
		printf("%.3f\n",min(s1,s2));
	}
	
	
	return 0;
}

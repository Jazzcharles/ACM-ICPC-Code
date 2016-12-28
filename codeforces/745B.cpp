#include<bits/stdc++.h>
using namespace std;


char s[1000][1000];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	int minx=n,miny=m,maxx=0,maxy=0,tot=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='X'){
				tot++;
				minx=min(minx,i);
				miny=min(miny,j);
				maxx=max(maxx,i);
				maxy=max(maxy,j); 
			}
		}
	}
	int ans=abs(maxx-minx+1)*abs(maxy-miny+1);
	if(tot==ans) puts("YES");
	else puts("NO");
	
	
	
	
	return 0;
}
/*
2 3
XXX
XXX

2 2
.X
XX

5 5
.....
..X..
.....
.....
.....

*/

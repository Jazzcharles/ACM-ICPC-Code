#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int main() {
	int n,ca=1;
	cin>>n;
	while(n--){
		for(int i=0;i<9;++i)
			for(int j=0;j<=i;++j)
				scanf("%d",&a[i][j]);
		set<int> s[15][15];
		s[0][0].insert(a[0][0]);
		for(int i=1;i<9;i++){
			for(int j=0;j<=i;j++){
				if(!j){
					if(s[i-1][j].count(a[i][j])==0){
						s[i][j]=s[i-1][j];
						s[i][j].insert(a[i][j]);
					}
					else s[i][j].clear();	
				} 
				else if(j==i){
					if(s[i-1][j-1].count(a[i][j])==0){
						s[i][j]=s[i-1][j-1];
						s[i][j].insert(a[i][j]);
					}
					else s[i][j].clear();
				}
				else{
					if(s[i-1][j].count(a[i][j])==0 && s[i-1][j-1].count(a[i][j])==0){
						if(s[i-1][j].size()>s[i-1][j-1].size())
							s[i][j]=s[i-1][j];
						else s[i][j]=s[i-1][j-1];
						s[i][j].insert(a[i][j]);
					}
					else if(s[i-1][j-1].count(a[i][j])==0){
						s[i][j]=s[i-1][j-1];
						s[i][j].insert(a[i][j]);
					}
					else if(s[i-1][j].count(a[i][j])==0){
						s[i][j]=s[i-1][j];
						s[i][j].insert(a[i][j]);
					}
					else 
						s[i][j].clear();
				}	
									
			}
		}
/*		for(set<int>:: iterator it=s[6][4].begin();it!=s[6][4].end();it++){
			cout<<*it<<' ';
		}
*/
		int flag=0;
		for(int i=0;i<9;i++){
			if(s[8][i].size()==9){
				flag=1;break;
			}	
//			cout<<s[8][i].size()<<' ';
		}
//		cout<<endl;
		cout<<"Case "<<ca++<<":"<<endl;
		if(flag) cout<<"Possible"<<endl;
		else cout<<"Impossible"<<endl;
	}
	return 0;
}

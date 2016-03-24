#include<iostream>
using namespace std;
int dir[8][2]={-1,2,-1,-2,1,2,1,-2,2,1,2,-1,-2,1,-2,-1};
bool ok(int x,int y){
	if(x>=0 && y>=0 && x<8 && y<8) return 1;
	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int x=s[0]-'a',y=s[1]-'1';
		int ans=0;
		for(int i=0;i<8;i++){
			int xx=x+dir[i][0];
			int yy=y+dir[i][1];
			if(ok(xx,yy)) ans++;
		}
		cout<<ans<<endl; 
	}
	
	return 0;
} 

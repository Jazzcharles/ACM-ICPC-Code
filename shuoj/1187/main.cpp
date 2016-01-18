#include <iostream>
using namespace std;
int dir[8][2]={1,2,1,-2,2,-1,2,1,-1,2,-1,-2,-2,1,-2,-1};
bool ok(int x,int y){
	if(x<0 || x>=8 || y<0 || y>=8) return 0;
	return 1;
}
int main(int argc, char** argv) {
	int n;
	cin>>n;
	getchar();
	while(n--)
	{
		char ch[2];
		gets(ch);
		int cnt=0;
		int sx=tolower(ch[0])-'a',sy=ch[1]-'0'-1;
		//cout<<sx<<' '<<sy<<endl;
		for(int i=0;i<8;i++){
			int xx=sx+dir[i][0],yy=sy+dir[i][1];
			if(ok(xx,yy))
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}

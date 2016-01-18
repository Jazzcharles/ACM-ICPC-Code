#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=1005;
int phi[MAXN];
void eular(int m,int n){
 for(int i = 0; i<=m;i++) phi[i] = 1;
 for(int i = 2; i<=m;i++)
    for(int j = i;j<=m;j+=i)
    	if(phi[j])	phi[j] = 0;
    	else phi[j]=1;
}
int main(int argc, char** argv) {
	int n,m;
	while(~scanf("%d%d",&m,&n)) 
	{
		int cnt=0;
		memset(phi,0,sizeof(phi));
		for(int i=2;i<=n;i++){
			for(int j=i;j<=m;j+=i){
				if(!phi[j]) phi[j]=1;
				else phi[j]=0;
			}
		}
		for(int i=1;i<=m;i++){
			if(!phi[i]) cnt++;
	//		cout<<phi[i]<<' ';
		}
		cout<<cnt<<endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn=500;
const int mod=1000007;
typedef long long ll;
long long dp[410][410];
int n,m,k;
void init()
{
	for(int i=0;i<410;i++){
		for(int j=i;j<410;j++){
			if(i==j || i==0) dp[i][j]=1%mod;
			else dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%mod;
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		}
	}
}
int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	init();
//	cout<<dp[2][6]<<endl;
	while(t--){
		scanf("%d%d%d",&m,&n,&k);
		if(k>m*n || k<2){
			printf("0\n");continue;
		}
		ll ans=dp[k][m*n]; 
        //AUBUCUD=A+B+C+D-AB-AC-AD-BC-BD-CD+ABC+ABD+BCD+ACD-ABCD
	
		ll a=dp[k][(m-1)*n],b=a,c=dp[k][m*(n-1)],d=c;
		ans=(ans-a-b-c-d+mod)%mod;
		while(ans<0) ans+=mod; 
//		cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	
     	ll ab=dp[k][(m-2)*n],ac=dp[k][(m-1)*(n-1)],ad=ac,bc=ac,bd=ac,cd=dp[k][m*(n-2)];
//      cout<<ab<<' '<<ac<<' '<<ad<<' '<<bc<<' '<<bd<<' '<<cd<<endl;
     	ans=(ans+ab+ac+ad+bc+bd+cd)%mod;	
	
	
		ll abc=dp[k][(m-2)*(n-1)],abd=abc,bcd=dp[k][(m-1)*(n-2)],acd=bcd;
//		cout<<abc<<' '<<abd<<' '<<bcd<<' '<<acd<<endl;
		ans=(ans-abc-abd-bcd-acd+mod)%mod;
		while(ans<0) ans+=mod;	
	
	
		ll abcd=dp[k][(m-2)*(n-2)];
//		cout<<abcd<<endl;
		ans=(ans+abcd)%mod; 
		
		printf("%d\n",ans);			
	}
	return 0;
}

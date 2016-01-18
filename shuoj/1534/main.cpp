#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN=1005;
LL gcd(LL a,LL b){
	if(!b) return a;
	else return gcd(b,a%b);
}
LL fpow(int a,int b){
	LL t=1;
	for(;b;b>>=1,a=a*a){
		if(b&1) t*=a;
	}
	return t;
}
int phi[MAXN];
void eular(){
 for(int i = 0; i<MAXN;i++) phi[i] = 1;
 for(int i = 2; i<MAXN;i++)
	 if(phi[i] == 1)
 	 for(int j = i;j<MAXN;j+=i)
 		phi[j] = 0;
}
int main(int argc, char** argv) {
	LL a,b;
	eular();
	while(~scanf("%d%d",&a,&b))
	{
		if((phi[b]==b && phi[a]==a) || a==1||b==1){
			printf("1\n");continue;
		}
		if(!(b%a)){
            printf("%d\n",a);continue;
		}



		printf("%lld\n",gcd(a,fpow(b,b)));
	}
	return 0;
}

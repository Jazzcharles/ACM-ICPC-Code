#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=1e6+10;
int phi[MAXN];
void eular(){
 	for(int i = 0; i<MAXN;i++) phi[i] = i;
 	for(int i = 2; i<MAXN;i++)
 		if(phi[i] == i)
 			for(int j = i;j<MAXN;j+=i)
 				phi[j] = phi[j] / i * (i-1);
}

int a[MAXN];

void init(){
	for(int i=2;i<=MAXN;i++){
		ll ans=phi[i];
		a[ans]=min(a[ans],i);
	}
//	cout<<a[7]<<' '<<a[8]<<endl;
//	for(int i=2;i<=20;i++) cout<<i<<' '<<a[i]<<endl;
	int Max=0;
	for(int i=2;i<=MAXN;i++){
		if(a[i]==INF) 
			Max=max(Max,phi[i]);
	} 
	//cout<<Max<<endl;
	for(int i=Max;i>=1;i--){
		if(a[i]>Max) a[i]=Max;
		else Max=a[i];
	}
//	for(int i=2;i<=20;i++) cout<<i<<' '<<a[i]<<endl;
}
int b[10005];
int main(){
	memset(a,INF,sizeof(a));
	eular();
//	cout<<phi[7]<<endl;
	init();
//	for(int i=2;i<=100;i++){
//		cout<<i<<' '<<a[i]<<endl;
//	}
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		memset(b,0,sizeof(b));
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}
		ll sum=0;
		for(int i=0;i<n;i++){
			sum+=a[b[i]];
		}
		printf("Case %d: %lld Xukha",ca++,sum);
	}

	return 0;
}

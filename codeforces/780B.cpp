#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define eps 1e-7
#define MAX 1e9
using namespace std;
const int maxn = 1e5+500;
int n;
double x[maxn],v[maxn];

bool ok(double t){//lb,rbµ±Ç°×óÓÒ±ß½ç 
	double lb =max(1.0,x[0]-t*v[0]);
	double rb =min(MAX,x[0]+t*v[0]);
	//cout<<lb<<' '<<rb<<endl; 
	for(int i = 1; i < n ; i++){
		double l = max(1.0,x[i]-t*v[i]);
		double r = min(MAX,x[i]+t*v[i]);
		//cout<<l<<' '<<r<<endl;
		if(l > rb || r < lb) return 0;
		lb = max(l,lb);
		rb = min(r,rb);
	} 
	return 1;
}
int main(){
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>x[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin>>v[i];
	}
	double ans = 1e9;
	double l = 0, r = 1e9;
	//ok(1.396);
	while((r-l)>eps){
		double mid = (l+r)/2;
		bool f = ok(mid);
		//cout<<l<<' '<<r<<' '<<mid<<' '<<f<<endl;
		if(f){
			ans = mid;
			r = mid;
		}
		else{
			l = mid;
		}
	}
	printf("%7f\n",ans);
	
	return 0;
}
/*
3
7 1 3
1 2 1


4
5 10 3 2
2 3 2 4

5
1 15 61 29 43
15 11 19 19 19

*/

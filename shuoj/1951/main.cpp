#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> PII;
const int maxn=1e5+5;
PII a[maxn],b[maxn];
int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,sum=0,step=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&a[i].X,&a[i].Y);
			step+=a[i].Y/k*a[i].X*2;
			a[i].Y%=k;
		}
		sort(a+1,a+1+n);
		int temp=0;		
//		for(int i=n;i>=1;i--){
//				cout<<a[i].X<<' '<<a[i].Y;
//				cout<<endl;
//		}				
		int i=n;
		while(i>0)
		{
					while(a[i].Y>0){
						step+=a[i].X*2;
						a[i].Y-=k;
					}
					if(a[i].Y<=0){
						a[i-1].Y+=a[i].Y;
			//			step+=a[i].X*2;
						i--;
					}	
					if(!i) break;
			//		cout<<step<<endl;
		}
		cout<<step<<endl;
	}
	return 0;
}

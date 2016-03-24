#include<iostream>
#include<cstring>
using namespace std;
int x[1000],y[1000];
bool ok(int x1,int y1,int x2,int y2){
	return (x1*y2-x2*y1)>0;
}
int main()
{
	int n;
	while(cin>>n&&n)	
	{
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i]; 
		}
		x[n]=x[0];y[n]=y[0];
		x[n+1]=x[1];y[n+1]=y[1];
		int f;
		if((x[1]-x[0])*(y[2]-y[1])-(x[2]-x[1])*(y[1]-y[0])) f=0;
		for(int i=1;i<=n-1;i++){
			if(!ok(x[i]-x[i+1],y[i]-y[i+1],x[i+1]-x[i+2],y[i+1]-y[i+2]))
				f=1;
		} 
		//if((x[1]-x[0])*(y[2]-y[1])-(x[2]-x[1])*(y[1]-y[0])) f=0;
		if(f) cout<<"concave"<<endl;
		else cout<<"convex"<<endl;
	}
	
	return 0;
} 

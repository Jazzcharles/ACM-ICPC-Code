#include<iostream>
#include<cmath>
using namespace std;
int x[1000],y[1000];
int cp(int x1,int y1,int x2,int y2){
	return x1*y2-x2*y1; 
}
int main(){
	int n;
	while(cin>>n && n)
	{
		for(int i=0;i<n;i++)
			cin>>x[i]>>y[i];	
		int s=0;
		for(int i=1;i<n-1;i++){
			s+=cp(x[i]-x[0],y[i]-y[0],x[i+1]-x[0],y[i+1]-y[0]);
		}
		printf("%.1f\n",1.0*abs(s)/2);
	}

	return 0; 
} 

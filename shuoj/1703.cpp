#include<iostream>
#include<cmath>
#define eps 1e-5
#define pi 3.1415926535897932384626
using namespace std;
double x[1005],y[1005];
double arc(double x0,double y0,double x1,double y1,double x2,double y2){
	double a=(x0-x1)*(x0-x1)+(y0-y1)*(y0-y1);
	double b=(x0-x2)*(x0-x2)+(y0-y2)*(y0-y2);
	double c=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
	return (a+b-c)/(2*sqrt(a)*sqrt(b));
}
int main(){
	int n,ca=1;
	while(cin>>n)
	{
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i];
		}
		x[n]=x[0],y[n]=y[0];
		double s=0,ss=0;
		double xx,yy,angle=0;
		cin>>xx>>yy;
		for(int i=0;i<n;i++){
			//s+=cp(xx-x[i],yy-y[i],xx-x[i+1],yy-y[i+1]);
			//ss+=fabs(cp(xx-x[i],yy-y[i],xx-x[i+1],yy-y[i+1]));		
			angle+=acos(arc(xx,yy,x[i],y[i],x[i+1],y[i+1]));
		}	
	//	s=fabs(s);
		int f=0;
		for(int i=0;i<n;i++){
			if(xx==x[i] && yy==y[i]) f=1;
		}
	//	cout<<ss<<' '<<s<<endl;
	//	cout<<angle<<endl; 
		cout<<"Case "<<ca++<<":"<<endl;
		if(fabs(angle-2*pi)<=eps && !f) cout<<"Yes!"<<endl;
		else cout<<"No!"<<endl;
	}
	
	return 0;
} 

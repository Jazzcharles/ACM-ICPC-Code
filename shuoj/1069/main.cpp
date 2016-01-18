#include <bits/stdc++.h>
using namespace std;
const int maxn=5001;
double dis(double a,double b,double c,double d,double e,double f){
	return sqrt((a-d)*(a-d)+(b-e)*(b-e)+(c-f)*(c-f));
}
struct node{
	double x,y,z;
}a[maxn];
int main(int argc, char** argv) {
	int n,j;
	double sx,sy,sz,tx,ty,tz;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
	}
	scanf("%lf%lf%lf%lf%lf%lf",&sx,&sy,&sz,&tx,&ty,&tz);
	sx=1.0/2*(sx+tx);sy=1.0/2*(sy+ty);sz=1.0/2*(sz+tz);
//	cout<<tx<<' '<<ty<<' '<<tz<<endl;
	double min=dis(a[0].x,a[0].y,a[0].z,sx,sy,sz);
	for(int i=1;i<n;i++){
		if(dis(a[i].x,a[i].y,a[i].z,sx,sy,sz)<min){
			j=i;
			min=dis(a[i].x,a[i].y,a[i].z,sx,sy,sz);
		}
	}
	printf("%.3f %.3f %.3f\n",a[j].x,a[j].y,a[j].z);
	return 0;	
}

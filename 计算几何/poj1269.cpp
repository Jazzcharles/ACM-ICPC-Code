#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
const int maxn = 100;
const double eps = 1e-8;


int sgn(double x){
	if(fabs(x) < eps) return 0;
	if(x<0) return -1;
	return 1;
}

struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
};

struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)    
    {
        s = _s;e = _e;
    }
    
    pair<int,Point> operator & (const Line &b) const
	{
		Point res = s;
		//cout<<(s-e).x<<' '<<(s-e).y<<' '<<(b.s-b.e).x<<' '<<(b.s-b.e).y<<endl;
		//cout<< ((s-e) ^ (b.s-b.e))<<endl;
		if(sgn((s-e) ^ (b.s-b.e)) == 0){
			if(sgn((s-b.e) ^ (b.s-e))== 0) 
				return make_pair(0,res);
			else return make_pair(1,res);
		}
		double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
		res.x+=(e.x - s.x)*t;
		res.y+=(e.y - s.y)*t;
		return make_pair(2,res); 
	} 
};


int main(){
	int n;
	cin>>n;
	cout<<"INTERSECTING LINES OUTPUT"<<endl;
	for(int i=0;i<n;i++){
		double x[4],y[4];
		for(int j=0;j<4;j++){
			cin>>x[j]>>y[j];
		}
		Point p[4];
		for(int j=0;j<4;j++){
			p[j] = Point(x[j],y[j]);
		}
		Line L1 = Line(p[0],p[1]);
		Line L2 = Line(p[2],p[3]);
		pair<int,Point> ans = L1 & L2;
		int k = ans.first;
		
		if(k == 1) puts("NONE");
		else if(k == 0) puts("LINE");
		else{
			printf("POINT %.2f %.2f\n",ans.second.x,ans.second.y);
		} 
	}
	cout<<"END OF OUTPUT"<<endl;
	
	
	return 0;
}
/*
5
0 0 4 4 0 4 4 0
5 0 7 6 1 0 2 3
5 0 7 6 3 -6 4 -3
2 0 2 27 1 5 18 5
0 3 4 0 1 2 2 5
*/

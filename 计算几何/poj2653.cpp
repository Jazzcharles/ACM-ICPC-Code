#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1e5+500;
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

bool inter(Line l1,Line l2)
{
	return
	max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
	max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
	max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
	max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
	sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
	sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
} 

//*Á½µã¼ä¾àÀë
double dist(Point a,Point b)
{
	return sqrt((a-b)*(a-b));
}


vector<int> v;
int n;
Line li[maxn];


int main(){
	while(~scanf("%d",&n))
	{
		if(!n) break;
		v.clear();
		for(int i=0;i<n;i++){
			Point s,e;
			scanf("%lf%lf%lf%lf",&s.x,&s.y,&e.x,&e.y);
			li[i] = Line(s,e);		
		}
		for(int i=n-1;i>=0 && v.size()<=1000;i--){
			int flag = 0;
			for(int j=i+1;j<n;j++){
				if(inter(li[i],li[j])) {
					flag = 1;
					break;
				}
			}
			if(!flag) v.push_back(i);
		}
		printf("Top sticks: ");
		for(int i=v.size()-1;i>=0;i--){
			if(i) printf("%d, ",v[i]+1);
			else printf("%d.\n",v[i]+1);
		}
	}
	
	
	return 0;
}
/*

5
1 1 4 2
2 3 3 1
1 -2.0 8 4
1 4 8 2
3 3 6 -2.0
3
0 0 1 1
1 0 2 1
2 0 3 1
0

*/

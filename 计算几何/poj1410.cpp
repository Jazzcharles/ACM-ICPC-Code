#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

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


//*两点间距离
	double dist(Point a,Point b)
	{
		return sqrt((a-b)*(a-b));
	}

//*判断线段相交
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

bool check(Point l,Point r,Point cur){
	int minx = min(l.x,r.x), maxx = max(l.x,r.x);
	int miny = min(l.y,r.y), maxy = max(l.y,r.y);
	if(cur.x >= minx && cur.x <= maxx && cur.y >= miny && cur.y <= maxy) return 1;
	return 0;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int flag = 0;
		Point s,e;
		cin>>s.x>>s.y>>e.x>>e.y;
		Line line = Line(s,e);
		int dir[2][2];
		for(int i=0;i<2;i++) 
			for(int j=0;j<2;j++) 
				cin>>dir[i][j];
		Line l[4];
		Point p1 = Point(dir[0][0],dir[0][1]);
		Point p2 = Point(dir[0][0],dir[1][1]);
		Point p3 = Point(dir[1][0],dir[0][1]);
		Point p4 = Point(dir[1][0],dir[1][1]);
		l[0] = Line(p1,p2);
		l[1] = Line(p1,p3);
		l[2] = Line(p2,p4);
		l[3] = Line(p3,p4);
		if(check(p1,p4,s)) flag = 1;
		if(check(p1,p4,e)) flag = 1;
		
		
		for(int i=0;i<4;i++){
			if(inter(l[i],line)) flag = 1;
		}		
		if(flag) cout<<"T"<<endl;
		else cout<<"F"<<endl;
		
	}
	
	
	
	
	
	
	return 0;
} 
/*
1
4 4 3 3 1 5 7 1
*/

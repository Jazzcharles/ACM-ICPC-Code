#include<iostream>
#include<cmath>
#include<cstring>

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

Line li[1000];
int n;

//判断直线和线段相交
bool Seg_inter_line(Line l1,Line l2) //判断直线l1和线段l2是否相交
{
	return sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0;
} 

//*两点间距离
double dist(Point a,Point b)
{
	return sqrt((a-b)*(a-b));
}


bool judge(Point p,Point q){
	if(sgn(dist(p,q)) == 0) return 0;
	Line tmp = Line(p,q);
	for(int i=0;i<n;i++){
		if(!Seg_inter_line(tmp,li[i]))	return 0;	
	}
	return 1;
}


int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			Point a,b;
			cin>>a.x>>a.y>>b.x>>b.y;
			li[i] = Line(a,b);	
		}
		int flag = 0;
		for(int i=0;i<n;i++){
			Point p[4] ;
			p[0] = li[i].s;
			p[1] = li[i].e;
			if(flag) break;
			for(int j=0;j<n;j++){
				p[2] = li[j].s;
				p[3] = li[j].e;
				bool ok = false;
				for(int u = 0; u < 4;u++){
					for(int v = u+1;v<4;v++){
						ok = ok || judge(p[u],p[v]); 
					}
				}
				if(ok) {
					flag = 1;
					break;
				}
			}
		}
		if(flag) cout<<"Yes!"<<endl;
		else cout<<"No!"<<endl;
	}
	
	
	
	
	return 0;
} 
/*
3
2
1.0 2.0 3.0 4.0
4.0 5.0 6.0 7.0
3
0.0 0.0 0.0 1.0
0.0 1.0 0.0 2.0
1.0 1.0 2.0 1.0
3
0.0 0.0 0.0 1.0
0.0 2.0 0.0 3.0
1.0 1.0 2.0 1.0
*/

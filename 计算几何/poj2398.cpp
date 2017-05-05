#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e5;

int res[maxn];
int tot[maxn];
struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y)
    {
        x = _x;y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
    int operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
    int operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
}p[maxn];

struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)    
    {
        s = _s;e = _e;
    }
}li[maxn];

int cmp(Line l1,Line l2){
	Point s1 = l1.s;
	Point e1 = l1.e;
	Point s2 = l2.s;
	Point e2 = l2.e;
	int x1 = min(s1.x,e1.x);
	int x2 = min(s2.x,e2.x);
	return x1<x2; 
}
//直线两端点n1,n2 当前点n0 ,1右边，0左边 

int cross(Line L,Point p0){
	Point p1 = L.s;
	Point p2 = L.e;
	if (((p1-p0)^(p2-p0))>=0) return 1;
	return 0;
}


int main(){
	int n,m,x1,x2,y1,y2;
	while(cin>>n){
		if(n==0) break;
		cin>>m>>x1>>y1>>x2>>y2;
		memset(res,0,sizeof(res));
		memset(tot,0,sizeof(tot));
		for(int i=1;i<=n;i++) {
			int x1,x2;
			cin>>x1>>x2;
			Point p1(x1,y1),p2(x2,y2); 
			li[i]=Line(p1,p2); 
		}
		sort(li+1,li+1+n,cmp);
		for(int i=0;i<m;i++) cin>>p[i].x>>p[i].y;
		for(int i=0;i<m;i++){
			int l=0,r=n,ans=0;
			while(l<=r){
				int mid = (l+r)>>1;
				bool f = cross(li[mid],p[i]);
				//cout<<l<<' '<<r<<' '<<mid<<' '<<f<<endl;
				if(f) ans=mid,l=mid+1;
				else r=mid-1;
			}
			res[ans]++;
		}
		for(int i=0;i<=n;i++){
			tot[res[i]]++;
			//cout<<i<<": "<<res[i]<<endl;
		}
		cout<<"Box"<<endl;
		for(int i=1;i<=m;i++){
			if(tot[i]) cout<<i<<": "<<tot[i]<<endl;
		}
		//cout<<endl;
	}
	
	
	
	
	
	return 0;
} 
/*
4 10 0 10 100 0
20 20
80 80
60 60
40 40
5 10
15 10
95 10
25 10
65 10
75 10
35 10
45 10
55 10
85 10
5 6 0 10 60 0
4 3
15 30
3 1
6 8
10 10
2 1
2 8
1 5
5 5
40 10
7 9
0

*/

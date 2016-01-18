#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int a,b,c;double det,ans;
	while(cin>>a>>b>>c){
		det=sqrt(b*b-4*a*c);
		double x=((-b)+det)/(2*a),y=((-b)-det)/(2*a);
		if(x<y) swap(x,y);
		printf("%.2f %.2f\n",x,y);
	}
	return 0;
}

#include <iostream>
#include <cmath> 
using namespace std;

int main(int argc, char** argv) {
	int a,b,c;
	cin>>a>>b>>c;
	double x1=(-b-sqrt(b*b-4*a*c))/2/a;
	double x2=(-b+sqrt(b*b-4*a*c))/2/a;
	printf("%.2f %.2f",x2,x1);
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {
	double x1,x2,y1,y2;
	while(cin>>x1>>y1>>x2>>y2){
		printf("%.2f\n",sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
	}	
	return 0;
}

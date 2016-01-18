#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int y;
	while(cin>>y){
		if(y%400==0 || (y%100!=0 && y%4==0))
			printf("The year %d is a leap year.\n",y);
		else
			printf("The year %d is not a leap year.\n",y);
	}
	return 0;
}

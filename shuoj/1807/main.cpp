#include <iostream>
using namespace std;

bool LeapYear(int y)  
{  
    if (y%400 == 0 || (y%100 != 0 && y%4 ==0))  
        return 1;  
    return 0;  
}  
int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--){
		int y,m,d;
		scanf("%d-%d-%d",&y,&m,&d);
		if(y<0 || m>=13 || d>31){
			cout<<-1<<endl;continue;
		}
		if(m==4|| m==6|| m==9 || m==11 && d>30){
			cout<<-1<<endl;continue;
		}
		if(m==2 && d>=29){
			cout<<-1<<endl;continue;
		}
		int sum=0;
		for(int i=y+1;i<=y+18;i++){
			if(LeapYear(i))
				sum+=366;
			else sum+=365;
		}
		if(LeapYear(y) && m<=2)  
            sum++;  
        if (LeapYear(y+18) && m<=2)  
            sum--;  
		cout<<sum<<endl;
	}
	return 0;
}

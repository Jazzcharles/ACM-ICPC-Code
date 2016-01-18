#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n;
	while(~scanf("%d",&n))
	{
		
		int s,sum=0,score=0,p;
		double aver;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&s,&p);
			if(p==-1) continue;
			else if(p<=100 && p>=90) p=4;
			else if(p>=80 && p<=89) p=3;
			else if(p>=70 && p<=79) p=2;
			else if(p>=60 && p<=69) p=1;
			else p=0;
			sum+=p*s,score+=s;
		}
		aver=1.0*sum/score;
		printf("%.2f\n",aver);
	}
	return 0;
}

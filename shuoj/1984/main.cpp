#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,a,b,m,f=0;
		scanf("%d%d%d",&a,&b,&m);
		if(m>=a && m>=b){
			for(i=m/a;i>=0;i--){
				for(j=0;j<=m/b;j++){
				
					if(i*a+j*b==m){
					f=1;break;
					}
				}
				if(f) break;
			} 
			if(f) printf("%d %d\n",i,j);
			else printf("Impossible\n");
		}
		else if(m<a && m<b){
			printf("Impossible\n");
		} 
		else if(m<a && m>b){
			if(m%b==0) printf("%d %d\n",0,m/b);
			else printf("Impossible\n");
		}
		else if(m>a && m<b){
			if(m%a==0) printf("%d %d\n",m/a,0);
			else printf("Impossible\n");
		}
	}
	return 0;
}

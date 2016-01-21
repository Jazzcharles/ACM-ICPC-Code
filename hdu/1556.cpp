#include <iostream>
#include <cstring>
#define lowbit(i) (i&(-i))
using namespace std;
const int maxn=1e5+5;
int bit[maxn],a[maxn],n;
void add(int i,int x){
	while(i<=maxn){
		bit[i]+=x;
//		cout<<i<<' '<<bit[i]<<endl;
		i+=lowbit(i);
	
	}
}
int query(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=lowbit(i);
	}
	return s;
}
int main(int argc, char** argv) {
	while(~scanf("%d",&n) && n){
		memset(bit,0,sizeof(bit));
		int a,b;
		for(int i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			add(a,1);
			add(b+1,-1);
		}	
		for(int i=0;i<n;i++){
			if(i) putchar(' ');
			printf("%d",query(i+1));
		}
		cout<<endl;
		
		
	}
	return 0;
}

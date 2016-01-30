#include<iostream>
#define lowbit(i) (i&(-i))
using namespace std;
const int maxn=1e5+5;
int bitl[maxn],bitr[maxn];
int query(int *a,int i)
{
	int s=0;
	while(i>0)
	{
		s+=a[i];
		i-=lowbit(i);
	}
	return s;
}

void add(int *a,int i)
{
	while(i<=maxn)
	{
		a[i]++;
		i+=lowbit(i);
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int q,l,r;
		cin>>q>>l>>r;
		if(q==1){
			add(bitl,l);
			add(bitr,r);
		}
		else{
			cout<<query(bitl,r)-query(bitr,l-1)<<endl;
		}
	}
	
	return 0;
}














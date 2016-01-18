//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
using namespace std;
#define max(a,b) (a>b?a:b)

int main(){
	int l,r;
	while(scanf("%d%d",&l,&r)!=EOF)
	{
		printf("%d %d ",l,r);
		if(l>r) swap(l,r);
		int ans=-1;
		for(int i=l;i<=r;i++){
			int cnt=1,j=i;
			while(j-1){
				if(j%2) j=j*3+1;
				else j/=2;
				cnt++;
   //  			cout<<j<<endl;
			}
			ans=max(ans,cnt);
		}
	    printf("%d\n",ans);
	}
	
	
}

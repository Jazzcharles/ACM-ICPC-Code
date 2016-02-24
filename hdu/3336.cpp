#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+5;
const int mod=10007;
int Next[maxn],leno,lens,cnt;
char opt[maxn];
void get_next ()
{  
    int j = 0, k = -1;  
    Next[0] = -1;  
    while (j < leno)  
    {  
        if (k == -1 || opt[j] == opt[k])  
        {  
            j++, k++;  
            Next[j] = k;  
        }  
        else k = Next[k];  
    }  
}  
int main(){
	ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(Next,0,sizeof(Next));
		scanf("%d%s",&leno,opt);
		get_next();
		int ans=leno+Next[leno];
		for(int i=1;i<leno;i++){
	//		cout<<Next[i]<<' ';
			if(Next[i+1]!=Next[i]+1){
				ans+=Next[i]%mod;
			}
		}
		printf("%d\n",ans%mod);
	}
	
	return 0;
}

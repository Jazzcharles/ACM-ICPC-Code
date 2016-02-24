#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+5;
int Next[maxn],leno,lens;
int opt[maxn],str[maxn];
void getnext()
{
    Next[0]=-1;
    int i=0,j=-1;
    while(i<lens)
    {
        if(j==-1 || opt[i]==opt[j])
        {
            i++;
            j++;
            if(opt[i]==opt[j])
            	Next[i]=Next[j];
            else
            	Next[i]=j;
        }
        else
            j=Next[j];
    }
}

int kmp()
{
	int i=0,j=0;
	getnext();
	while(i<lens && j<leno)
	{
		if(j==-1 || str[i]==opt[j])
			i++,j++;
		else
			j=Next[j];
		if(j==leno)
			return i-j+1;
	}
	return -1;
}

int main(){
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&lens,&leno);
		char ch;
		for(int i=0;i<lens;i++){
			scanf("%d",&str[i]);
		}
		for(int i=0;i<leno;i++){
			scanf("%d",&opt[i]);
		}
		printf("%d\n",kmp());
	}
	
	return 0;
}

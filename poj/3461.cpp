#include<iostream>
#include<cstdio>
using namespace std;
#include<cstring>
const int maxn=1e6+5;
int cnt,Next[maxn],leno,lens;
char opt[maxn],str[maxn];
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
		if(j==leno){
		//	cout<<123<<' '<<i<<endl;
			cnt++;
			j=Next[j];
		}
			
	}
	return cnt;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%s",opt);
		scanf("%s",str);
		lens=strlen(str);
		leno=strlen(opt);
		printf("%d\n",kmp());
	}
	
	return 0;
}

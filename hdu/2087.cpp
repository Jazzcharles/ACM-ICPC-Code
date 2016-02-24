#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+5;
int Next[maxn],leno,lens,cnt;
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
			cnt++;
			j=0;	
		}
	}
	return cnt;
}
int main(){
	while(~scanf("%s",str))
	{
		cnt=0;
		if(str[0]=='#') break;
		scanf("%s",opt);
		lens=strlen(str);leno=strlen(opt);
		//cout<<str<<endl<<opt<<endl;
		printf("%d\n",kmp());
	}
	return 0;
}

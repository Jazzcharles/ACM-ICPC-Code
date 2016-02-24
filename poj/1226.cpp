#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e2+5;
int Next[maxn],leno,lens,cnt;
string opt,str,a[maxn];
void get_next ()
{  
    int j = 0, k = -1;  
    Next[0] = -1;  //1ºÅ 
    while (j < leno)  
    {  
        if (k == -1 || opt[j] == opt[k])  
        {  
            j++, k++;  
            Next[j] = k;  
        }  
        else k = Next[k]; //2ºÅ 
    }  
}  

int kmp()
{
	int i=0,j=0,ans=0,len=0;
	get_next();
	while(i<lens && j<leno)
	{
		if(j==-1 || str[i]==opt[j])
			len++,i++,j++; //3ºÅ
		else{
			ans=max(ans,len);
			j=Next[j];
			len=0;
		}
		if(j==leno)
			return ans;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false); //4ºÅ
	int t;
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) 
			cin>>a[i];
		
	}
	
	
	
	
	return 0;
}


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+5;
const int mod=10007;
int Next[maxn],leno,lens,cnt,nxt[maxn];
string opt,str;
void get_Next ()
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

void get_nxt(){
	int j = 0, k = -1;  
    nxt[0] = -1;  
    while (j < lens)  
    {  
        if (k == -1 || str[j] == str[k])  
        {  
            j++, k++;  
            nxt[j] = k;  
        }  
        else k = nxt[k];  
    }  
}
int main(){
	ios::sync_with_stdio(false);
	string a,b;
	while(cin>>a>>b)
	{
		memset(Next,0,sizeof(Next));
		memset(nxt,0,sizeof(nxt));
		opt=b+a;
		leno=opt.length();
		get_Next();
		//for(int i=0;i<=leno;i++) cout<<Next[i]<<' ';cout<<endl;
		string ans1=a;
		for(int i=Next[leno];i<b.length();i++){
			 ans1+=b[i]; 
		}
		str=a+b;
		lens=str.length();
		get_nxt();
		string ans2=b;
		for(int i=nxt[lens];i<a.length();i++){
			ans2+=a[i];
		}
		if(ans1.length()<ans2.length()) cout<<ans1<<endl;
		else if(ans2.length()<ans1.length()) cout<<ans2<<endl;
		else cout<<min(ans1,ans2)<<endl;
	}
	return 0;
}

//sdfgasdf 000000123

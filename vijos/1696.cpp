#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll a[1005];

ll gcd(ll a,ll b){
	if(!b) return a;
	else return gcd(b,a%b);
}
int main()
{
	string s;
	while(getline(cin,s)){
		memset(a,0,sizeof(a));
		if(s[0]=='['){
			int temp=0,j=0,n=0;
			for(int i=1;i<s.length();i++){
				if(isdigit(s[i]))
					temp=temp*10+s[i]-'0';
				else{
					if(temp){
						a[++n]=temp;temp=0;	
					}
				}
			}
		    //for(int i=0;i<n;i++) cout<<a[i]<<' ';
			ll up=0,down=0;
			for(int i=n;i>=1;i--){
				if(i==n){
					up=a[i]*a[i-1]+1;down=a[i];
					i--;
				}
				else{
					up=a[i]*down+up;
				}
				if(i!=1) swap(up,down);
			}
			if(down==1) cout<<up<<endl;
			else cout<<up/gcd(up,down)<<"/"<<down/gcd(up,down)<<endl;
		}
		else{
			ll up=0,down=0,loc,j=0;
			for(int i=0;i<s.length();i++){
				if(s[i]=='/') loc=i;
			}
			for(int i=0;i<s.length();i++){
				if(i<loc) up=up*10+s[i]-'0';
				else if(i>loc) down=down*10+s[i]-'0'; 
			}
			ll tmp=up;
			up=up/gcd(up,down);down=down/gcd(tmp,down);
			while(up&&down){
				ll temp=up/down;
				a[j++]=temp;
				up-=temp*down;
				swap(up,down);
			}
			//if(j==1) cout<<a[0]<<endl;
			//else{
				cout<<"[";
				for(int i=0;i<j;i++){
					cout<<a[i];
					if(!i && j>1) cout<<";";
					else if(i!=j-1 && j>1) cout<<","; 
				}			
				cout<<"]"<<endl;				
			//}

		}
	}
	
	return 0;
}

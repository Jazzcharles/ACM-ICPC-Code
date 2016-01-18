#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
string a,b;
int main(int argc, char** argv) {
	while(getline(cin,a))
	{
		getline(cin,b);
		string c="";
		int lena=a.length(),lenb=b.length(),ans=0;
		if(lena<=lenb){
			for(int i=0;i<=lena;i++){
				c+=a[i];
				int temp=b.find(c),lenc=c.length();	
		//		cout<<c<<' '<<' '<<lenc<<endl;
				if(temp==string :: npos) break;
				ans=max(ans,lenc);
			}	
		}
		else{
			for(int i=0;i<=lenb;i++){
				c+=b[i];
				int temp=a.find(c),lenc=c.length();	
		//		cout<<c<<' '<<' '<<lenc<<endl;
				if(temp==string :: npos) break;
				ans=max(ans,lenc);
			}
		}
		printf("%d\n",ans);
		getchar();
	}
	return 0;
}

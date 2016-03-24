/*
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int maxn=1e5+5;
char a[maxn][25];
int w,l;
int main(){
	int n=0;
	char s[maxn];
	while(cin>>a[n++]) ;
	//cout<<n<<endl;
	int len=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<strlen(a[i]);j++){
			if(a[i][j]=='E') break;
				s[len++]=a[i][j]; 			
		}
	}
	//cout<<s<<endl;
	for(int i=0;i<len;i++){
	//	cout<<w<<' '<<l<<endl;
		if(s[i]=='W') w++;
		if(s[i]=='L') l++;
		if(w>=11 && w-l>=2){
			cout<<w<<":"<<l<<endl;
			w=0;l=0;
		}
		if(l>=11 && l-w>=2){
			cout<<w<<":"<<l<<endl;
			w=0;l=0;
		}
	}
	if(w||l) cout<<w<<":"<<l<<endl;
	else cout<<"0:0"<<endl;
	cout<<endl;
	w=0;l=0;
	for(int i=0;i<len;i++){
	//	cout<<w<<' '<<l<<endl;
		if(s[i]=='W') w++;
		if(s[i]=='L') l++;
		if(w>=21 && w-l>=2){
			cout<<w<<":"<<l<<endl;
			w=0;l=0;
		}
		if(l>=21 && l-w>=2){
			cout<<w<<":"<<l<<endl;
			w=0;l=0;
		}
	}
	if(w||l) cout<<w<<":"<<l<<endl;
	else cout<<"0:0"<<endl;
	return 0;
}
*/
#include <iostream> 
#include <cstdlib>

using namespace std;

int a[10000] = {}, b[10000] = {};
int main(){
	char c;
	int W = 0, L = 0, W2 = 0, L2 = 0;
	int js = 0;
	while(cin >> c){
		if(c == 'E'){
			break;
		}
		if(c == 'W'){
			++W,++W2;
		}
		if(c == 'L'){
			++L,++L2;
		}
		if((W >= 11 || L >= 11) && abs(W - L) > 1){
			cout << W << ":" << L << endl;
			W = L = 0;
		}
		if((W2 >= 21 || L2 >= 21) && abs(W2 - L2) > 1){
			a[js] = W2, b[js++] = L2;
			W2 = L2 = 0;
		}
	}
	cout << W << ":" << L << endl << endl;
	for(int i = 0; i < js; ++i){
		cout << a[i] << ':' << b[i] << endl;
	}
	cout << W2 << ':' << L2;
	return 0;
}


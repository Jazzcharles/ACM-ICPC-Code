#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		for(int i=0;i<s.length();i++){
			if(isdigit(s[i])) cout<<s[i];
			if(isalpha(s[i])){
				if(s[i]=='a' || s[i]=='A' ||s[i]=='b' || s[i]=='B' ||s[i]=='c' || s[i]=='C')
					cout<<2;
				if(s[i]=='d' || s[i]=='D' ||s[i]=='e' || s[i]=='E' ||s[i]=='f' || s[i]=='F')
					cout<<3;
				if(s[i]=='g' || s[i]=='G' ||s[i]=='h' || s[i]=='H' ||s[i]=='i' || s[i]=='I')
					cout<<4;
				if(s[i]=='j' || s[i]=='J' ||s[i]=='k' || s[i]=='K' ||s[i]=='l' || s[i]=='L')
					cout<<5;
				if(s[i]=='m' || s[i]=='M' ||s[i]=='n' || s[i]=='N' ||s[i]=='o' || s[i]=='O')
					cout<<6;
				if(s[i]=='p' || s[i]=='P' ||s[i]=='q' || s[i]=='Q' ||s[i]=='R' || s[i]=='r' || s[i]=='s' || s[i]=='S')
					cout<<7;
				if(s[i]=='v' || s[i]=='V' ||s[i]=='t' || s[i]=='T' ||s[i]=='u' || s[i]=='U')
					cout<<8;
				if(s[i]=='X' || s[i]=='x' ||s[i]=='w' || s[i]=='W' ||s[i]=='y' || s[i]=='Y' || s[i]=='z' || s[i]=='Z')
					cout<<9;
			}
			if(i==3) cout<<"-";
		}
		cout<<endl;
	}
	
	return 0;
}

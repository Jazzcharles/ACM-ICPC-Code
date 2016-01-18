#include <bits/stdc++.h>
using namespace std;

string add(string str1,string str2)
{
    string str;
    int len1=str1.length();
    int len2=str2.length();
    if(len1<len2)
    {
        for(int i=1;i<=len2-len1;i++)
           str1="0"+str1;
    }
    else
    {
        for(int i=1;i<=len1-len2;i++)
           str2="0"+str2;
    }
    len1=str1.length();
    int cf=0;
    int temp;
    for(int i=len1-1;i>=0;i--)
    {
        temp=str1[i]-'0'+str2[i]-'0'+cf;
        cf=temp/10;
        temp%=10;
        str=char(temp+'0')+str;
    }
    if(cf!=0)  str=char(cf+'0')+str;
    return str;
}

string mult(string str1,string str2){
	string str,tempstr;
	int len1=str1.length();
	int len2=str2.length();
	for(int i=len2-1;i>=0;i--){
		int temp=str2[i]-'0',t=0,up=0;
		tempstr="";
		if(temp)
		{
			for(int j=1;j<=len2-1-i;j++){
				tempstr+="0";
			}	
			for(int j=len1-1;j>=0;j--){
				t=char(temp*(str1[j]-'0')+up)%10;
				up=char(temp*(str1[j]-'0')+up)/10;
				tempstr=char(t+'0')+tempstr;
			}
			if(up) tempstr=char(up+'0')+tempstr;
		}
		str=add(str,tempstr);
	}
	str.erase(0,str.find_first_not_of('0'));
	return str;
}
int main(int argc, char** argv) {
	string a,b;
	while(cin>>a>>b){
		cout<<a<<"*"<<b<<"="<<mult(a,b)<<endl;
	}
	return 0;
}

#include<iostream>
#include<map>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		map<string,map<string,int> >m;
		map<string,map<string,int> > :: iterator it;
		while(n--){
			string fru,loc;int num;
			cin>>fru>>loc>>num;
			m[loc][fru]+=num;
		} 
		for(it=m.begin();it!=m.end();it++){
			cout<<it->first<<endl;
			map<string,int>mm=it->second;
			for(map<string,int> :: iterator itt=mm.begin();itt!=mm.end();itt++){
				cout<<"   "<<"|----"<<itt->first<<"("<<mm[itt->first]<<")"<<endl;				
			}
		}
	}
	return 0;
}	


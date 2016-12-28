#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+500;
char str[maxn];
vector<string> v[maxn];

int ans,len,cur;
void dfs(int num,int depth){
	if(!num){
		ans=max(ans,depth);
		return ;
	}
	//cout<<num<<' '<<depth<<endl;
		for(int i=0;i<num && cur<len;i++){
			string temp;
			while(cur<len && str[cur]!=',')
				temp+=str[cur++];
			v[depth].push_back(temp);
			cur++;
			int nn=0;
			while(cur<len && str[cur]!=',')
				nn=nn*10+str[cur++]-'0';
			cur++;	
	//		cout<<temp<<' '<<nn<<' '<<depth<<endl;
			
			dfs(nn,depth+1);
	//	cout<<"debug 666666"<<endl;	
	}

}


int main(){
	scanf("%s",str);
	int flag=1;
	ans=0;
	cur=0;
	len=strlen(str);
	while(cur<len){
		dfs(1,0);		
	}
	cout<<ans<<endl;
	for(int i=0;i<ans;i++){
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<' ';
		}
		cout<<endl;
	}
	//cout<<ans<<endl;
	return 0;
}
/*
hello,2,ok,0,bye,0,test,0,one,1,two,2,a,0,b,0

a,5,A,0,a,0,A,0,a,0,A,0
*/

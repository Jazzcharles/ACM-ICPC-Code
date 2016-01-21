
#include<iostream>
#include<map>
#include<string> 
using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n)&&n)
	{
		map<string,int> m;
		string str;
		for(int i=0;i<n;i++){
			cin>>str;
			m[str]++;
		}
		int ans=0;
		string index;
		for(map<string,int> :: iterator it=m.begin();it!=m.end();it++){
			if(it->second>ans){
				ans=it->second;
				index=it->first;
			}
		}
		cout<<m.count(index)<<endl;
		cout<<index<<endl;
	}

	return 0; 
}
/*  
#include <iostream>
#include <string>
#include <map>
using namespace std;
  
int main()
{
    multimap<string,int> m_map;
    string s("def"),s1("abc");
    m_map.insert(make_pair(s,55));
    m_map.insert(make_pair(s,50));
    m_map.insert(make_pair(s,60));
    m_map.insert(make_pair(s1,30));
    m_map.insert(make_pair(s1,20));
    m_map.insert(make_pair(s1,10));
    //方式1
    int k;
    multimap<string,int>::iterator m;
    m = m_map.find(s);
    for(k = 0;k != m_map.count(s);k++,m++)
        cout<<m->first<<"--"<<m->second<<endl;
    //方式2
    multimap<string,int>::iterator beg,end;
    beg = m_map.lower_bound(s1);
    end = m_map.upper_bound(s1);
    for(m = beg;m != end;m++)
        cout<<m->first<<"--"<<m->second<<endl;
    for(m=m_map.begin();m!=m_map.end();m++){
    	cout<<m->first<<','<<m->second<<endl; 
	}
	cout<<m_map.find("def")<<endl; 
    return 0;
}
*/

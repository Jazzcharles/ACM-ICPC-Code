#include <iostream>
#include <stack>
using namespace std;
const int maxn=1e5;
int a[maxn];
int main(int argc, char** argv) {
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		stack<int> s;
		int ans=a[0];
		for(int i=0;i<n;i++){
			int num=a[i];
			if(s.empty() || num>a[s.top()]){
				s.push(num);
				i++;
			}
			else{
				int width,index=s.top();
				s.pop();
				if(!s.empty())
					width=i-s.top()-1;
				else
					width=i;
				ans=max(ans,width*a[index]);
			}
		}
		cout<<ans<<endl;
	}


	return 0;
}

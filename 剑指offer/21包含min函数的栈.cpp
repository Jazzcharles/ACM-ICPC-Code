#include<bits/stdc++.h>
using namespace std;

//ά��һ����ԭstack S��ͬ��Ŀ��stack MIN��ά��S����Сֵ 
int main(){
	stack<int> s;
	stack<int> mi;
	int n;
	cin>>n;
	int small = -0x3f;
	for(int i = 0 ; i < n ; i++)
	{
		int x;
		cin>>x;
		small = min(x,small);
		s.push(x);
		mi.push(small);
	}	
	
	
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;       
int STACK[maxn],top=0;          
bool InStack[maxn];          
int DFN[maxn];                 
int Low[maxn];                
int ComponetNumber=0;        
int Index=0;                 
vector <int> Edge[maxn];       
vector <int> Component[maxn]; 

void Tarjan(int u)
{
    int v;
    DFN[u]=Low[u]=Index++;
    InStack[u]=true;
    STACK[++top]=u;
    for (int e=0;e<Edge[u].size();e++)
    {
        v=Edge[u][e];
        if (DFN[v]==-1)
        {
            Tarjan(v);
            Low[u]=min(Low[u],Low[v]);
        }
        else if (InStack[v])
            Low[u]=min(Low[u],DFN[v]);
    }
    if (DFN[u]==Low[u])
    {
  /* 		v=STACK[top];
    	if(u!=v){
 			top--;
 			cout<<u<<endl;
		}
		else{
			ComponetNumber++;
			while(u!=v){ 
		 		v=STACK[top--];
		 		InStack[v]=false;
		 		Component[ComponetNumber].push_back(v);
		 		cout<<v<<endl;
			}
		}
    */     int cnt=0;
        do
        {
        	cnt++;
            v=STACK[top--];
            InStack[v]=false;
            Component[ComponetNumber].push_back(v);
           // cout<<v<<endl;
        }
        while (u!=v);
        if(cnt>1) ComponetNumber++;
 	   }
}

void init(){
	ComponetNumber=0;
    memset(STACK,-1,sizeof(STACK));
    memset(InStack,0,sizeof(InStack));
    memset(DFN,-1,sizeof(DFN));
    memset(Low,-1,sizeof(Low));
    memset(Edge,0,sizeof(Edge));
    memset(Component,0,sizeof(Component));
}
void solve(int n)  
{
    for(int i=0;i<n;i++)
        if(DFN[i]==-1)
            Tarjan(i);   
} 

int main(){
	int n,e;
	while(~scanf("%d%d",&n,&e))
	{
		init();
		for(int i=0;i<e;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			Edge[x].push_back(y);
		}
		solve(n);
		cout<<ComponetNumber<<endl;
	}
	return 0;
}

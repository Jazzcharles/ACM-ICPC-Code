#include <iostream>
#include <cstring>
#define lowbit(i) (i&(-i))
using namespace std;
int n,bit[1010][1010];
int query(int x,int y)
{
	int s=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j)){
			s+=bit[i][j];
		}
	return s;
}

void add(int x,int y,int s)
{
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=n;j+=lowbit(j))
			bit[i][j]+=s;
}

int main(int argc, char** argv) {
	int T;
     scanf("%d",&T);
     while(T--)
     {
         int q;
         scanf("%d%d",&n,&q);
         memset(bit,0,sizeof(bit));
         char op[10];
         int x1,y1,x2,y2;
         while(q--)
         {
             scanf("%s",op);
             if(op[0] == 'C')
             {
                 scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                 add(x1,y1,1);
                 add(x2+1,y1,1);
                 add(x1,y2+1,1);
                 add(x2+1,y2+1,1);
             }
             else
             {
                 scanf("%d%d",&x1,&y1);
                 int ans=query(x1,y1);
				 if(ans%2) printf("1\n");
                 else printf("0\n");
             }
         }
        if(T > 0) printf("\n");
	}
	return 0;
}

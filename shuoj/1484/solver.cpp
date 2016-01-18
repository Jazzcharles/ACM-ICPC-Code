int GCD(int a,int b)
{
int i,j,k;
j=(a<b)?a:b;
for(i=j;i>0;i--)
  if(a%i==0 && b%i==0)
   return i;
if(i==0)
 return 1;
}
#include <iostream>
using namespace std;
main()
{
    double a=1,b=100,sum=100;
    int n;cin>>n;
    while(a<n)
    {
      a++;
      b=b/2;
      sum=sum+2*b;
    }
    printf("%.4f\n",sum);
    return 0;
}

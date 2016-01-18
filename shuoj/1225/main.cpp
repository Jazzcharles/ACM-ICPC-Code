#include<stdio.h>
int main(void)
{
int year,month1,day,i,j,count=0;
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
while(scanf("%d/%d/%d",&year,&month1,&day)!=EOF)
{
    if(year%4==0 && year%100!=0 || year%400==0)
	     month[1]=month[1]+1;
    for(i=0;i<12;i++)
    {	
		 if(month1==i+1)
	     for(j=0;j<i;j++)
		   count=count+month[j];
    }
    count=count+day;
    printf("%d\n",count);
	count=0;
}
return 0;
}

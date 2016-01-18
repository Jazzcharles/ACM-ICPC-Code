#include<stdio.h>
#include<string.h>
int main()
{
	int m[1000],i=1,j,n,k=1,MaxIndex=1,MinIndex=1,max,min;
    scanf("%d",&n);
	for(k=1;k<=n;k++)
	{
		while(1)
		{
		scanf("%d",&m[i]);
		i++;
		if(getchar()=='\n')
			break;
		}
	    if(i<4)
		{
			printf("Case %d\n",k);
	        printf("No maximal and minimal!\n");
		}
	    else
	    {
	    max=m[3]+m[1]+m[2];min=m[3]+m[1]+m[2];
		for(j=1;j<=i-3;j++)
		{ 
			if((m[j]+m[j+1]+m[j+2])>max){
	            MaxIndex=j;
	            max=m[j]+m[j+1]+m[j+2];}
	        if(m[i-2]+m[i-1]+m[1]>max){   
                max=m[i-2]+m[i-1]+m[1];   
                MaxIndex=i-2;}   
            if(m[i-1]+m[1]+m[2]>max){   
                max=m[i-1]+m[1]+m[2];   
                MaxIndex=i-1;}  
			if((m[j]+m[j+1]+m[j+2])<min){
	            MinIndex=j;
	            min=m[j]+m[j+1]+m[j+2];}
			if(m[i-2]+m[i-1]+m[1]<min){   
                min=m[i-2]+m[i-1]+m[1];   
                MinIndex=i-2;}   
            if(m[i-1]+m[1]+m[2]<min){   
                min=m[i-1]+m[1]+m[2];   
                MinIndex=i-1;}   
        } 
	    printf("Case %d:\n",k);
	    printf("maximum = %d, minimum = %d, MaxIndex = %d, MinIndex = %d\n",max,min,MaxIndex,MinIndex);
	    }
	  MaxIndex=MinIndex=1;max=min=0;i=1;
    }

return 0;	
}

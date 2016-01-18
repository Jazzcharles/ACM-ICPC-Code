    #include <bits/stdc++.h>  
    using namespace std;  
    const int maxn=4e3+5;  
    int a[25],dp[25];  
    int main(int argc, char** argv) {  
            char ch;  
            int n=0;  
            while(~scanf("%d%c",&a[n++],&ch) && ch!='\n'){}
            memset(dp,0,sizeof(dp));      
            for(int i=0;i<n;i++){  
                int temp=0,tmp=0;  
                dp[i]=1;  
                for(int j=i-1;j>=0;j--){  
                    if(a[j]>=a[i] && temp<dp[j]){        //找0~i-1比i高的那些导弹中（它们都能打掉i）最多能打掉的个数加一  
                        temp=dp[j];  
                    }  
                }  
                dp[i]=temp+1;  
            }       
            int ans=0;  
            for(int i=0;i<n;i++){  
                ans=max(dp[i],ans);   
            }  
            printf("%d\n",ans);  
        return 0;  
    }  

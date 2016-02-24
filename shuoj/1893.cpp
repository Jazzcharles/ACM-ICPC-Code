#include<iostream>
#include<cmath> 
#include<cstring>
using namespace std;

const double PI=acos(-1.0);
const int maxn=500010;
int sum[maxn];
struct Complex {
    double r,i;
    Complex(double _r = 0.0,double _i = 0.0) {
        r = _r; i = _i;
    }
    Complex operator +(const Complex &b) {
        return Complex(r+b.r,i+b.i);
    }
    Complex operator -(const Complex &b) {
        return Complex(r-b.r,i-b.i);
    }
    Complex operator *(const Complex &b) {
        return Complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
}x1[maxn],x2[maxn];
void change(Complex y[],int len) {
    int i,j,k;
    for(i = 1, j = len/2;i < len-1; i++) {
        if(i < j)swap(y[i],y[j]);
        k = len/2;
        while( j >= k) {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}

void FFT(Complex y[],int len,int on) {
    change(y,len);
    for(int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j+=h) {
            Complex w(1,0);
            for(int k = j;k < j+h/2;k++) {
                Complex u = y[k];
                Complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
} 

char a[300005],b[300005];
int main(){
	
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s%s",a,b);
		int len1=strlen(a),len2=strlen(b);
		int len=1;
		while(len<max(len1,len2)*2){
			len*=2; 
		}	
		for(int i = 0;i < len1;i++)
            x1[i] = Complex(a[len1-1-i]-'0',0);
        for(int i = len1;i < len;i++)
            x1[i] = Complex(0,0);
        for(int i = 0;i < len2;i++)
            x2[i] = Complex(b[len2-1-i]-'0',0);
        for(int i = len2;i < len;i++)
		    x2[i] = Complex(0,0);
		FFT(x1,len,1);
        FFT(x2,len,1);
        for(int i = 0;i < len;i++)
            x1[i] = x1[i]*x2[i];
        FFT(x1,len,-1);
		for(int i = 0;i < len;i++)
            sum[i] = (int)(x1[i].r+0.5);
        for(int i = 0;i < len;i++)
        {
            sum[i+1]+=sum[i]/10;
            sum[i]%=10;
        }
        len = len1+len2-1;
        while(sum[len] <= 0 && len > 0)len--;
        for(int i = len;i >= 0;i--)
            printf("%c",sum[i]+'0');
        printf("\n");
	}
	return 0;
	
	
}

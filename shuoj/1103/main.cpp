#include <stdio.h>
 #include <string.h>
 int main(void)
 {
 char ch;
 while((ch=getchar())!='\n')
 {
 if('A'<=ch && ch<='Z')
 printf("%c",ch+32);
 else
 putchar(ch);
 }
 }

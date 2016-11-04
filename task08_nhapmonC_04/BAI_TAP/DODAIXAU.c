#include<stdio.h>
#include<conio.h>

int string_ln(char*);

int main() {
   char str[20];
   int length;
   
   gets(str);
   
   length = string_ln(str);
   printf("%d",length);
  return(0);
}

int string_ln(char*p) /* p=&str[0] */
{
   int count = 0;
   while (*p != '\0') {
      count++;
      p++;
   }
   return count;
}

/*Tìm độ dài chuỗi bởi sử dụng con trỏ trong C
Input
String
Output
6

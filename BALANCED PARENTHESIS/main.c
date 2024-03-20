#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int main()
{
   char str[100];
   char stack[100];
    int top = -1,i,len,flag=0;
   printf("Enter the expression : ");
   gets(str);
len = strlen(str);
  for(int i=0;i<len;i++)
   {
    if(str[i] == '(' ||str[i] == '{' ||str[i] == '[')
    {
        top++;
        stack[top] = str[i];
    }

    else if(str[i] == ')' ||str[i] == '}' ||str[i] == ']')
    {
        char ch = stack[top];
        if(ch=='(')
           ch = ')';

        else if(ch=='{')
           ch = '}';

        else
          ch = ']';

        if(ch == str[i]){
            top--;
        }
        else{
            flag=1;
            break;
        }
    }
   }

   if(flag==0&&top==-1)
         printf("Balanced !!!!");
   else
         printf("Not Balanced !!!!");

         return 0;
}

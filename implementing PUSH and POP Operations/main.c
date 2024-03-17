#include<stdio.h>
#define maxsize 5
int stack[maxsize];
int top = -1;

void Push()
{
    if(top==maxsize-1)
    {
        printf("StackOver Flow!!!!\n");
        return;
    }
    top++;
    int n;
    printf("Enter the number you want to push in stack : ");
    scanf("\n%d",&n);
    stack[top] = n;
    printf("%d is inserted in the stack\n",n);

}


void Pop()
{
    if(top==-1)
    {
        printf("Underflow !!!!\n");
        return;
    }
    printf("%d is removed from the stack\n",stack[top]);
    top--;
}


void Show()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return;
    }
    for(int i=0;i<=top;i++)
    {
        printf("%d\n",stack[top-i]);
    }
}


int main()
{
   for(int i=0;i<3;i++)
   {
     Push();
   }
   printf("\n");
   Show();
   printf("\n");
   Pop();
   printf("\n");
   Show();
   return 0;
}

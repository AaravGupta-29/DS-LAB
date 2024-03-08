#include<stdio.h>
#include<stdlib.h>
#define maxsize 1000
int size;
void Create(int list[])
{
    int i;
    printf("Enter the size of list : ");
    scanf("%d",&size);
    if(size>maxsize)
    printf("List Over flow !!!!");
    else{
          printf("Enter list elements : \n");
          for(i=0;i<size;i++)
          {
            printf("Enter %d element in the list : ",i+1);
            scanf("\n%d",&list[i]);
          }
    }

}



void Insert(int list[])
{
    if(size==0) printf("List is Empty !!!!\n");
    else
    {
      int pos,value,i;
    printf("Enter position : ");
    scanf("\n%d",&pos);
    printf("Enter value to insert : ");
    scanf("\n%d",&value);
    if(pos>0 && pos<size)
    {
        for(i=size;i>=pos;i--)
        {
            list[i] = list[i-1];
        }
          list[pos-1] = value;
            size++;
            printf("%d is inserted at position %d\n",list[pos-1],pos);
    }
    else
       printf("Invalid Position !!!!!\n");
    }

}



void Display(int list[])
{
    if(size==0) printf("List is Empty !!!!\n");

    else{
    printf("List Elements are : \n");
    int i;
    for(i=0; i<size ; i++)
    {
        printf("%d\n",list[i]);
    }

    }
}

void Delete (int list[])
{
   if(size==0) printf("List is Empty !!!!\n");

    else
    {
      int pos,i;
      printf("Enter Position : ");
      scanf("\n%d",&pos);
      if(pos>0 && pos<=size)
      {
        for(i = pos-1;i<size;i++)
            list[i] = list[i+1];
                  size--;
                  printf("Element Deleted !!!!\n");
      }
      else
         printf("Invalid Position !!!!\n");
    }
}

void Search(int list[])
{
    if(size==0) printf("List is Empty !!!!\n");
    else{
     int element,i;
     printf("Enter the element you want to search : ");
     scanf("\n%d",&element);

     for(i=0;i<size;i++)
     {
          if(element==list[i]){
            printf("%d is found\n",element);
            return;
          }
     }
     printf("%d is not found\n",element);

    }
}


int main()
{
   int list[maxsize];
   Create(list);
   Insert(list);
   Display(list);
   Delete(list);
   Display(list);
   Search(list);
    return 0;
}

#include<stdio.h>

void quick_sort(int [],int,int);

int main()
{
  int A[20],i,n;

   printf("Enter the number of elements");
    scanf("%d",&n);
   printf("Enter the elements of the array ");
    for(i=0;i<n;i++)
    {
    scanf("%d",&A[i]);
    }

 quick_sort(A,0,n-1);

 printf("Sorted array");
  for(i=0;i<n;i++)
   {
    printf("%d",A[i]);
   }

 return 0;
}

void quick_sort(int A[10],int lb,int ub)
{
 int key,i,j,t;

if(lb<ub)
{
  key=lb;
  i=lb;
  j=ub;

while(i<j)
  {

   while(A[i]<=A[key]&&i<ub)
     i++;

   while(A[j]>=A[key]&&j>lb)
     j=j-1;

    if(i<j)
    {
        t=A[i];
        A[i]=A[j];
        A[j]=t;
    }
  }
        t=A[key];
        A[key]=A[j];
        A[j]=t;

quick_sort(A,lb,j-1);
quick_sort(A,j+1,ub);
}
}


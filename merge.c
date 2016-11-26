#include<stdio.h>

void merge(int A[],int l,int h)
{
 int i=0,len,key=0,m1=0,m2=0,tem[20];
 len=h-l+1;

 if(l>=h)
 return;

 key=(l+h)/2;
 merge(A,l,key);
 merge(A,key+1,h);

 for(i=0;i<len;i++)
 {
     tem[i]=A[l+i];
 }

m1=0;
m2=key-l+1;

for(i=0;i<len;i++)
{
    if(m2<=h-1)
     { if(m1<=key-1)
       { if(tem[m1]>tem[m2])
          { A[i+1]=tem[m2++]; }
        else A[i+1]=tem[m1++]; }
      else A[i+1]=tem[m2++]; }
    else A[i+1]=tem[m1++];
}
}


void main()
{
int A[20],i=0,n;

printf("Enter the number of elements");
scanf("%d",&n);
printf("Enter the elements of the array ");
 for(i=0;i<n;i++)
 {
  scanf("%d",&A[i]);
 }

merge(A,0,n-1);

printf("Sorted array");
 for(i=0;i<n;i++)
 {
  printf("%d",A[i]);
 }
}

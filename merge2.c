#include<stdio.h>

void mer(int A[],int l,int h)
{
int key;

 if(l<h)
 {
  key=(l+h)/2;
  mer(A,l,key);
  mer(A,key+1,h);
  merge(A,l,key,h);

}
}
void merge(int A[],int low,int mid,int high)
{
 int i,l,m,temp[10],k;
 l=low;
 i=low;
 m=mid+1;

 while((l<=mid)&&(m<=high))
  {
      if(A[l]<=A[m])
      {
          temp[i]=A[l];
          l++;
      }

      else
      {
          temp[i]=A[m];
          m++;
      }
       i++;
  }

 if(l>mid)
  for(k=m;k<=high;k++)
   {
       temp[i]=A[k];
       i++;
   }

 else
   for(k=l;k<=mid;k++)
   {
       temp[i]=A[k];
       i++;
   }

 for(k=low;k<=high;k++)
 A[k]=temp[k];

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

mer(A,0,n-1);

printf("Sorted array");
 for(i=0;i<n;i++)
 {
  printf("%d ",A[i]);
 }
}

#include<stdio.h>

int main()
{
    int i,n,j,a[20],t,c=0;

    printf("Enter the no. of elements ");
    scanf("%d",&n);

    printf("Enter the elements\n");
     for(i=0;i<n;i++)
      scanf("%d",&a[i]);

     for(i=0;i<n;i++)
     printf("%d",a[i]);

    for(i=0;i<n;i++)
    {  for(j=0;j<n-i-1;j++)
        {
           if(a[j]>a[j+1])
           {
               t=a[j+1];
               a[j+1]=a[j];
               a[j]=t;
               c++;
           }
        }
    if(c==0)
      break;
    }
     printf("\nSorted Array\n");

     for(i=0;i<n;i++)
     printf("%d",a[i]);

return 0;
}


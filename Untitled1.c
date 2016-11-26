#include<stdio.h>
#include<malloc.h>

main()
{
 int a[10][10],i,n,m,j;
 int **x;
 char ch;

x=a;

 printf(" enter the number of rows ");
 scanf("%d",&m);

 x=(int**)malloc(m*sizeof(int *));

for(i=1;i<=m;i++)
 {
 printf("\n Enter the no. of columns for %d th row",i);
 scanf("%d",&n);
  x[i]=(int*)malloc((n)*sizeof(int));

  for(j=1;j<=n;j++)
    {

    scanf("%d",&x[i][j]);
    }
      for(j=1;j<=n;j++)
    printf("%d",x[i][j]);
   printf("\n");



  }
}

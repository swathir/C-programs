#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<math.h>

void main()
{
    int a[5]={1,4,5,9,2};
    unsigned int *b[4];
    b[0]=a;//now b[0] is holding the orignal array
    int i,j;

    for(i=1;i<4;i++){
b[i]= (unsigned int*)malloc(sizeof(unsigned int)*5);
    }

                printf("%d %d %d %d",b[0][0]&1,b[0][0]&2,b[0][0]&4,b[0][0]&8);
}

#include<stdio.h>

void main()
{
int i;
char M[20];

printf("Enter Message ");
//strcpy(M,"10");
gets(M);


for(i=0;i<8*5;i++)
printf("%d",0 != ("HELLO"[i/8] & 1 << (~i&7)));

printf("\n\n ");
for(i=0;i<8*5;i++)
printf("%d",0 != (M[i/8] & 1 << (~i&7)));
}

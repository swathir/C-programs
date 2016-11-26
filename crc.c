#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
int i,j,kn,mn,c;
//bool k[50][8];
char M[100],k[40],t[40],q[100],crc[40],k1[40];
//int As[50];

kn=strlen(k);
mn=strlen(M);

printf("Enter Message ");
//strcpy(M,"10");
gets(M);
/*
for(i=0;M[i]!='\0';i++)
 {
 As[i]=(int)M[i];
 printf(" %d",As[i]);
 }


for (i=0;i<mn;i++)
  { for(c=8,j=0;c>=0;c--,j++)
         k[i][]=As[i]>>c;
  }
*/
//printf("Message in binary ");

//for(i=0;i<8*mn;i++)
//printf("%d",0 != (M[i/8] & 1 << (~i&7)));

//100000100110000010001110110110111
strcpy(k,"100000111");

strcpy(k1,k);

for(i=0;i<kn-1;i++)
M[mn+i]='0';

for(i=0;i<kn;i++)
t[i]=M[i];

for(i=0;i<mn;i++)
{
 q[i]=t[0];

 if(q[i]=='0')
   for(j=0;j<kn;j++)
     k[j]='0';
 else
   for(j=0;j<kn;j++)
     k[j]=k1[j];

 for(j=kn-1;j>0;j--)
  {
    if(t[j]==k[j])
      crc[j-1]='0';
    else
      crc[j-1]='1';
  }

 crc[kn-1]=M[i+kn];
 strcpy(t,crc);
}

strcpy(crc,t);


printf("\nCRC is ");
for(i=0;i<kn-1;i++)
printf("%c",crc[i]);

}

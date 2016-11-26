#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
int i,j,kn,mn,c;
//bool k[50][8];
char M[100],k[30],t[30],q[100],crc[30],k1[30],kk,m[100];
int As[50],number;

printf("Enter Message ");
//strcpy(M,"10");
gets(m);

for(i=0;m[i]!='\0';i++)
 {
 As[i]=(int)m[i];
 printf(" %d",As[i]);
 }

mn=strlen(m);
kk=mn-1;

 number= mn*8;
 number--;

  for(i=mn-1;i>=0;i--)
  {
     for(j=0;j<8;j++)
      {
         M[number]= m[kk]%2;
         m[kk]=m[kk]/2;
            number--;
        }
        kk--;
    }
//100000111
//100000100110000010001110110110111
strcpy(k,"100000100110000010001110110110111");

kn=strlen(k);

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

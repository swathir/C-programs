#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
int i,j,kn,mn,c;
//bool k[50][8];
char M[100],k[30],t[30],q[100],crc[30],k1[30],kk,m[100];
int final[100];
char fina[6]={0x2C,0x41,0x38,0xA9,0x0F,0xE4},fin[6]={0x2C,0x41,0x38,0xA9,0x4C,0x47};
char type[2]={0x08,0x00};
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

printf("\npreamble  source_address destination_address type data CRC");
for(i=0;i<7;i++)
final[i]=0xaa;
for(i=0;i<7;i++)
printf("%0x",final[i]);

for(j=i,kk=0;j<6+i;kk++,j++)
final[j]=fina[kk];

for(i=0;i<13;i++)
printf("%0x",final[i]);

for(i=j,kk=0;i<6+j;kk++,i++)
final[i]=fin[kk];

for(j=i,kk=0;j<2+i;kk++,j++)
final[j]=type[kk];

for(i=j,kk=0;As[i]!='\0';i++,kk++)
final[i]=As[kk];

//printf("\ndata  ");

printf("\n\nCRC is ");
for(i=0;i<kn-1;i++)
{
    printf("%c",crc[i]);
    final[i]=crc[i];
    i++;
}
printf("\n\nFINAL is ");
for(j=0;j<i;j++)
{
    printf("%0x ",final[j]);
}
printf("\n\n");
}

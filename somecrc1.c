 #include<stdio.h>
 #include<math.h>
 #include<string.h>
 #include<malloc.h>
 #include<math.h>
#include<stdlib.h>
 struct frame
 {
    int preamble[56];
    int sfd[8];
    int destaddress;
    int sourceaddress;
    char type[16];
    int msg[100];
    int crc[32];

 };
 struct frame f1;
 int currentlengthofmessage=0;
 int bin;
 int numappend;
 void crccheck()
 {
  int temp1,temp2;
  int crc[32]={0};
  int lowerorder[]={0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1};
  int countin = 32;
  int count=0;
  int i;
  int l;
  int k;
  numappend+=32;
  while(count<numappend)
   {

     temp2 = crc[0];
     crc[0] = f1.msg[count];

     if(crc[31]==0)
      { i=0;
        countin = 32;
        while(countin>1)
        {
           temp1 = temp2;
           temp2 = crc[i+1];
           crc[i+1] = temp1;
           countin--;
           i++;

        }

      }
     else
      {
        i=0;
        countin = 32;
        while(countin>1)
        {
           temp1 = temp2;
           temp2 = crc[i+1];
           crc[i+1] = temp1;
           countin--;
           i++;

        }
       l = 0;
       for(k=31;k>=0;k--)
       {
        crc[k] = crc[k]^lowerorder[l];
        l++;
       }

      }


   count++;


 }

 printf("remainder in this case is  \n");
 for(i=31;i>=0;i--)
 {
    printf("%d",crc[i]);
 }
 for(i=0;i<31;i++)
 {
     if(crc[i]==1)
         {
             printf("error in transmission \n");
             break;
         }
 }

 }
 void initializepreamble()
 {
   int i = 0;
   int sadd,dadd;
   for(i=0;i<56;i++)
   {
       if(i%2==0)
         f1.preamble[i] = 1;
       else
         f1.preamble[i]=0;

   }
   f1.sfd[0]=1;
   f1.sfd[1]=0;
   f1.sfd[2]=1;
   f1.sfd[3]=0;
   f1.sfd[4]=1;
   f1.sfd[5]=0;
   f1.sfd[6]=1;
   f1.sfd[7]=1;
   f1.type[0] = '0';
   f1.type[1] = '0';
   f1.type[2] = '0';
   f1.type[3] = '0';
   f1.type[4] = '1';
   f1.type[5] = '0';
   f1.type[6] = '0';
   f1.type[7] = '0';
   f1.type[8] = '0';
   f1.type[9] = '0';
   f1.type[10] = '0';
   f1.type[11] = '0';
   f1.type[12] = '0';
   f1.type[13] = '0';
   f1.type[14] = '0';
   f1.type[15] = '0';

   printf("Enter the source address in binary (max 48 bits)");
   scanf("%d",&f1.sourceaddress);
   printf("Enter the destination address in binary (max 48 bits)");
   scanf("%d",&f1.destaddress);


   printf("\n Preamble \n");
   for(i=0;i<56;i++)
   printf("%d",f1.preamble[i]);
   printf(" \n");
   printf("\n Start of Delimiter \n");
   for(i=0;i<8;i++)
   printf("%d",f1.sfd[i]);
   printf(" \n");
   printf("Source Address of message %d \n",f1.sourceaddress);
   printf("Destination Address of message %d \n",f1.destaddress);
   printf("Type/Length %s \n",f1.type);

 }




 void main()
 {
   int num,n,ret;
   int bin[80];
   char str[30];
   int g[33]={1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1};
   int crc[32]={0};
   int lowerorder[]={0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,0,1,1,0,1,1,1};
   int i,j,k,l,x,rem;
   int count = 0;
   char ch;
   int temp1,temp2;int countin=32;
   /*printf("Enter your message: ");
     scanf("%s",str);
     printf("String is %s",str);*/
   i=0;
   FILE *fp;
   initializepreamble();


    printf("Enter the name of file you wish to see\n");
    scanf("%s",str);

   fp = fopen(str,"r"); // read mode

    if( fp == NULL )
    {
       perror("Error while opening the file.\n");
       exit(EXIT_FAILURE);
    }


    currentlengthofmessage=0;
    while( ( ch = fgetc(fp) ) != EOF )
       {
           printf("%c",ch);
             x = (int)ch;
      printf("Value of x is %d \n",x);
      num=x;

      int k=0;
      while(num>0)
     {
      rem = num%2;
      num = num/2;
      bin[k]=rem;
      k++;
     }
   k = k-1;
    while(k>=0)
    {
      f1.msg[currentlengthofmessage++] = bin[k];
      bin[k] = 0;
      k--;

    }
 }

    fclose(fp);


 printf("current message \n");
 for(i=0;i<currentlengthofmessage;i++)
   {
    printf("%d",f1.msg[i]);
   }
 printf("\n");



 numappend = currentlengthofmessage-1;

   for(i=0;i<32;i++)
   {
      f1.msg[currentlengthofmessage++]=0;
   }


 i=0;
   while(count<currentlengthofmessage)
   {

     temp2 = crc[0];
     crc[0] = f1.msg[count];


     if(crc[31]==0)
      { i=0;
        countin = 32;
        while(countin>1)
        {
           temp1 = temp2;
           temp2 = crc[i+1];
           crc[i+1] = temp1;
           countin--;
           i++;

        }

      }
     else
      {
        i=0;
        countin = 32;
        while(countin>1)
        {
           temp1 = temp2;
           temp2 = crc[i+1];
           crc[i+1] = temp1;
           countin--;
           i++;

        }
       l = 0;
       for(k=31;k>=0;k--)
       {
        crc[k] = crc[k]^lowerorder[l];
        l++;
       }


      }


   count++;

   }
 printf("\nCRC is\n");
 k = 0;
 for(i=31;i>=0;i--)
   {

       f1.msg[numappend+32-i]=crc[i];
       f1.crc[k]=crc[i];
       printf("%d",f1.crc[k]);
       k++;

   }
   numappend+=32;

 printf("\n sent message \n");

 for(i=0;i<=numappend;i++)
 {
   printf("%d",f1.msg[i]);
 }
 printf("\n");
 //change a bit of f1.msg like f1.msg[i] = 0 or 1 then run this
 crccheck();

 }

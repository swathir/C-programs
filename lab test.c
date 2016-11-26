#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<math.h>
#include<malloc.h>

//using namespace std;

void binRadixSort(unsigned int *a,int N){

    unsigned int *b[4];
    b[0]=a;//now b[0] is holding the orignal array
    int i,j;

    for(i=1;i<4;i++){
b[i]= (unsigned int*)malloc(sizeof(unsigned int)*N);
    }

    int H0;//uper bound index of the array having 0
    int len;//the number of pass required

    // hold the upper bound of the array thathold bit '0'
    //Section 2 initialize H0 and find nuber of pass required i.e. binary digit in unsign int
    //*****************************************************

       for(i=0,j=0;i<N;i++)
         if(!b[0][i]&1)
          {
          H0=i;
          b[1][j++]=b[0][i];
          }
       len==j-1;

    //*******************************************************


    unsigned int ander =1;    // a number that we use to perform the and
     //operation to extract perticular bit

    int k0,k1,k2,k3;
    k0=0;
    k1=k0+1;
    k2=k0+2;
    k3=k0+3;


    int j0=0,j1=0;//variable to hold the count where we need to store a number with
  //particular bit is 0 in j0 and 1 in j1
    for(i=1;i<16;i++)
    {
//int j;
        j0=j1=0;
        for(j=0;j<=H0;j++){
            if(!(b[k0][j]&ander))
            {
                b[k2][j0] = b[k0][j];
                j0++;
            }
    else
    {
            b[k3][j1] = b[k0][j];
            j1++;
    }
        }

        for(;j<N;j++){
            if(!(b[k1][j-H0-1]&ander))
            {
                b[k2][j0] = b[k1][j-H0-1];
                j0++;
            }
            else
            {
                b[k3][j1] = b[k1][j-H0-1];
                j1++;
            }
        }


ander = ander*2;
printf("%d\n",ander);
H0=j0-1;

//write a code so that in the next iteration we are looking at the proper array
//**********************************************************************

k0=k3;
k3=k2;
k2=k1;
k1=k3;
k3=0;
//*******************************************

    // find the number of binary digit in the number and initailize the number to perform the operation

    }

    //copy the sorted array in the orignal array
    for(j=0;j<=H0;j++)
        a[j]=b[k0][j];
    for(;j<N;j++)
        a[j]=b[k1][j-H0-1];

    printf("\n\n");

}

int main()
{
    unsigned int *a;
    int N; // Number of elment in the array
    int i;

    //clrscr();
    //initialize
        //section 1
    //create a dynamic array and get the inputto array by user
    //**********************************************
        printf("Enter the no. of elements ");
            scanf("%d",&N);
        a=(unsigned int*)malloc(sizeof(unsigned int)*N);

        for(i=0;i<N;i++)
       {
           printf("Enter the %d th element ",i);
            scanf("%d",&a[i]);

            if(a[i]<=0)
             {
                 printf("improper");
                 i--;
                 continue;
             }
       }

    //**********************************************

    printf("%d %d %d",N,a[0],a[N-1]);

    binRadixSort(a,N);
    for(i=0;i<N;i++)
    printf("A[%d]:%d",i,a[i]);

    return 0;

}

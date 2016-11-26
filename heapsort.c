#include<stdio.h>

int heapsize=1,length;

void heapify(int A[], int i)
{
int t,largest;
int l=2i;
int r=2i+1;

if(l<=heapsize && A[l]>A[i])
{largest=l;}

else largest=i;

if(r<=heapsize && A[largest]<A[r])
{largest=r;}

if(largest!=i)
{
t=A[i];
A[i]=A[largest];
A[largest]=t;
}

}

void build_maxheap(int A[])
{
int i;
heapsize=length; //
for(i=length/2;i>0;i--)
heapify(A,i);
}

void heapsort(int A[])
{
    int i,t;
build_maxheap(A);

for(i=length;i>1;i--)
{
t=A[1];
A[1]=A[i];
A[i]=t;
}

heapsize=heapsize-1;
heapify(A,1);
}

void insert(int A[], int x)
{
A[heapsize]=x;
heapsize=heapsize+1;
}

void display(int A[])
{
int i;
for(i=1;i<=length;i++)
printf("\n %d ",A[i]);
}

void main()
{
int i, A[15],x;
loop:
printf("Enter the no. of elements  ");
scanf("%d",&length);

if(length>15)
{
    printf("Too many elements; re-enter");
    goto loop;
}

i=length;
while(i!=0)
{
printf("Enter the elements ");
scanf("%d",&x);
insert(A,x);
i--;
}
heapsort(A);
display(A);

}

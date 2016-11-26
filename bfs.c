#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
int info;
struct node* L;
};

void display(struct node* nw[][10], int j1[], int n)
{
int i,j;
for(i=1;i<=n;i++)
  {
    for(j=1;j<=j1[i];j++)
      printf("  %d ->",nw[i][j]);

  printf("\n");
  }

}

void bfs(struct node* nw[10][10], int n, int v[])
{
int i,j=1;
struct node *this;
this=nw[1][1];

label:
while(this!=NULL)
{
  if(v[this->info]!=1)
  {
  printf("%d",this->info);
  v[i]=1;
  }

    for(i=1;i<=n;i++)
    {
    if(this->L==nw[i][j]&&v[this->info]!=1)
        {
        this=nw[i][j];
        goto label;
        }
    else this=this->L;
    }
}
}

void main()
{
int n,i,num,ch,j1[10],vis[10],j;
struct node* nw[10][10];

printf("Enter the no. of nodes  ");
scanf("%d",&n);

for(i=1;i<=n;i++)
{
printf("Enter connected nodes for %d ",i);
nw[i][1]=(struct node*)malloc(sizeof(struct node));
nw[i][1]->L=NULL;
nw[i][1]->info=i;

for(j=2;ch!=0;j++)
{
scanf("%d",&num);

nw[i][j]=(struct node*)malloc(sizeof(struct node));
nw[i][j]->L=NULL;
nw[i][j]->info=num;

printf("\nWould you like to continue ? 1/0 :");
scanf("%d",&ch);
if(ch==0)
j1[i]=j;
}
}

for(i=1;i<=n;i++)
vis[i]=0;

display(nw,j1,n);
bfs(nw,n,vis);

}


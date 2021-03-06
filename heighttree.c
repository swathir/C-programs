#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void height(struct node* );

struct node
{
int n;
struct node* ll;
struct node* rl;

}*root;

struct node* insert(struct node *root, int x)
{
  struct node *temp;
  struct node *cur;

  temp=(struct node*)(malloc(sizeof(struct node)));

  temp->ll=NULL;
  temp->rl=NULL;
  temp->n=x;

  if(root==NULL)
  return temp;

  cur=root;

  while(cur!=NULL)
  {


      if(x==cur->n)
      {
      printf("duplicate");
      free(temp);
      return(root);
      }

  if(x<cur->n)
  {
      if(cur->ll==NULL)
      {
        cur->ll=temp;
        return(root);
      }
      cur=cur->ll;
      continue;
  }
  else
        if(cur->rl==NULL)
      {
        cur->rl=temp;
        return(root);
      }
  cur=cur->rl;

  }

  return root;

}

void pre(struct node *T)
{
    if(T!=NULL){
     printf(" %d ",T->n);
    pre(T->ll);
    pre(T->rl);
    }

}

void in(struct node *T)
{
    if(T!=NULL)
    {
        in(T->ll);
     printf(" %d ",T->n);
       in(T->rl);

    }

}

void post(struct node* T)
{
 if(T!=NULL)
 {
     post(T->ll);
         post(T->rl);
        printf(" %d ",T->n);
 }
}

int maxv(int a,int b)
{
   if(a>b)
   return a;
   else return b;
}

int heigh(struct node* root)
{
    if(root==NULL)
    return -1;

   return 1+maxv(heigh(root->ll),heigh(root->rl));

   /*
   while root != NULL
    root->ll&&root->rl==NULL
    if c>max
       max=c
    c=0

    push
    c++
    root=root->ll
    root=root->rl
    pop
    */
}

void main()
{
struct node *root = NULL;
int ch, x, c;

label:
printf("\n\nEnter your choice \n1.Insert \n2.preorder \n3.postorder \n4.Inorder \n5.Height \n6.exit  ");
scanf("%d",&ch);

switch(ch)
{
    case 1 :
    printf("\nEnter the value to be inserted ");
    scanf("%d",&x);
    root=insert(root,x);

    goto label;
    break;

    case 2 :
        if(root==NULL)
              printf("tree is empty\n");
        else
          pre(root);
    goto label;
        break;

    case 3 :
        if(root==NULL)
              printf("tree is empty\n");
        else post(root);
    goto label;
        break;

    case 4 :
         if(root==NULL)
             printf("tree is empty\n");
         else in(root);
    goto label;
        break;

    case 5 :
         if(root==NULL)
              printf("tree is empty\n");
         else {c = 1 + heigh(root);
         printf("Height is %d",c);}
    goto label;
        break;


    case 6 : exit(0);

    default : printf("Invalid entry\n\n");
    goto label;
}

}

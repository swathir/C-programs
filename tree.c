#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node* R;
struct node* L;
}*root,*N,*P,*S,*SP;


struct node* findp(struct node* root,int x)
{
    struct node* q;
    struct node* par;
    q=root;

    par = NULL;
    while(q!=NULL)
    {
        if(q->info==x)
        {
   //         (*f)=1;
             return par;
        }
        par=q;

        if(q->info>x)
        q=q->L;
        else q=q->R;
    }

}
struct node* insert(struct node *root, int x)
{
  struct node *temp;
  struct node *cur;

  temp=(struct node*)(malloc(sizeof(struct node)));

  temp->L=NULL;
  temp->R=NULL;
  temp->info=x;

  if(root==NULL)
  return temp;

  cur=root;

  while(cur!=NULL)
  {
      if(x==cur->info)
      {
      printf("duplicate");
      free(temp);
      return(root);
      }

  if(x<cur->info)
  {
      if(cur->L==NULL)
      {
        cur->L=temp;
        return(root);
      }
      cur=cur->L;
      continue;
  }
  else
        if(cur->R==NULL)
      {
        cur->R=temp;
        return(root);
      }
  cur=cur->R;

  }

  return root;

}

struct node* search(struct node* root, int x)
{
    struct node* q;
    q=root;

    while(q!=NULL)
    {

        if(q->info==x)
        {
           printf("\nelement found");
            return q;
        }

        if(q->info>x)
        q=q->L;
        else q=q->R;
    }

 printf("\nElement not found");
}

struct node* delet(struct node* root,int x)
{
    P=findp(root,x);
    N=search(root,x);
    S=root->R;

    if(N==NULL)
    {
        printf("Node not found");
        return;
    }

    if(N==root) //root
    {
        printf(": %d",root->R->info);
        printf(": %d",root->L->info);
   /*     if(root->R==NULL)
        {
            printf("root has no right");
            if(root->L!=NULL)
            root=root->L;
            free(N);
            return root;
        }
            else
            {
                printf("root had no child");
                root==NULL;
                printf("no more elements");
                return NULL;
            }*/

          if(S->L==NULL)
    {
        if(root->L!=NULL)
       (root->R)->L=root->L;
       root=root->R;
       free(N);
       return root;
    }
        while(S->L!=NULL)
      {
          SP=S;
          S=S->L;
      }

        SP->L=S->R;
        S->L=N->L;
        S->R=N->R;
        free(N);
        return S;
    }

    if(N->L!=NULL&&N->R!=NULL) //both
    {
      while(S->L!=NULL)
      {
          SP=S;
          S=S->L;
      }

        SP->L=S->R;
        S->L=N->L;
        S->R=N->R;
        if(P->L=N)
        {
            P->L=S;
        }
        else P->R=S;
        free(N);
        return root;
    }

    else if(N->L!=NULL&&N->R==NULL) //lchil
    {
        if(P->R==N)
        {P->R=N->L;
        }

        else P->L=N->L;

        free(N);
        return root;

    }

     else if(N->L==NULL&&N->R!=NULL) //rchil
     {

        if(P->R==N)
        {P->R=N->R;
        }

        else P->L=N->R;

        free(N);
        return root;

     }

     else //no
     {
        if(P->R==N)
        {P->R=NULL;        }

        else P->L=NULL;

        free(N);
        return root;
     }
}

void pre(struct node *T)
{
    if(T!=NULL){
     printf(" %d ",T->info);
    pre(T->L);
    pre(T->R);
    }
}

void in(struct node *T)
{
    if(T!=NULL)
    {
        in(T->L);
     printf(" %d ",T->info);
       in(T->R);

    }

}

void main()
{
struct node *root = NULL;
int ch, x, num, i;

label:
printf("\n\nEnter your choice \n1.Insert \n2.search \n3.delete \n4.print \n5.in \n6.exit  ");
scanf("%d",&ch);

switch(ch)
{
    case 1 :
    printf("\nEnter the value to be inserted ");
    scanf("%d",&num);
    root=insert(root,num);

    goto label;
    break;

    case 2 :
        if(root==NULL)
              printf("node is empty\n");
        else
           {
          printf("\nEnter the value to be searched ");
          scanf("%d",&x);
          N=search(root,x);
            }
    goto label;
        break;

    case 3 :
        if(root==NULL)
              printf("node is empty\n");
        else
        {
            printf("\nEnter the value to be deleted ");
            scanf("%d",&i);
            root=delet(root,i);
     }
    goto label;
        break;

    case 4 :
        if(root==NULL)
              printf("tree is empty\n");
        else
          pre(root);
    goto label;
        break;


    case 5 :
        if(root==NULL)
              printf("tree is empty\n");
        else
          in(root);
    goto label;
        break;

    case 6 : exit(0);

    default : printf("Invalid entry\n\n");
    goto label;
}

}

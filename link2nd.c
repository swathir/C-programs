#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node *delet(struct node* ,struct node*);
struct node *insert(struct node *,struct node*,int);
void print(struct node*);
struct node* create(struct node *);
int k=1;


struct node
{
    int n;
    struct node *link;
} *head, *list;

struct node* create(struct node *list)
{  int num;

    printf("Enter the element(enter -999 in the end)");
    scanf("%d", &num);

if(num==-999)
   {
     return(head);
   }

else
{
    if(head==NULL)
     {
     list=(struct node*)malloc(sizeof(struct node));
     list->n=num;
     list->link=NULL;
     head=list;

     }
}
return(head);
}

struct node *insert(struct node* list, struct node *head, int num)
{
    struct node* nw;
    nw=(struct node*)malloc(sizeof(struct node));

    while(list->link!=NULL)
       {
           if(list->n<num && list->link->n>num)
           {
                nw->link=list->link;
                nw->n=num;
                list->link=nw;

           }
           else
           {
               list=list->link;
           }

       }

  if(list->link==NULL)
  {
            if(list->n<num)
             {

             nw->n=num;
             list->link=nw;
             nw->link=NULL;
             list=head;
             }

  }



     return list;
}

struct node *delet(struct node* list,struct node* head)
{
    struct node *p;

      p=list->link;
      list->link=p->link;
      free(p);
      return head;

return head;
}


void print(struct node* list)
{
    if(list->link==NULL)
     {
         printf("%d",list->n);
         return;
     }

else printf("%d",list->n);
print(list->link);

  return;
}

void func(struct node* list,struct node *head,int num, int d, int c)
{

    if(list->link->n==num)
    {
    if(d==1)
     {
        trav(list,head,c);
     }
    if(d==0)
    {
        printf("%d",k);
        trav(head,head,(k-c)-1);
    }
   }

   else
   {
       k++;
       func(list->link,head,num,d,c);
   }
}

void trav(struct node* list,struct node* head, int c)
{
    if(c==0)
    {
        head=head->link;
    }
    else while(c!=0)
     {
      c--;
      list=list->link;
      }
delet(list,head);

}

int main()
{

   int num=0,op;
   int c;
   int d;

   head=(struct node*)malloc(sizeof(struct node));
   head=NULL;

do{
   printf("select 0.quit 1.create 2.insert 4.func 5.print");
   scanf("%d",&op);

   if(op==1)
   {
    head=create(head);
   }

    if(op==2)
    {
        printf("enter the value to be inserted ");
        scanf("%d", &num);

if(head->n>num)
{
        struct node* nw;
    nw=(struct node*)malloc(sizeof(struct node));
            nw->link=head;
            nw->n=num;
            head=nw;
}

else    insert(head,head,num);
    }

    if(op==4)
    {
        printf("enter values of num, d (0 for l or 1 for r),c (traversal)");
        scanf("%d%d%d",&num,&d,&c);
        func(head,head,num,d,c);
    }

    if(op==5)
    {
        print(head);
    }

  /*  else if(op!=0)
    {
        printf("wrong input");
        break;
    }
*/
}while(op!=0);


return 0;
}

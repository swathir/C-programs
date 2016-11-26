/*
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node *delet(struct node* ,struct node*);
struct node *insert(struct node *,struct node*,int);
void func(struct node*,int,char,int);
void print(struct node*);
struct node* create(struct node *);

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
    p=(struct node*)malloc(sizeof(struct node));

while(list->link!=NULL)
{

      p=head->link;
      free(head);
      head=p;
      return head;

  }

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

void func(struct node* head,int num, char d, int c)
{
head=list;

    if(list->n==num)
    {
    if(d=='r')
     {
    while(c!=0)
     {
      c--;
      }
      delet(list,head);
     }

    if(d=='l')
    {
    while(c!=0)
    {
    list=list->link;
    c--;
    }
    delet(list,head);
    }
}
}
int main()
{

   int num=0,op;
   int c;
   char d;

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
        printf("enter values of num, d,c");
        scanf("%d%c%d",&num,&d,&c);
        func(head,num,d,c);
    }

    if(op==5)
    {
        print(head);
    }
}while(op!=0);

return 0;
}

*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node *delet(struct node* ,struct node*, int key);
struct node *insert(struct node *,struct node*,int);
void retrieve(struct node*);
void print(struct node*);
struct node* create(struct node *);

//struct node* create(struct node *, int )

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

      //     if(list->n==num)
      //    {
      //        nw->n=num;
      //        nw->link=list->link;
       //       list->link=nw;
       //   }
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

struct node *delet(struct node* list,struct node* head, int key)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));

while(list->link!=NULL)
{

    if(head->n==key)
     {
      p=head->link;
      free(head);
      head=p;
      return head;
     }

    if(list->link->n==key)
     {
      p=list->link;
      list->link=p->link;
      free(p);
      return head;
     }

    else list=list->link;
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

void retrieve(struct node* list)
{
    int c,d;
    printf("Enter the value of index");
    scanf("%d",&d);
    c=d-1;
    while(c>0)
    {
        if(list->link!=NULL)
         {
             c--;
             list=list->link;
         }
    }

    printf("%d",list->n);
}

int main()
{

//node delet(node *,int);
//node insert(node *,int);
//void retrieve(node *);
//void print(node *);


   int num=0,op;
   head=(struct node*)malloc(sizeof(struct node));
   head=NULL;

do{
   printf("select 0.quit 1.create 2.insert 3.delete 4.retrieve 5.print");
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

    if(op==3)
    {
        printf("enter the value to be deleted  ");
        scanf("%d", &num);
        head=delet(head,head,num);
    }

    if(op==4)
    {
        retrieve(head);
    }

    if(op==5)
    {
        print(head);
    }
}while(op!=0);

return 0;
}


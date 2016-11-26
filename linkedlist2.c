#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node *delet(struct node* ,struct node*, int key);
struct node *insert(struct node *,struct node*,int);
void print(struct node*);
struct node* create(struct node *);
int k=2;

struct node
{
    int n;
    struct node *link;
    struct node *ll;

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
     list->ll=NULL;
     head=list;

     }
}
return(head);
}

struct node *insert(struct node* list, struct node *head, int num)
{
    struct node* nw;
    nw=(struct node*)malloc(sizeof(struct node));
    nw->n=num;

    while(list->link!=NULL)
       {
           if(list->n<num && list->link->n>num)
           {
                nw->link=list->link;
                (list->link)->ll=nw;
                nw->ll=list;
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
             list->link=nw;
             nw->ll=list;
             nw->link=NULL;
             list=head;
             }

  }



     return list;
}

struct node *delet(struct node* list,struct node* head, int key)
{
    struct node *p;

while(list->link!=NULL)
{

    if(head->n==key)
     {
      p=head->link;
      p->ll=NULL;
      free(head);
      head=p;
      return head;
     }

    if(list->link->n==key&&list->link->link!=NULL)
     {
      p=list->link;
      list->link=p->link;
      p->link->ll=list;
      free(p);
      return head;
     }

    else list=list->link;

        if(list->link==NULL && list->n==key)
    {
        list->ll->link=NULL;
    }

  }

return head;
}

void search(struct node* head, struct node *list)
{
    int num;
    printf("enter number to be searched ");
    scanf("%d",&num);

            if(head->n==num)
        {
         printf(" 1 ");
         return;
        }


    while(list->link!=NULL)
    {

        if(list->link->n==num)
        {
            printf("%d",k);
            return;
        }

        else
        {
            k++;
            list=list->link;
            continue;
        }
    }

    printf("invalid search");
}

void print(struct node* list)
{
    if(list->link==NULL)
     {
         printf("%d ",list->n);
         return;
     }

else printf("%d ",list->n);
print(list->link);

  return;
}

int main()
{

   int num=0,op;
   head=(struct node*)malloc(sizeof(struct node));
   head=NULL;

do{
   printf("select 0.quit 1.create 2.insert 3.delete 4.print 5.search");
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
            head->ll=nw;
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
        print(head);
    }

    if(op==5)
    {
        k=2;
        search(head,head);
    }
}while(op!=0);

return 0;
}

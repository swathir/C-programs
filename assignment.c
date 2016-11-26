#include<stdio.h>
#include<malloc.h>

struct list
{
    int a;
    struct list *ptr;
}*head1=NULL,*head2=NULL,*tail1=NULL,*tail2=NULL,*head=NULL,*tail=NULL,*temp1=NULL,*temp2=NULL;
int no_of_nodes_1=0;
int no_of_nodes_2=0;
int insert(int no,int val)
{
    if(no==1)
    {
        if(head1==tail1 && head1==NULL)
        {

            head1= (struct list *) malloc(sizeof(struct list));
            head1->a = val;
            head1->ptr=NULL;
            tail1 = head1;
        }
        else
        {
            if(val<tail1->a)
            {
                printf("\n not in ascending order cant add\n");
                return;
            }
            temp1=tail1;
            tail1 = (struct list*) malloc(sizeof(struct list));
            tail1->a = val;
            tail1->ptr=NULL;
            temp1->ptr=tail1;
        }
       no_of_nodes_1++;
      printf("\n Element added to list one\n");
    }
    else if(no==2)
    {
        if(head2==tail2 && head2==NULL)
        {

            head2= (struct list *) malloc(sizeof(struct list));
            head2->a = val;
            head2->ptr=NULL;
            tail2 = head2;
        }
        else
        {
            if(val<tail2->a)
            {
                printf("\n not in ascending order cant add\n");
                return;
            }
            temp2=tail2;
            tail2 = (struct list*) malloc(sizeof(struct list));
            tail2->a = val;
            tail2->ptr=NULL;
            temp2->ptr=tail2;
        }
       no_of_nodes_2++;
      printf("\n Element added to list two\n");
    }

}

void merge()
{
    temp1=head1;
    temp2=head2;
    int flag=0;
    int nop=0;
    while(1)
    {
        if(flag==0)

        {
            if(temp1->a < temp2-> a && nop==0)
            {
                head = temp1;
                tail= temp1;
                temp1=temp1->ptr;
                if(temp1==NULL)
                flag=1;
            }
            else if(temp1->a>temp2->a && nop==0)
            {
                head = temp2;
                tail=temp2;
                temp2=temp2->ptr;
                if(temp2==NULL)
                flag=2;
            }
            else if(temp1->a<temp2->a)
            {
                tail->ptr=temp1;
                tail=temp1;
                temp1=temp1->ptr;
                if(temp1==NULL)
                flag=1;
            }
            else if(temp1->a>temp2->a)
            {
                tail->ptr=temp2;
                tail=temp2;
                temp2=temp2->ptr;
                if(temp2==NULL)
                flag=2;
            }
        }
        if(flag==1)
        {
            tail->ptr=temp2;
            tail=temp2;
            temp2=temp2->ptr;
            if(temp2==NULL)
            break;
        }
        if(flag==2)
        {
            tail->ptr=temp1;
            tail=temp1;
            temp1=temp1->ptr;
            if(temp1==NULL)
            break;
        }
        nop++;
    }
    tail->ptr=NULL;
    printf("\nMerged.. \n");

}

void display()
{

    temp1=head;
    printf("\n Contents of merged list\n");
    while(temp1->ptr!=NULL)
    {
        printf("\t%d",temp1->a);
        temp1=temp1->ptr;
    }
    printf("\t%d\n",temp1->a);
}
void display1()
{
    temp1=head1;
    printf("\n Contents of list 1\n");

    while(temp1->ptr!=NULL)
    {
        printf("\t%d",temp1->a);
        temp1=temp1->ptr;
    }
    printf("\t%d\n",temp1->a);
}

void display2()
{
    temp1=head2;
    printf("\n Contents of list 2\n");

    while(temp1->ptr!=NULL)
    {
        printf("\t%d",temp1->a);
temp1=temp1->ptr;
    }
    printf("\t%d\n",temp1->a);
}


void main()
{
    int op,listno,val;
    do
    {
          printf("\n1.Insert\n2.Merge\nEnter option:\n");
          scanf("%d",&op);
          if(op==1)
           {printf("\n Enter the list no \n");
           scanf("%d",&listno);
           if(listno>2||listno<1)
             continue;
           printf("\n Enter the value to insert\n");
           scanf("%d",&val);
           insert(listno,val);
           }
           if(op==2)
           {
               if(no_of_nodes_2==0&& no_of_nodes_1==0)
               {
                   printf("\n Cant merge as no nodes exist");op==1;}
                   else
                   {

                       display1();
                       display2();
                    merge();
                    display();
           }
    }
    }while(op<2);
}

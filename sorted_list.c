#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
void dispaly(struct node *start);
//struct node *Call_sort_k_number(int k,struct node *start);
main()
{
    int i,n,x;
    struct node *start;
    start=NULL;
    printf("Enter no. of elements\n");
    scanf("%d",&n);
    printf("Enter the element to be inserted\n");
    scanf("%d",&x);
    start=addatbeg(start,x);
    for(i=2;i<=n;i++)
    {
        printf("Enter element to be inserted\n");
        scanf("%d",&x);
        start=addatend(start,x);
    }
    //start=Call_sort_k_number(n,start);
    display(start);
}
struct node *addatbeg(struct node *start,int data)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=start;
    start=tmp;
    return start;
}
struct node *addatend(struct node *start,int data)
{
    struct node *tmp,*p;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    p=start;
    while(p->link!=NULL)
    {
        p=p->link;
    }
    tmp->link=NULL;
    p->link=tmp;
    return start;
}
void display(struct node *start)
{
    struct node *p;
    if(start==NULL)
    {
        printf("list is empty");
    }
    p=start;
    while(p!=NULL)
    {
        printf("->%d ",p->info);
        p=p->link;
    }
}
/*struct node *Call_sort_k_number(int k,struct node *start)
{
    struct node *p,*q;
    int x;
    p=start;
    q=p->link;
    while(p->link!=NULL)
    {
        while(q!=NULL)
        {
            if(p->info == q->info)
            {
                x=p->info;
                p->info=q->info;
                q->info=x;
            }
        }
        p=p->link;
        q=p->link;
    }
    return start;
}*/

#include<stdio.h>
#include<conio.h>
struct node
{
    float cgpa;
    char name;
    struct node *link;
};
struct node *fun(struct node *start,int n);
struct node *add(struct node *start,float f,char c);
struct node *addatbeg(struct node *start,float f,char c);
void display(struct node *start);
main()
{
    int n,f,c;
    struct node *start;
    start=NULL;
    printf("Enter no. of candidtaes\n");
    scanf("%d",&n);
    start=fun(start,n);
    display(start);
}
struct node *fun(struct node *start,int n)
{
    float f;
    char c;
    int i;
    struct node *p;
        printf("Enter cgpa\n");
        scanf("%f",&f);
        printf("Enter name\n");
        scanf("%c",&c);
        start=addatbeg(start,f,c);
        for(i=2;i<=n;i++)
        {
        printf("Enter cgpa\n");
        scanf("%f",&f);
        printf("Enter name\n");
        scanf("%c",&c);
        p=start;
        while(p->link!=NULL && f > p->cgpa )
        {
            start=add(start,f,c);
        }

        }
}
struct node *addatbeg(struct node *start,float f,char c)
{
    struct node *tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->cgpa=f;
    tmp->name=c;
    tmp->link=start;
    start=tmp;
    return start;
}
struct node *add(struct node *start,float f,char c)
{
    struct node *tmp,*p;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->cgpa=f;
    tmp->name=c;
    p=start;
    while(p->link!=NULL)
    {
        p=p->link;
    }
    tmp->link=p->link;
    p->link=tmp;
    return start;
}
void display(struct node *start)
{
    struct node *p;
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    p=start;
    while(p!=NULL)
    printf("%f %c ",p->cgpa,p->name);
}

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *lchild;
    struct node *rchild;
};
struct node *insert(struct node *ptr,int ikey);
void inorder(struct node *ptr);
main()
{
    int n,i,x;
    struct node *root;
    root=NULL;
    printf("Enter no. of nodes\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    printf("Enter value to be inserted\n");
    scanf("%d",&x);
    root=insert(root,x);
    printf("%d is inserted\n",x);
    }
    printf("BST is\n");
    inorder(root);
}
struct node *insert(struct node *ptr,int ikey)
{

    if(ptr == NULL)
    {
        struct node *ptr;
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->info=ikey;
        ptr->lchild=NULL;
        ptr->rchild=NULL;
    }

    else if(ikey < ptr->info)
    ptr->lchild=insert(ptr->lchild,ikey);
    else if(ikey > ptr->info)
    ptr->rchild=insert(ptr->rchild,ikey);
    else if(ikey == ptr->info)
    printf("duplicate key\n");
    return ptr;
}
void inorder(struct node *ptr)
{
    if(ptr==NULL)
    return;
    inorder(ptr->lchild);
    printf("%d ",ptr->info);
    inorder(ptr->rchild);
}

 #include<stdio.h>
 #include<conio.h>
 #include<malloc.h>

 #define max 10

 struct node
 {
   int vertex;
   struct node *next;
 };
 typedef struct node* nodeptr;
 typedef struct queue
 {
  int front,rear;
  int arr[max];
 };
 typedef struct stack
 {
  int top;
  int arr[max];
 };
 nodeptr getnode()
 {
  nodeptr p;
  p=(nodeptr)malloc(sizeof(struct node));
  p->next=NULL;
  return p;
 }

  int empty(struct stack *s)
  {
   if(s->top==-1)
   {
   return 1;
   }
   else
   return 0;
  }
  void push(struct stack *s,int x)
  {
  if(s->top==max-1)
  printf("\n Queue Overflow");
  else
  {
 s->top++;
 s->arr[s->top]=x;
  }
  }
  int pop(struct stack *s)
  {
  int x;
  if(empty(s))
   printf("\n Queue Underflow..!");
  else
  {
   x=s->arr[s->top];
   s->top--;
  }
  return x;
  }

  int qempty(struct queue *q)
  {
  if(q->front > q->rear)
  return 1;
  else
  return 0;
  }
  void insertq(struct queue *q,int x)
  {
  if(q->rear==max-1)
   printf("\n Queue Overflow..!");
  else
  {
  q->rear++;
  q->arr[q->rear]=x;
  }
  }
  int removeq(struct queue *q)
  {
   int x;
   if(qempty(q))
 printf("\n Queue Underflow..!");
   else
   {
   x=q->arr[q->front];
   q->front++;
   }
   return x;
  }

  void init(nodeptr head[],int n)
  {
  int v;
  for(v=1;v<=n;v++)
  head[v]=NULL;
  }
  void initialise_visit(int visited[],int n)
  {
  int i;
  for(i=1;i<=n;i++)
   visited[i]=0;
  }

    void create(nodeptr head[])
  {
  nodeptr adj;
  char ch='y';
  int i,v1,v2,v,c;
  nodeptr new1,p;
  printf("\n <0>Directed");
  printf("\n <1>UnDirected");
  printf("\n Enter Your Choice:\t");
  scanf("%d",&c);

  do
  {
  printf("\n Enter The Edge Between Two Vertices:\t");
  scanf("%d%d",&v1,&v2);
  new1=getnode();
  new1->vertex=v2;
  p=head[v1];
  if(p==NULL)
  head[v1]=new1;
  else
  {
  while(p->next!=NULL)
   p=p->next;
   p->next=new1;
  }
  if(c==1)
  {
 new1=getnode();
 new1->vertex=v1;
 p=head[v2];
 if(p==NULL)
  head[v2]=new1;
 else
 {
   while(p->next!=NULL)
    p=p->next;
    p->next=new1;
 }
  }
  printf("\n Do You Want To Add More Edges In Graph(y/n):\t");
  ch=getche();
  }while(ch=='y'||ch=='Y');
  }

  void display(nodeptr head[],int n)
  {
  int v;
  nodeptr adj;
  printf("\n Adjancency List Is:\n");
  for(v=1;v<=n;v++)
  {
   printf("\n Head[%d]->",v);
   adj=head[v];
   while(adj!=NULL)
   {
  printf("%d  ",adj->vertex);
  adj=adj->next;
   }
   printf("\n");
  }
  }

  void DFSR(nodeptr head[],int start,int visited[])
  {
  nodeptr adj;
  visited[start]=1;
  printf("\t %d",start);
  adj=head[start];
  while(adj!=NULL)
  {
   if(visited[adj->vertex]==0)
   {
  DFSR(head,adj->vertex,visited);
   }
   adj=adj->next;
  }
  }


  void BFS(nodeptr head[],int start,int visited[])
  {
  nodeptr adj;
  struct queue q;
  int v;
  q.front=0;
  q.rear=-1;
  visited[start]=1;
  printf("\n %d",start);
  insertq(&q,start);
  while(!qempty(&q))
  {
  v=removeq(&q);
  adj=head[v];
  while(adj!=NULL)
  {
 if(visited[adj->vertex]==0)
 {
   visited[adj->vertex]=1;
     insertq(&q,adj->vertex);

   printf("\t %d",adj->vertex);
 }
 adj=adj->next;
  }
  }
  }
  void main()
  {
  char c='y';
  int ch,start,n,visited[10];
  nodeptr head[10];

  do
  {

 printf("\n        Graph         \n\n");
 printf("\n 1. Create");
 printf("\n 2. Display Adjancency List");
 printf("\n 3. Depth First Search");
 printf("\n 4. Breadth First Search");
 printf("\n 5. Exit");
 printf("\n\n");
 printf("\n Enter Your Choice:\t");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 printf("\n Enter The No. of Vertices In Graph:\t");
 scanf("%d",&n);
 init(head,n);
 create(head);
 break;

 case 2:
 display(head,n);
 break;

 case 3:
 printf("\n Enter The Vertex From Which You Want To Start Traversal");
 scanf("%d",&start);
 initialise_visit(visited,n);
 printf("\n Depth First Search Is\n");
 DFSR(head,start,visited);
 break;

 case 4:
 printf("\n Enter The Vertex From Which You Want To Start Traversal");
 scanf("%d",&start);
 initialise_visit(visited,n);
 BFS(head,start,visited);
 break;

 case 5:
 break;
 }
 printf("\n Do You Want To Continue(y/n):\t");
 c=getche();
 }while(c=='Y'||c=='y');
  getch();
}


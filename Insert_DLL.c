#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct dlist
{
    int info;
    struct dlist *next,*prev;
};

typedef struct dlist node;
void create(node **,node **);
void display(node *,node *);
void insert(node **, node **,int,int);
main()
{
    node *s = NULL,*l = NULL;
    int num,pos;
    create(&s,&l);
    printf("DLL Created:\n");
    display(s,l);
    printf("Enter the number and position:");
    scanf("%d %d",&num,&pos);
    insert(&s,&l,num,pos);
    printf("New DLL:\n");
    display(s,l);
}
void create(node **s,node **l)
{
    node *nn;
    int num;
    char ano = 'y';
    while(ano == 'y')
    {
        printf("Enter the number:");
        scanf("%d",&num);                               //Do not use %d\n in create for preventing the input error while 'continue' execution.Newline Error
        nn = (node *)malloc(sizeof(node));
        nn -> info = num;
        nn -> next = NULL;
        if (*s == NULL){
            nn->prev=NULL;
            *s = nn;
        }
        else{
            (*l)->next = nn;
            nn->prev=*l;
        }
        *l = nn;
        printf("Continue[y/n]?");
        fflush(stdin);
        scanf("%c",&ano);
    }
}
void display(node *s,node *l)
{
    node *temp = s;                                 //temp should be initialized by s and l for printing the elements.
    printf("Forward Printing:\n ");
    while(temp!=NULL){
        printf("%d ",temp->info);
        temp = temp ->next;
    }
    printf("\n");
    temp = l;
    printf("Backward Printing:\n");
    while(temp!=NULL){
        printf("%d ",temp->info);
        temp = temp->prev;
    }
    printf("\n");
}
void insert(node **s,node **l,int n,int p)
{
    node *nn,*temp;
    int i;
    nn = (node *)malloc(sizeof(node));
    nn -> info = n;
    nn -> next = NULL;
    if (p == 1 || *s ==NULL){
        nn -> next = *s;
        nn -> prev = NULL;
        if(*s!=NULL){
            (*s) -> prev = nn;

        }
        else{
            (*l) = nn;

        }
        *s = nn;
    }
    else{
        temp = *s;
        i = 2;
        while(i<=p-1 && temp->next != NULL){
            i++;
            temp = temp ->next;
        }
        nn -> next = temp -> next;
        nn -> prev= temp;
        if(temp -> next!=NULL){
            temp ->next->prev = nn;
        }
        else{
            *l =nn;
        }
        temp-> next =nn;
    }
}

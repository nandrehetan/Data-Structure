#include <stdio.h>
#include <malloc.h>

struct node{
    int data;
    struct node *next;
};
struct node* create(struct node*, int);

int main()
{
    struct node *head, *p;
    head= (struct node *)malloc(sizeof(struct node));
    int n,i;

    printf("Enter number of nodes");
    scanf("%d", &n);
    head= NULL;

    head= create(head,n);
    p=head;

    for(i=0;i<n;i++)
    {
        printf("%d", p->data);
        p=p->next;
    }
}

struct node *create(struct node *head, int n)
{
    struct node *p;
    int i;

    head= (struct node *)malloc(sizeof(struct node));

    printf("Enter 1st value");
    scanf("%d", head->data);

    head->next= NULL;
    //printf("%d-Head Data", head->data);
    p=head;

    for(i=0; i<n; i++)
    {
        p->next = (struct node *)malloc(sizeof(struct node));
        printf("Enter data");
        scanf("%d", p->data);
        p=p->next;

    }
    p->next= NULL;
    return(head);
}

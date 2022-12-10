#include <stdio.h>
#include <stdlib.h>

struct node{
    float coeff;
    int expo;
    struct node* link;
};

struct node* insert(struct node* head, float coeff, int expo)
{
    struct node* temp;
    struct node* new = malloc(sizeof(struct node));
    new->coeff = coeff;
    new->expo  = expo;
    new->link  = NULL;

    if(head == NULL || expo > head->expo)
    {
        new->link = head;
        head = new;
    }
    else
    {
        temp = head;
        while(temp->link != NULL && temp->link->expo >=expo)
            temp = temp->link;
            new->link = temp->link;
            temp->link = new;
    }
    return head;
}

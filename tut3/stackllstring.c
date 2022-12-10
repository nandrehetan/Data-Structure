#include <stdio.h>
#include <malloc.h>
#define MAX 100
 struct node
{
    char * data;
    struct node * next;
}* stack= NULL;
char* pop(){
    struct node *next = stack->next;
    char * c = stack->data;
    // printf("%c\n",stack->data);
    stack = next;
    return c;
}
void push(char * n){
    struct node *next = (struct node *) malloc(sizeof(struct node));
    next->data = n;
    next->next = stack;
    stack = next;
}
void display(){
    struct node *temp;
    temp = stack;
    if (temp != NULL){
        while(temp != NULL){
            printf("data is : %s\n",temp->data);
            temp = temp->next;
        }
    }
}

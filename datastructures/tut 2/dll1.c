#include <stdio.h>
#include <malloc.h>
 struct node
{
    int data;
    struct node * previous;
    struct node * next;

};
struct dll{
    struct node * head;
    struct node * last;
};
struct dll create(struct dll a, int n){
    a.head = (struct node *) malloc(sizeof(struct node));
    a.head->data = n;
    a.head->next = NULL;
    a.head->previous = NULL;
    a.last = a.head;
    return a;
}
struct dll insert_last(struct dll a,int n){
    struct node *next = (struct node *) malloc(sizeof(struct node));
    next->data = n;
    next->previous = a.last;
    a.last->next = next;
    a.last = next;
    return a;
}
void display(struct dll a){
    struct node *temp;
    temp = a.head;
    if (temp != NULL){
        while(temp != NULL){
            printf("data is : %d\n",temp->data);
            temp = temp->next;
        }
    }
}
int main() {
    struct dll a;
  a = create(a,10);
  a = insert_last(a,15);
  a = insert_last(a,25);
  a = insert_last(a,35);
  a = insert_last(a,45);
  printf("%d",a.last->data);
  display(a);
  return 0 ;
}

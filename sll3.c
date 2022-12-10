#include <stdio.h>
#include <malloc.h>
 struct node
{
    int data;
    struct node * next;

};
struct sll{
    struct node * head;
    struct node * last;
};
struct sll create(struct sll a, int n){
    a.head = (struct node *) malloc(sizeof(struct node));
    a.head->data = n;
    a.head->next = NULL;
    a.last = a.head;
    return a;
}
struct sll insert_last(struct sll a,int n){
    struct node *next = (struct node *) malloc(sizeof(struct node));
    next->data = n;
    a.last->next = next;
    a.last = next;
    return a;
}
void display(struct sll a){
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
    struct sll a;
  a = create(a,10);
  a = insert_last(a,15);
  a = insert_last(a,25);
  a = insert_last(a,35);
  a = insert_last(a,45);
  printf("%d",a.last->data);
  display(a);
  return 0 ;
}

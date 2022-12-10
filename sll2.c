#include <stdio.h>
#include <malloc.h>
 struct node
{
    int data;
    struct node * next;

}* head,*last;
void create(int n){
    head = (struct node *) malloc(sizeof(struct node));
    head->data = n;
    head->next = NULL;
    last = head;
}
void insert_last(int n){
    struct node *next = (struct node *) malloc(sizeof(struct node));
    next->data = n;
    last->next = next;
    last = next;
}
void display(){
    struct node *temp;
    temp = head;
    if (temp != NULL){
        while(temp != NULL){
            printf("data is : %d\n",temp->data);
            temp = temp->next;
        }
    }
}
int main() {
  create(10);
  insert_last(15);
  display();
  return 0 ;
}

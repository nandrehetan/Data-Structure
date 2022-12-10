#include <stdio.h>
#include <malloc.h>
 struct node
{
    int data;
    struct node * next;
}* stack= NULL;
void pop(){
    struct node *next = stack->next;
    printf("%d\n",stack->data);
    stack = next;
}
void push(int n){
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
            printf("data is : %d\n",temp->data);
            temp = temp->next;
        }
    }
}
int main() {
//   create(10);
  push(15);
  push(1);
  push(13);
  push(12);
  push(23);
  pop();
  display();
  return 0 ;
}

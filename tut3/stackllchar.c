 
#include <stdio.h>
#include <malloc.h>
 struct node
{
    char data;
    struct node * next;
}* stack= NULL;
char pop(){
    struct node *next = stack->next;
    char c = stack->data;
    // printf("%c\n",stack->data);
    stack = next;
    return c;
}
void push(char n){
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
            printf("data is : %c\n",temp->data);
            temp = temp->next;
        }
    }
}
int main() {
//   create(10);
    char q,c[10] = "testachar";
  push(c[4]);
  push(c[5]);
  push(c[6]);
  // push(1);
  // push(13);
  // push(12);
  // push(23);
  printf("%c",pop());
  display();
  return 0 ;
}

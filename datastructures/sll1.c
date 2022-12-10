#include <stdio.h>
#include <malloc.h>
 struct node
{
    int data;
    struct node * next;

}* head;

void create(int n){
    head = (struct node *) malloc(sizeof(struct node));
    head->data = n;
    head->next = NULL;
}
// void insert_last(int n){
//     struct node *next = (struct node *) malloc(sizeof(struct node));
//     printf("Enter value ");
//     scanf("%d",&next->data);
//     printf("1");
//     last->next = next;
//     printf("1");
//     last = next;
//     printf("1");
// }
void display(){
    struct node *temp;
    temp = head;
    if (temp != NULL){
        while(temp != NULL){
            printf("data is : %d",temp->data);
            temp = temp->next;
        }
    }
}
int main() {
  create(10);
  display();
  return 0 ;
}

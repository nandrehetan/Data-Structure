#include <stdio.h>
#include <malloc.h>
 struct node
{
    int data;
    struct node * next;

};
struct node * head = NULL;
struct node * last = NULL;
void create(int n){
    struct node *head = (struct node *) malloc(sizeof(struct node));
    printf("Enter value ");
    scanf("%d",&head->data);
    printf("1");
    head->next = NULL;
    printf("1");
    last = head;
    printf("1");
}
void insert_last(int n){
    struct node *next = (struct node *) malloc(sizeof(struct node));
    printf("Enter value ");
    scanf("%d",&next->data);
    printf("1");
    last->next = next;
    printf("1");
    last = next;
    printf("1");
}
int main() {
  create(10);
  insert_last(20);
  printf("1");
  printf("%d",head->data);
  printf("%d",(head->next)->data);
  return 0 ;
}

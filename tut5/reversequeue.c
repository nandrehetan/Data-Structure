#include<stdio.h>
# define MAX 5
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

int cqueue_arr[MAX];
int front = -1;
int rear = -1;
void insert(int item)
{
    if((front == 0 && rear == MAX-1) || (front == rear+1)){
            printf("Queue Overflow \n");
            return;
    }

    if(front == -1){
        front = 0;
        rear = 0;
    }
    else
{
if(rear == MAX-1)
rear = 0;
else
rear = rear+1;
}
cqueue_arr[rear] = item ;
}
int deletion()
{
if(front == -1)
{
printf("Queue Underflown");
return -1;
}
int a = cqueue_arr[front];
// printf("Element deleted from queue is : %dn",cqueue_arr[front]); test
if(front == rear)
{
front = -1;
rear=-1;
}
else
{
if(front == MAX-1)
front = 0;
else
front = front+1;
}
return a;
}
void display()
{
int front_pos = front,rear_pos = rear;
if(front == -1)
{
printf("Queue is empty\n");
return;
}
printf("Queue elements :");
if( front_pos <= rear_pos )
while(front_pos <= rear_pos)
{
printf("%d ",cqueue_arr[front_pos]);
front_pos++;
}
else
{
while(front_pos <= MAX-1)
{
printf("%d ",cqueue_arr[front_pos]);
front_pos++;
}
front_pos = 0;
while(front_pos <= rear_pos)
{
printf("%d ",cqueue_arr[front_pos]);
front_pos++;
}
}
}
int main()
{
int choice,item;
printf("\n1.Insert\n");
printf("\n2.Delete\n");
printf("\n3.Display\n");
printf("\n4.reverse\n");
printf("\n5.quit\n");
do
{
printf("Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 :
printf("Input the element for insertion in queue : ");
scanf("%d", &item);
insert(item);
break;
case 2 :
    printf("%d",deletion());
break;
case 3:
display();
break;
case 4:
    while (front!=-1){
        push(deletion());
    }
    while(stack != NULL){
        pop();
    }
    break;
default:
    printf("Wrong choice\n");
}
}while(choice!=5);
return 0;
}

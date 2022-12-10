#include <stdio.h>
# define max 10
int queue[max];
int front=-1;
int rear=-1;
void enqueue(int element){
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
        queue[rear]=element;
    }
    else if((rear+1)%max==front){
        printf("Queue is overflow..");
    }
    else{
        rear=(rear+1)%max;
        queue[rear]=element;
    }
}

int dequeue(){
    if((front==-1) && (rear==-1)){
        printf("\nQueue is underflow..");
    }
 else if(front==rear){
    int r = queue[front];
    front=-1;
    rear=-1;
    return r;
}
else{
    int r = queue[front];
    front=(front+1)%max;
    return r;
}
return 0;
}
void display(){
    int i=front;
    if(front==-1 && rear==-1){
        printf("\n Queue is empty..");
    }
    else{
        printf("\nElements in a Queue are :");
        while(i<=rear)
        {
            printf("%d,", queue[i]);
            i=(i+1)%max;
        }
    }
}
int main(){
    int choice=1,x;
    printf("\n Press 1: Insert ");
    printf("\n Press 2: Delete ");
    printf("\n Press 3: Display");
    while(choice<4 && choice!=0){
        printf("Enter your choice - ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("enter the element which is to be inserted - ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                printf("the element dequed is %d \n",dequeue());
                break;
            case 3:
            display();
        }
    }
    return 0;
}

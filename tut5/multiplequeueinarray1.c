#include <stdio.h>
int power(int base,int exponent){
    int i = 0,res=1;
    while (i <=exponent){
        res*=base;
        i++;
    }
    return res;
}
int initpos(int x,int n ,int m){
    return(((x%2)+(x/2))*((n+1)/(m+1))*2)-(x%2);
}
int rpair(int x,int m){
    if (x == m & x%2 ==0){
        return x;
    }else if (x%2 ==0){
        return x+1;
    }else{
        return x-1;
    }
}
void innit(int front[],int rear[],int m,int n){
    int x = 0;
    while (x <= m){
        front[x] = initpos(x,n,m);
        rear[x]= -1;
        x++;
    }
}
void enqueue(int x,int y,int queue[],int front[],int rear[],int n,int m){
    if (rear[x]==-1){
        front[x] = initpos(x,n,m);
        rear[x]=front[x];
        queue[front[x]]= y;
        front[x] = front[x] -power(-1,x);
    }
    else if(front[x]==front[rpair(x,m)] &&x!=rpair(x,m)){
        printf("overflow");
    }else if(x==rpair(x,m) && front[x]>=m){
        printf("overflow");
    }else{
        queue[front[x]]= y;
        front[x] = front[x] -power(-1,x);
    }
}
int dequeue(int x,int queue[],int front[],int rear[],int n,int m){
    int d = queue[rear[x]];
    if(rear[x]- front[x]==1 ||front[x]-rear[x]==1){
        rear[x] = -1;
        front[x]=initpos(x,n,m);
    }else{
        rear[x]= rear[x]+power(-1,x+1);
    }
    return d;
}
int main(){
    int choice=1,x,y,m,n;
    printf("Enter size - ");   // n = size , m is number of arrays
    scanf("%d", &n);
    printf("Enter number of queues - ");
    scanf("%d", &m);m--;n--;
    int queue[n],front[m],rear[m];
    innit(front,rear,m,n);
    printf("\n Press 1: Insert ");
    printf("\n Press 2: Delete ");
    printf("\n Press 3: Exit");
    while(choice!=3){
        printf("Enter your choice - ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("enter the array in which element is to be inserted - ");
                scanf("%d", &x);x--;
                printf("enter the element which is to be inserted - ");
                scanf("%d", &y);
                enqueue(x,y,queue,front,rear,n,m);
                break;
            case 2:
                printf("enter the array from which element is to be removed - ");
                scanf("%d", &x);x--;
                if (rear[x]!=-1){
                    x = dequeue(x,queue,front,rear,n,m);
                    printf("the element dequed is %d \n",x);
                }
                break;
            case 3:
                printf("code compiled");
        }
    }
    return 0;
}

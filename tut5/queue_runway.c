#include <stdio.h>
# define max 24
void enqueue(int queue[],int rear,int front,int element){
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
        queue[rear]=element;
    }
    else if((rear+1)==max){
        printf("Queue is overflow..");
    }
    else{
        rear=rear+1;
        queue[rear]=element;
    }
}

int dequeue(int queue[],int rear,int front){
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
    front=front+1;
    return r;
}
return 0;
}

void display(int queue[],int rear,int front){
    int i=front;
    if(front==-1 && rear==-1){
        printf("\n Queue is empty..");
    }
    else{
        printf("\nElements in a Queue are :");
        while(i<=rear){
            printf("%d,", queue[i]);
            i=(i+1)%max;
        }
    }
}
// enqueue(queue,front,rear,x);
// printf("the element dequed is %d \n",dequeue(queue,front,rear));
int main(){
    int queue1[max],queue2[max],front1=-1,rear1=-1,front2=-1,rear2=-1,timeentery[24]= {0,0,0,3,3,3,6,6,6,9,9,9,12,12,12,15,15,15,18,18,18,21,21,21},timeexit[24], time=0,timechange=3,indexl[max], indext[max],a=0,b=0,tnext=0,t=0,n,i=0,x=0,y=0,totalWaitTime=0,countLandedFlights=0,countTakeOffFlights=0;
    char enteries[] = "lttllttlltltlttlltlllttt",l[]="lt";
    while (i < 24){
        if (enteries[i]==l[0]){
            indexl[x]=i;
            x++;
        }else{
            indext[y]=i;
            y++;
        }
        i++;
    }
    i=0;
    x=0;
    y=0;
    while (time<=24){
        while(timeentery[i]<=time){ //adding to queue
            if(enteries[i]==l[0]){
                enqueue(queue1,front1,rear1,x);
                x++;i++;
            }else{
                enqueue(queue2,front2,rear2,y);
                y++;i++;
            }
        }
        if(tnext==time){
            while (t!=2){
                if(front1!=rear1){
                    n = dequeue(queue1,front1,rear1);
                    timeexit[indexl[n]]=time+timechange;
                    totalWaitTime+=(timeexit[indexl[n]]-timeentery[indexl[n]])*5;
                    printf("At time t = %d, In Runway %d, plane with plane ID: %d  is landing after waiting %d minutes\n",time,t+1,n,totalWaitTime);
                    t+=1;
                    countLandedFlights+=1;
                }else{
                    n = dequeue(queue2,front2,rear2);
                    timeexit[indext[n]]=time+timechange;
                    totalWaitTime+=(timeexit[indext[n]]-timeentery[indext[n]])*5;
                    printf("At time t = %d, In Runway %d, plane with plane ID: %d is taking off after waiting %d minutes\n",time,t+1,n,totalWaitTime);
                    t+=1;countTakeOffFlights+=1;
                }
            }
            tnext+=timechange;
        }
        time+=1;
    }
    printf("\nTotal Wait Time = %d\n",totalWaitTime);
    printf("\nNumber Of flights landed = %d",countLandedFlights);
    printf("\nNumber of Flights taken off = %d",countTakeOffFlights);
    return 0;
}

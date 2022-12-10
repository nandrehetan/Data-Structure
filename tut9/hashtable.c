#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
int arr[9][2],max =9;

void display(){
    int i;
    printf("table contains - ");
    printf("\n index \t data \n");
    for(i=0;i<=max;i++){
        printf("\n%d \t%d \t%d \n",i,arr[i][0],arr[i][1]);
    }
}

void linear_probe(int key,int num){
    if(arr[key][0]== -1){
        arr[key][0]=num;
    }else{
        if(arr[key][1]== -1){
            arr[key][1]=num;
        }else{
        bool k = true ;
        int i=(key+1)%max;
        while(i!=key){
            if(arr[i][0]==-1){
                arr[i][0]=num;
                k= false;
                break;
            }
            if(arr[i][1]==-1){
                arr[i][1]=num;
                printf("collision resolved");
                k= false;
                break;
            }
            i=(i+1)%max;
        }
            if (k){
                printf("hash table is full");
                display();
            }
        }
    }
}

int main(){
    int i,key,num,input;
    for(i=0;i<=max;i++){
        arr[i][0]=-1;
        arr[i][1]=-1;
    }
    do{
        printf("enter the number");
        scanf("%d",&num);
        key=num%max;
        linear_probe(key,num);
        printf("press 1 to continue");
        scanf("%d",&input);
    }
    while(input==1);
    display();
    return 0;
}

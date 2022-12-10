#include<stdio.h>
#include<stdlib.h>
int arr[100],max =9;

void display()
{
    int i;
    printf("table contains - ");
    printf("\n index \t data \n");
    for(i=0;i,max;i++)
    {
        printf("\n%d \t%d \n",i,arr[i]);
    }
}

void linear_probe(int key,int num,int i)
{
    if(arr[key]== -1)
    {
        arr[key]=num;
    }
    else
    {
        printf("collision");
        i=(key+1)%max;
        while(i!=key)
        {
            if(arr[i]==-1)
            {
                arr[i]=num;
                printf("collision resolved");
                break;
            }
            i=(i+1)%max;
        }
    printf("hash table is full");
    display();
    }
}

int main()
{
    int i,key,num,input;
    for(i=0;i<max;i++)
    {
        arr[i]=-1;
    }
    do
    {
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

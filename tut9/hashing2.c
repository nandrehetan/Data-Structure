#include<stdio.h>
#include<stdlib.h>

int node;
int nv,ne;
int i , j ,s;
int visited[20];
int a[20][20];
int v1,v2;

int  hash[9][2] = {
       {0,0},{0,0},{0,0},
       {0,0},{0,0},{0,0},
       {0,0},{0,0},{0,0}
    };


struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int hash_fun(int e, int v)
{
    if(v < 9)
    {
        if(hash[v][0]==0)
    {
        hash[v][0] = e;
    }
    else if(hash[v][1]==0)
    {
        hash[v][1] = e;
    }
    else
    {
        hash_fun(e,v+1);
    }
    return 0;
    }

    else{
        printf("Hash table is full!!");
        return 1;
    }

}

int main(){

    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    int w1 = 1;
    int w2 = 1;
    int ch1,ch2;
    int no,e,v;


    while(w1==1)
    {
        printf("\nEnter your Choice\n1.Hashing \n2.Exit:\n");
        scanf("%d",&ch1);
        switch(ch1){
            case 1:
            printf("Hash Tables");
            printf("\nEnter the number of elements: ");
            scanf("%d",&no);
            int x = 0;
            for(int i=1;i<=no && x!=1;i++)
            {
                printf("Enter element %d: ",i);
                scanf("%d",&e);
                v = e%9;
                x = hash_fun(e,v);
            }
            printf("\nThe hash table is: \n");
            for(int i = 0;i<9;i++)
            {
                printf("%d  %d",hash[i][0],hash[i][1]);
                printf("\n");
            }
            break;

            case 2:
            printf("Exit!!");
            w1 = 0;
            break;

            default:
            printf("Invalid Choice!!");
            break;
        }
    }

return 0;
}

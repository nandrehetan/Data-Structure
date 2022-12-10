#include <stdio.h>
#define size 10
int n= 0;
void push(int * stack, int a){
    if (n <=size){
        stack[n] = a;
        n++;
    }else{
        printf("overflow");
    }
}
void pop(int * stack){
    if (n >0){
        n--;
        printf("%d\n",stack[n]);
    }
}
void display(int * stack){
    int a = n-1;
    while (a >0){
        printf("%d\n",stack[n]);
        a--;
    }
}
int main (){
    int stack[100],c,x;
    c = 0;
    while(c !=4){
        printf("enter 1 to push a value,\n2 to pop And\n3 to display the stack\n4 to exit\n");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("enter the value to push");
                scanf("%d",&x);
                push(stack,x);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                printf("Exiting the code");
                break;
            default:
                printf("invalid");
        }
    }
return 0;
}

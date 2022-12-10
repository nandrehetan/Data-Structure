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
    int stack[100];
    push(stack,10);
    push(stack,11);
    display(stack);
    push(stack,12);
    push(stack,13);
    push(stack,14);
    display(stack);
    push(stack,15);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    display(stack);
    pop(stack);
    pop(stack);
    pop(stack);

}

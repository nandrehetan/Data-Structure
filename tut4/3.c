#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#define max 5
int i = -1;
 struct node
{
    char data;
    struct node * previous;
}*stack;
// int isempty(struct stack * s){
//     if (s->top == -1)
//         return (1);
//     return (0);
// }
// int isfull(struct stack * s){
//     if (s->top == max-1)
//         return (1);
//     return (0);
// }
// char pop(struct stack * s){
//     if (!isempty(s)){
//         char c=s->data[s->top];
//         s->top--;
//         return(c);
//     }
// }
char pop(){
    if (i != -1){
        char c=stack->data;
        stack = stack->previous;
        i--;
        return(c);
    }
    else{
        char c = "0";
        return(c);
    }
}
void push(char n){
    if(i == max)
        printf("o");
    else if(i ==-1){
        stack = (struct node *) malloc(sizeof(struct node));
        stack->data = n;
        stack->previous = NULL;
        i++;
    }
    else{
        struct node * head = (struct node *) malloc(sizeof(struct node));
        head->data = n;
        head->previous = stack;
        stack = head;
        i ++;
    }
}
// void push(char n){
//     if(isempty(s))
//         s->top =-1;
//     if(!isfull(s)){
//         s->top++;
//         s->data[s->top] = n;
//     }
// }

// void display(struct stack * s){
//     int n= s->top;
//     while(n > 0){
//         printf("data is : %d\n",s->data[n]);
//         n--;
//     }
// }
int prec(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if( x=='%')
        return(3);
    if( x=='^')
        return(4);
    return 0;
}
char top(){
    return (stack->data);
}
void InfixtoPostfix(char Infix[], char Post[])
{
//     struct stack s;
    char x, temp;
    int i=0, j=0;
    for (i=0;Infix[i]!="/0"; i++)
    {
        temp = Infix[i];
        if(isalnum(temp))
        {
            Post[j++]=temp;
        }
        else if (temp == '(')
                push(temp);
        else if (temp == ')')
        {
            while((x=pop())!='(')
                Post[j++] = x;
        }
        else while(prec(temp)<=prec(top())){
            Post[j++]=pop();
            push(temp);}
    }
    while(i != -1)
    {
         Post[j++]=pop();
         Post[j]="/0";
    }

}
int main()
{
//     char infix[max], post[max];
//     printf("Infix operation is");
//     scanf("%s", infix);
//     InfixtoPostfix(infix, post);
//     printf("Postfix conversion is: %s",post);
    push("e");
    push("e");
    push("e");
    push("e");
    char c = "a";
    printf("%c v", c);
    c = pop();
    printf("3");
    c = pop();
    printf("%c v", c);

}

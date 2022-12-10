#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 10
int prec(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}
struct stack
{
    char data[MAX];
    int top;
};
void init(struct stack *s){
    s->top = -1;
}
int empty(struct stack *s)
{
    if (s->top==-1)
    return(1);
    return(0);
}
int full(struct stack *s)
{
    if(s->top==MAX-1)
    return(1);
    return(0);
}
char top(struct stack *s)
{
    return(s->data[s->top]);
}
void push(struct stack *s, char x)
{
    s->top=s->top+1;
    s->data[s->top]=x;
}
char pop(struct stack *s)
{
    char x;
    x=s->data[s->top];
    s->top=s->top-1;
    return(x);
}
void InfixtoPostfix(char Infix[], char Postfix[])
{
    struct stack s;
    int i, j;
    char e, x;

    i = 0, j = 0;
    e = Infix[i];
    while (e != '\0')
    {
        if (e == '(')
            push(&s,e);
        else if (isdigit(e) || isalpha(e))
        {
            Postfix[j++] = e;
        }

        else if (e == ')')
        {
            x = pop(&s);
            while (x != '(')
            {
                Postfix[j++] = x;
                x = pop(&s);
            }
        }else{
            x = pop(&s);
            while (prec(x) >= prec(e))
            {
                Postfix[j++] = x;
                x = pop(&s);
            }
            push(&s,x);
            push(&s,e);
        }
        e = Infix[++i];
    }
    Postfix[j] = '\0';
    while(!empty(&s))
    {
         Postfix[j++]=pop(&s);
    }
    Postfix[j]="\0";
}
int main()
{
    char infix[MAX], Post[MAX];
    printf("Infix operation is");
    scanf("%s", &infix);
    InfixtoPostfix(infix, Post);
    printf("Postfix conversion is: %s", Post);
}

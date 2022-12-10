#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
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
void InfixtoPrefix(char Infix[], char Prefix[])
{
    struct stack s;
    int i, j, l;
    char e, x;
    i = 0, j = 0;
    while (Infix[i] != '\0')
    {
        i++;
    }
    char Postfix[i];
    i--;
    e = Infix[i];
    while (i >= 0){
        // printf("%c",e);
        if (e == ')')
            push(&s,e);
        else if (isdigit(e) || isalpha(e))
        {
            Postfix[j++] = e;
        }

        else if (e == '(')
        {
            x = pop(&s);
            while (x != ')')
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

        e = Infix[--i];
    }
    while(!empty(&s))
    {
         Postfix[j++]=pop(&s);
    }
    Postfix[j]="\0";
    // printf("%s",Postfix);
    i = 0;
    j-=2;
    while (j>=0){
        Prefix[i] = Postfix[j];
        // printf("%c %d %d",Postfix[j],i,j);
        j--;
        i++;
    }
    Prefix[i]="\0";
    // printf("%s",Prefix);

}
int main()
{
    char infix[MAX], Pre[MAX];
    printf("Infix operation is");
    scanf("%s", &infix);
    InfixtoPrefix(infix, Pre);
    printf("Prefix conversion is: %s", Pre);
}

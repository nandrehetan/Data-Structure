#include<stdio.h>
#include <ctype.h>
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
void InfixtoPostfix(char * Infix, char *Post)
{
    struct stack s;
    char x, temp;
    int i=0, j=0;
    init(&s);
    for (i=0, Infix[i]!="\0"; i++;)
    {
        temp = Infix[i];
        if(isalnum(temp))
        {
            Post[j++]=temp;
        }
        else if(temp == '(')
        {
            push(&s, temp);
        }
        else if (temp == ')')
        {
            while((x=pop(&s))!=')')
                Post[j++] = x;
        }
        else while(prec(temp)<=prec(top(&s)))
            Post[j++]=pop(&s);
        push(&s,temp);
    while(!empty(&s))
    {
         Post[j++]=pop(&s);
         Post[j]="\0";
    }

}
}
int main()
{
    char infix[MAX], Post[MAX];
    printf("Infix operation is");
    scanf("%s", &infix);
    InfixtoPostfix(&infix, &Post);
    printf("Postfix conversion is: %s", Post);
}

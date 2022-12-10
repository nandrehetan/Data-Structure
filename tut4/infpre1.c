#include<stdio.h>
#include<ctype.h>

char stack[40];
int top = -1;

void push(char m)
{
    stack[++top] = m;
}
char pop()
{
    if(top == -1)
      return(-1);
    else
      return stack[top--];
}

int priority(char m)
{
    if(m =='(')
     return(0);
    if(m =='+'|| m =='_')
     return(1);
    if(m =='*'|| m =='/')
     return(2);


}

int main()
{
    char exp[40];
    char*e,m;
    printf(" the expresssion is:");
    scanf("%s",exp);
    printf("\n");
    e = exp;

    while(*e!='\0')
    {
        if(isalnum(*e))
          printf("%c",*e);
        else if(*e=='(')
          push(*e);
        else if(*e==')')
        {
            while((m = pop())!='(')
             printf("%c",m);
        }
        else
        {
            while(priority(stack[top])>=priority(*e))
              printf("%c",pop());
             push(*e);
        }
        e++;
     }

     while(top !=-1)
     {
         printf("%c",pop());
     }
     return 0;
}

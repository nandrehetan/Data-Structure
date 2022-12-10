#include<stdio.h>
#include<string.h>
void push(char ele);
char pop();
int isoperand(char);
void display();

char s[25]={'\0'};
int top=-1;
char ch;
int main()
{
	char postfix[25]={'\0'};
	char ele;
	int i,j;
	printf("\n Enter The PostfixExpression:");
	scanf("%s",postfix);

	i=0;
	while(i<strlen(postfix))
	{
		ele=postfix[i];
		if (isoperand(ele))
		{
			push(ele);
			push(' ');
			printf("\n ele= %c push to stack S ",ele);
		}

		else
		{
			printf("\n operator =%c",ele);
			for(j=top-1;j>=0;j--)
			{
				if(s[j]==' ')
				{
					s[j]=ele;
					break;

				}
			}
		}
		display();
		printf("\n---------------------------------\n");
			i++;

	}
	printf("\nPostfixExpression: %s",postfix);
	printf("\n Infix expression = %s", s);

}

void push(char ele)
{
	if(top==24)
	printf("\nStack is Full");
	else
	{
		top=top+1;
		s[top]=ele;
	}
}
char pop()
{
	if (top==-1)
	printf("\n Stack is Empty");
	else
	{
		ch=s[top];
		top--;
	}
	return ch;

}
int isoperand(char ele)
{
	if (ele>='A' && ele<='Z'|| ele>='a'&&ele<='z')
	{
		return 1;
	}
	else
	return 0;
}
void display()
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("\n s[%d]=%c",i,s[i]);
	}
}

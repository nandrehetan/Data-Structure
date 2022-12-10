 
#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
}*head,*newnode,*temp;
int pos;
int n;
void create();
void print();
void reverse();
int main()
{
	int num;
	printf("\n Lets create a linked list first \n");
    create();
    print();
    reverse();
    print();
return 0;
}
void create()
{
	printf("Enter the length of the list: ");
	scanf("%d",&n);
	struct node *newnode;
	head=0;
int i;
	for(i=0;i<n;i++)
{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data of node: ");
	scanf("%d",&newnode->data);
	newnode->next=0;
if (head==0)
{
	head=temp=newnode;
}
else {temp->next=newnode;
temp=newnode;
}
}
}
void print()
{
	temp=head;
	printf("\nThe list is:  \n");
	while(temp!=0)
	{
		printf("%d  ",temp->data);
			temp=temp->next;
	}

}
void reverse()
{
struct node *prevnode,*current,*nextnode;
prevnode=0;
current=nextnode=head;
while(nextnode!=0)
{
	nextnode=nextnode->next;
	current->next=prevnode;
	prevnode=current;
	current=nextnode;
}
	head=prevnode;
}

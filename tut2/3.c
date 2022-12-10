#include <stdio.h>
#include <malloc.h>
 struct node
{
    int coeff;
    int power;
    struct node * next;

};
struct sll{
    struct node * head;
    struct node * last;
};
struct sll create(struct sll a, int n,int m){
    a.head = (struct node *) malloc(sizeof(struct node));
    a.head->coeff = n;
    a.head->power = m;
    a.head->next = NULL;
    a.last = a.head;
    return a;
}
struct sll insert_last(struct sll a,int n,int m){
    struct node * next = (struct node *) malloc(sizeof(struct node));
    next->coeff = n;
    next->power = m;
    a.last->next = next;
    a.last = next;
    return a;
}
void display(struct sll a){
    struct node *temp;
    temp = a.head;
    if (temp != NULL){
        printf("%d*x^%d ",temp->coeff,temp->power);
        temp = temp->next;
        while(temp->next != NULL){
            if(temp->coeff >= 0){
                printf("+ %d*x^%d ",temp->coeff,temp->power);
                temp = temp->next;
            }
            else{printf(" %d*x^%d ",temp->coeff,temp->power);
                temp = temp->next;}
        }
        printf("+ %d \n",temp->coeff,temp->power);
    }
}
struct sll addd(struct sll a,struct sll b){
    struct node *temp,*temp1;
    struct sll c;
    char s;
    temp = a.head;
    temp1 = b.head;
    if (temp != NULL){
        c = create(c,temp->coeff+temp1->coeff,temp->power);
        temp = temp->next;
        temp1 = temp1->next;
        while(temp != NULL){
            c = insert_last(c,temp->coeff+temp1->coeff,temp->power);
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
    return c;
}
int main() {
    struct sll a,b,c;
    int x,y,i;
    printf("Enter the highest power of x ");
    scanf("%d",&y);
    printf("Enter polynomial a\n");
    i = y;
    printf("Enter coeffecient of x ^ %d ",i);
    scanf("%d",&x);
    a=create(a,x,i);
    i--;
    while (i >= 0){
        printf("x ^ %d ",i);
        scanf("%d",&x);
        a = insert_last(a,x,i);
        i--;
    }
    display(a);
    printf("Enter polynomial b\n");
    i = y;
    printf("Enter coeffecient of x ^ %d ",i);
    scanf("%d",&x);
    b = create(b,x,i);
    i--;
    while (i >= 0){
        printf("x ^ %d ",i);
        scanf("%d",&x);
        b = insert_last(b,x,i);
        i--;
    }

    c = addd(a,b);
    printf("Sum of \n");
    printf("    ");
    display(a);
    printf("and ");
    display(b);
    printf("is\n");

    display(c);
    return 0 ;
}

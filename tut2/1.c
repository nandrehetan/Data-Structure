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
        while(temp != NULL){
            printf("%d * x ^%d\n",temp->coeff,temp->power);
            temp = temp->next;
        }
    }
}

int main() {
    struct sll a,b,c;
    int x,y,i;
    printf("enter the highest power of x ");
    scanf("%d",&x);
    printf("enter polynomial a");
    i = x;
    printf("enter coeffecient of x ^ %d ",i);
    scanf("%d",&x);
    a=create(a,x,i);
    i--;
    while (i >= 0){
        printf("enter coeffecient of x ^ %d ",i);
        scanf("%d",&x);
        a = insert_last(a,x,i);
        i--;
    }
    display(a);
    printf("enter polynomial b");
    i = x;
    printf("enter coeffecient of x ^ %d ",i);
    scanf("%d",&x);
    b = create(b,x,i);
    i--;
    while (i >= 0){
        printf("enter coeffecient of x ^ %d ",i);
        scanf("%d",&x);
        b = insert_last(b,x,i);
        i--;
    }
    display(b);
    return 0 ;
}

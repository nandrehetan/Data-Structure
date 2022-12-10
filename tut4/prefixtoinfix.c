#include <stdio.h>
#include <malloc.h>
#define MAX 100
 struct node
{
    char * data;
    struct node * next;
}* stack= NULL;
void chrpcpy(char f[],char s[]){
    int i= 0,j=0;
    while (f[i]!="\n"){
        i++;
    }
    while (s[j]!="\n"){
        f[i+j]= s[i];
        j++;
    }
    f[i+j]='\n';
    printf("%s", f);
}
char* pop(){
    struct node *next = stack->next;
    char * c = stack->data;
    // printf("%c\n",stack->data);
    stack = next;
    return c;
}
void push(char * n){
    struct node *next = (struct node *) malloc(sizeof(struct node));
    next->data = n;
    next->next = stack;
    stack = next;
}
void display(){
    struct node *temp;
    temp = stack;
    if (temp != NULL){
        while(temp != NULL){
            printf("data is : %s\n",temp->data);
            temp = temp->next;
        }
    }
}
void prefixtoinfix(char Infix[], char Prefix[])
{

    int i, j;
    char e;

    char * l,p,q,bo="(",bc=")";
    printf("1");

    i = 0, j = 0;
    printf("%s",Infix);
    while (Infix[i] != '\0'){
        i++;
        printf("%d",i);
    }
    printf("2");
    i--;
    e = Prefix[i];
    while (i>=0){
        printf("%c", e);
        if (isdigit(e) || isalpha(e))
        {
            push(e);
        }else{
            p = pop();
            q = pop();
            chrpcpy(l,bo);
            chrpcpy(l,p);
            chrpcpy(l,e);
            chrpcpy(l,q);
            chrpcpy(l,bc);
            // l = "("+ p + e + q + ")";
            push(l);
            printf("%s", bo);
            l = NULL;
        }

        e = Prefix[i++];


    }

}
int main() {
    char infix[MAX], Pre[MAX];
    printf("Postfix operation is");
    scanf("%s", &Pre);
    prefixtoinfix(infix, Pre);
    printf("Infix conversion is: %s", infix);
}

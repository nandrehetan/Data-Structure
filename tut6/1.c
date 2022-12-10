#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
void displayinorder(struct node *temp) {
    if(temp==NULL) {
        return;
    }
    displayinorder(temp->left);
    printf("%d",temp->data);
    displayinorder(temp->right);
}
void displaypreorder(struct node *temp) {
    if(temp==NULL) {
        return;
    }
    printf("%d",temp->data);
    displaypreorder(temp->left);
    displaypreorder(temp->right);
}
void displaypostorder(struct node *temp) {
    if(temp==NULL) {
        return;
    }
    displaypostorder(temp->left);
    displaypostorder(temp->right);
    printf("%d",temp->data);
}
struct node *createNode(int data) {
    struct node *newnode;
    // printf("1");
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    return newnode;
}
struct node * createtree(){
    int data,n;
    printf("enter data for head ");
    scanf("%d",&data);
    struct node * head = createNode(data);
    printf("is there data on left of data %d,1 for yes",head->data);
    scanf("%d",&n);
    if (n == 1){
        head->right = createtree();
    }
    else{
        head->right = NULL;
    }
     printf("is there data on right of data %d,1 for yes",head->data);
    scanf("%d",&n);
    if (n == 1){
        head->left = createtree();
    }else{
        head->left = NULL;
    }
    return head;
}
int main() {
    struct  node * head;
    head = createtree();
    displaypreorder(head);
    displaypostorder()
}

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 100
struct node {
    int data;
    struct node *L;
    struct node *R;
};

struct node *createNode(int data) {
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data = data;
    return temp;
}
struct node *insertNode(struct node* root,int data){
    if (root ==NULL){
        root =createNode(data);
        return root;
    }
    struct node * temp = root;
    while (true){
        if (temp->data > data){
            if (temp->R !=NULL){
                temp = temp->R;
            }
            else{
                temp->R = createNode(data);
                return root;
            }
        }
        else(temp->data < data);{
            if (temp->L != NULL){
                temp = temp->L;
            }
            else {
                temp->L = createNode(data);
                return root;
            }
        }
    }
}
struct node * deleteNode(struct node * root,int data){
    if (root == NULL){
        return root;
    }
    int right = 0;
    struct node * temp;
    struct node * tempp;
    temp = root;
    while (true){
        if (temp->data > data){
            if (temp->R !=NULL){
                tempp = temp;
                right=1;
                temp = temp->R;
            }
            else{
                return root;
            }
        }
        if(temp->data < data);{
            if (temp->L != NULL){
                tempp = temp;
                right = 1;
                temp = temp->L;
            }
            else {
                return root;
            }
        }
        if(temp->data == data);{
            break;
        }
    }
    struct node * templ;
    struct node * tempr;
    if (temp->L == NULL) {
        templ = temp->R;
        if (right==1)
            tempp->R = templ;
        else
            tempp->L = templ;
        return root;
    } else if (root->R == NULL) {
        templ = root->L;
        if (right==1)
            tempp->R = templ;
        else
            tempp->L = templ;
        return root;
    }
    templ= temp;
    tempr = temp;
    while (templ->L != NULL){
        tempr=templ;
        templ = templ->L;
    }
    tempr->L= NULL;
    templ->L=temp->L;
    templ->R=temp->R;
    if (right==1)
        tempp->R = templ;
    else
        tempp->L = templ;
    return root;
}
struct node * minValuenode(struct node* temp) {
    struct node* left = temp;
    while (left->L != NULL)
        left = left->L;
    return left;
}
int tree_height(struct node * root) {
    if (!root)
        return 0;
    else {
        int left_height = tree_height(root->L);
        int right_height = tree_height(root->R);
        if (right_height >=left_height )
            return right_height + 1;
        else
            return left_height + 1;
    }
}

void print_level(struct node* root, int level_no) {
    if (!root)
        return;
    if (level_no == 0) {
        printf("%d , ", root->data);
    }
    else {
        print_level(root->L, level_no - 1);
        print_level(root->R, level_no - 1);
    }
}

void Displaylevel(struct node* root){
    if (!root)
        return;
    int height = tree_height(root);
    for (int i=0; i<height; i++) {
        print_level(root, i);
    }
    printf("\n");
}

int hightoftree(struct node *root){
    int max;
    if (root!=NULL)
    {
        int leftsubtree = hightoftree(root->L);
        int rightsubtree = hightoftree(root->R);
        if (leftsubtree > rightsubtree)
        {
            max = leftsubtree + 1;
            return max;
        }
        else
        {
            max = rightsubtree + 1;
            return max;
        }
    }
}
void mirrorimage(struct node* root){
  if (root != NULL)
    {
        struct node* temp;
        temp = root->L;
        root->L  = root->R;
        root->R = temp;
        mirrorimage(root->L);
        mirrorimage(root->R);

    }
}

int main() {
    struct  node * Root;
    Root= NULL;
    int ch = 1,node,data;
    printf("Enter your choice\n1.Insert\n2.Delete\n3.Level wise Display.\n4.Mirror Image\n5.Height of the Tree\n6.Exit \n");

   	while(ch!=6){
	printf("Enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("Insert node: ");
            scanf("%d",&data);
            Root = insertNode(Root,data);
            printf("\n");
            break;

        case 2:
            printf("Delete data: ");
            scanf("%d",&data);
            Root = deleteNode(Root ,data);
            printf("\n");
            break;

        case 3:
            printf("\nLevel wise Display: \n");
            Displaylevel(Root);
            printf("\n");
            break;

        case 4:
            printf("Before Mirrororing Tree \n");
            Displaylevel(Root);
            mirrorimage(Root);
            printf("After Mirrororing Tree \n");
            Displaylevel(Root);
            printf("\n");
            break;

        case 5:
            data = hightoftree(Root);
            printf("Hight of the tree is %d\n",data);
            break;

        case 6:
            printf("\nExit!!");
            break;
        default:
            printf("\nInvalid Choice!!");
            break;

    }
    }
}

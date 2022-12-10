#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct Stack {
    int size;
    int top;
    struct node* *array;
};
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct node*) malloc(stack->size * sizeof(struct node));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top - 1 == stack->size;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, struct node* node) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

struct node* pop(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

struct node* peek(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

void postorder(struct node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack(MAX_SIZE);
    do {
        while (root) {
            if (root->right)
                push(stack, root->right);
            push(stack, root);
            root = root->left;
        }
        root = pop(stack);
        if (root->right && peek(stack) == root->right) {
            pop(stack);
            push(stack, root);
            root = root->right;
        } else
        {
            printf("%d\t", root->data);
            root = NULL;
        }
    } while (!isEmpty(stack));
}

void inorder(struct node *root) {
    struct node *current = root;
    struct Stack* s = createStack(MAX_SIZE);
    int done = 0;

    while (!done) {
        if (current != NULL) {
            push(s, current);
            current = current->left;
        }
        else {
            if (!isEmpty(s)) {
                current = pop(s);
                printf("%d\t", current->data);
                current = current->right;
            }
            else
                done = 1;
        }
    }
}

void preorder(struct node* root) {
    struct node *ptr = root;
    if (root == NULL)
        return;

    struct Stack* stack = createStack(MAX_SIZE);
    push(stack,ptr);
    do {
        ptr = pop(stack);
        printf("%d\t",ptr->data);
        if(ptr->right!=NULL)
                push(stack,ptr->right);
        if(ptr->left!=NULL)
                push(stack,ptr->left);


    } while (!isEmpty(stack));
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
        head->left = createtree();
    }
    else{
        head->left = NULL;
    }
     printf("is there data on right of data %d,1 for yes",head->data);
    scanf("%d",&n);
    if (n == 1){
        head->right = createtree();
    }else{
        head->right = NULL;
    }
    return head;
}
int main() {
    struct  node * root;
    root = createtree();
    printf("Trees!!");
    int ch;
    int node;
    int w = 1;  
    printf("Enter your choice\n1.Inorder\n2Preorder\n3.Postorder\n4Exit \n");
   	while(w==1){
	printf("Enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("\nInorder!!");
        printf("\nInorder Traversal is: \n");
        inorder(root);
        printf("\n");
        break;
        
        case 2:
        printf("\nPreorder!!");
        printf("\nPreorder Traversal is: \n");
        preorder(root);
        printf("\n");
        break;
        
        case 3:
        printf("\nPostorder!!");
        printf("\nPostorder Traversal is: \n");
        postorder(root);
        printf("\n");
        break;
        
		case 4:
        printf("\nExit!!");
        w = 0;
        break;
        
        default:
        printf("\nInvalid Choice!!");
        break;
        
    }
    }    
}

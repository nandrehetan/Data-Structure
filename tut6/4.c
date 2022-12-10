#include<stdio.h>
#include<stdlib.h>
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

struct node * createtree(){
    int data,n;
    printf("enter data  ");
    scanf("%d",&data);
    struct node * head = createNode(data);
    printf("Is there data on left of %d, 1 for yes ",head->data);
    scanf("%d",&n);
    if (n == 1){
        head->L = createtree();
    }
    else{
        head->L = NULL;
    }
    printf("Is there data on right of %d, 1 for yes ",head->data);
    scanf("%d",&n);
    if (n == 1){
        head->R = createtree();
    }else{
        head->R = NULL;
    }
    return head;
}

struct Stack {
    int size;
    int top;
    struct node ** array;
};

struct Stack* Stackcreate(int size) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct node*) malloc(stack->size * sizeof(struct node));
    return stack;
}

int isF(struct Stack* stack) {
    return stack->top - 1 == stack->size;
}

int isE(struct Stack* stack) {
    return stack->top == -1;
}

void pushstack(struct Stack* stack, struct node* node) {
    if (isF(stack))
        return;
    stack->array[++stack->top] = node;
}

struct node* popstack(struct Stack* stack) {
    if (isE(stack))
        return NULL;
    return stack->array[stack->top--];
}

struct node* peek(struct Stack* stack) {
    if (isE(stack))
        return NULL;
    return stack->array[stack->top];
}

void postorder(struct node* Root) {
    if (Root == NULL)
        return;

    struct Stack* stack = Stackcreate(MAX_SIZE);
    do {
        while (Root) {
            if (Root->R)
                pushstack(stack, Root->R);
            pushstack(stack, Root);
            Root = Root->L;
        }
        Root = popstack(stack);
        if (Root->R && peek(stack) == Root->R) {
            popstack(stack);
            pushstack(stack, Root);
            Root = Root->R;
        } else
        {
            printf("%d ", Root->data);
            Root = NULL;
        }
    } while (!isE(stack));
}

void inorder(struct node *Root) {
    struct node *current = Root;
    struct Stack* s = Stackcreate(MAX_SIZE);
    int done = 0;

    while (!done) {
        if (current != NULL) {
            pushstack(s, current);
            current = current->L;
        }
        else {
            if (!isE(s)) {
                current = popstack(s);
                printf("%d ", current->data);
                current = current->R;
            }
            else
                done = 1;
        }
    }
}

void preorder(struct node* Root) {
    struct node *ptr = Root;
    if (Root == NULL)
        return;

    struct Stack* stack = Stackcreate(MAX_SIZE);
    pushstack(stack,ptr);
    do {
        ptr = popstack(stack);
        printf("%d ",ptr->data);
        if(ptr->R!=NULL)
                pushstack(stack,ptr->R);
        if(ptr->L!=NULL)
                pushstack(stack,ptr->L);


    } while (!isE(stack));
}

int main() {
    struct  node * Root;
    Root = createtree();
    int ch = 1;
    int node;
    printf("Enter your choice\n1.Inorder\n2Preorder\n3.Postorder\n4Exit \n");
   	while(ch!=4){
	printf("Enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("\nInorder Traversal is: \n");
        inorder(Root);
        printf("\n");
        break;
        
        case 2:
            printf("\nPreorder Traversal is: \n");
            preorder(Root);
            printf("\n");
            break;
        
        case 3:
            printf("\nPostorder Traversal is: \n");
            postorder(Root);
            printf("\n");
            break;
        
		case 4:
            printf("\nExit!!");
            break;
        
        default:
            printf("\nInvalid Choice!!");
            break;
        
    }
    }    
}

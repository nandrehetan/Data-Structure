#include<stdlib.h>
#include<stdio.h>
struct node {
    int key;
    struct node *left, *right;
};
struct node * minValuenode(struct node* node) {
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}
int tree_height(struct node * root) {
    // Get the height of the tree
    if (!root)
        return 0;
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void print_level(struct node* root, int level_no) {
    // Prints the nodes in the tree
    // having a level = level_no

    // We have a auxiliary root node
    // for printing the root of every
    // subtree
    if (!root)
        return;
    if (level_no == 0) {
        // We are at the top of a subtree
        // So print the auxiliary root node
        printf("%d -> ", root->key);
    }
    else {
        // Make the auxiliary root node to
        // be the left and right nodes for
        // the subtrees and decrease level by 1, since
        // you are moving from top to bottom
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }

}

void print_tree_level_order(struct node* root) {
    if (!root)
        return;
    int height = tree_height(root);
    for (int i=0; i<height; i++) {
        printf("Level %d: ", i);
        print_level(root, i);
        printf("\n");
    }
    printf("\n\n-----Complete Level Order Traversal:-----\n");
    for (int i=0; i<height; i++) {
        print_level(root, i);
    }
    printf("\n");
}

struct node *newnode(int item) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


struct node* insert(struct node* node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newnode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

struct node* deletenode(struct node* root, int key) {
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deletenode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deletenode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValuenode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deletenode(root->right, temp->key);
    }
    return root;
}
int hightoftree(struct node *root)
{
    int max;
    if (root!=NULL)
    {
        /* Finding the height of left subtree. */
        int leftsubtree = hightoftree(root->left);
        /* Finding the height of right subtree. */
        int rightsubtree = hightoftree(root->right);
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
void mirrorimage(struct node* root)
{
  if (root != NULL)
    {
        struct node* temp;
        /*first traversing the left subtree */
        mirrorimage(root->left);
        mirrorimage(root->right);
        temp = root->left;
        root->left  = root->right;
        root->right = temp;
    }
}
// Driver Program to test above functions
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
            printf("Insert node \n");
            scanf("%d",&data);
            Root = insert(Root,data);
            printf("\n");
            break;

        case 2:
            printf("Delete data: \n");
            scanf("%d",&data);
            Root = deletenode(Root ,data);
            printf("\n");
            break;

        case 3:
            printf("\nLevel wise Display: \n");
            print_tree_level_order(Root);
            printf("\n");
            break;

        case 4:
            printf("\nMirror Image: \n");
            print_tree_level_order(Root);
            mirrorimage(Root);
            print_tree_level_order(Root);
            printf("\n");
            break;

        case 5:
            printf("\nHight of the tree: \n");
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

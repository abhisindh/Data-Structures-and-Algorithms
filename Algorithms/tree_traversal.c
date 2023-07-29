#include "../DataStructures/Tree.c"
#include "../DataStructures/Queue.c"
#include <time.h>
#include <math.h>

BSTNode* createRandomTree()
{   
    srand(15);
    int root_value = rand()%50;
    BSTNode* root = createTree(50);
    int len = 15;//rand()%20;
    printf("Random values : %d ", root_value);
    //int list[] = {25,75,12,37,63,87,6,18,31,43,57,69,81,93,INT_MIN};
    for (int i=0; i<len; i++)
    {
        int value = rand()%100;
        printf("%d ", value);
        insert(root, value);
    }
    printf("\n");
    return root;
}

void inorderTraversal(BSTNode* root)
{   
    if (!root) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraveral(BSTNode* root)
{
    if (!root) return;
    printf("%d ", root->data);
    preorderTraveral(root->left);
    preorderTraveral(root->right);
}

void postorderTraversal(BSTNode* root)
{
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void print_tree(BSTNode* root, int level) {
    if (!root) return;

    print_tree(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        printf("|   ");
    }
    printf("|---%d\n", root->data);

    print_tree(root->left, level + 1);
}



void levelOrderTraversal(BSTNode* root)
{
    Queue* queue = createQueue();
    enqueue(queue, root);
    while (!empty(queue)){
        BSTNode* current = dequeue(queue);
        printf("%d ", current->data);
        if (current->left) enqueue(queue,current->left);
        if (current->right) enqueue(queue,current->right);
    }
}


int main(){
    BSTNode* root = createRandomTree();printf("\n");
    print_tree(root, 0);printf("\n");
    printf("Inorder traversal : ");inorderTraversal(root);printf("\n");
    printf("Preorder traversal : ");preorderTraveral(root);printf("\n");
    printf("Postorder traversal : ");postorderTraversal(root);printf("\n");
    printf("Level Order traversal : ");levelOrderTraversal(root);printf("\n");

    delete_tree(root);
    return 0;
}
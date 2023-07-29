// Binary Search Tree Implementation
#include <stdlib.h>
#include <stdio.h>

typedef struct BSTNode BSTNode;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};


BSTNode* createTree(int data){
    BSTNode* tree = malloc(sizeof(BSTNode));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void insert(BSTNode* root, int data){
    if (data < root->data){
        if (!root->left){
           BSTNode* new_node = createTree(data);
           root->left = new_node;
           return;
        }
        insert(root->left, data);
    }else{
        if (!root->right){
            BSTNode* new_node = createTree(data);
            root->right = new_node;
            return;
        }
        insert(root->right, data);
    }
}

int get_node_count(BSTNode* root){
    if (!root) return 0;
    return 1+get_node_count(root->left)+get_node_count(root->right);
}

void print_values(BSTNode* root){
    if (!root) return;
    if (root->left) print_values(root->left);
    printf("%d ", root->data);
    if (root->right) print_values(root->right);
}

void delete_tree(BSTNode* root){
    if (!root) return;
    if (root->left) delete_tree(root->left);
    if (root->right) delete_tree(root->right);
    // printf("\n Deleting values at %p, with value %d", root, root->data);
    free(root);
}

int is_in_tree(BSTNode* root, int value){
    if (!root) return 0;
    if (value < root->data) return is_in_tree(root->left, value);
    if (value > root->data) return is_in_tree(root->right, value);
    return 1;
}

int get_height(BSTNode* root){
    if (!root) return 0;
    int left = get_height(root->left);
    int right = get_height(root->right);
    return left > right ? left+1: right+1;
}

int get_min(BSTNode* root){
    BSTNode* current = root;
    while (current->left) current = current->left;
    return current->data;
}
int get_max(BSTNode* root){
    BSTNode* current = root;
    while (current->right) current = current->right;
    return current->data;
}

int in_order_check(BSTNode* root, int* prev){
    if (!root) return 1;
    if (!in_order_check(root->left, prev)) return 0;

    if (*prev >= root->data) return 0;
    *prev = root->data;

    return in_order_check(root->right, prev);


}

int is_binary_search_tree(BSTNode* root){
    int prev = INT_MIN;
    return in_order_check(root, &prev);
}


BSTNode* delete_node(BSTNode* root, int value){
    if (!root) return root;
    else if (value < root->data) root->left = delete_node(root->left, value);
    else if (value > root->data) root->right = delete_node(root->right, value);
    else{
        if (!root->right && !root->left){ //leaf node
            free(root);
            root = NULL;
        }else if (!root->right){ // only left node
            BSTNode* temp = root;
            root = root->left;
            free(temp);
        }else if (!root->left){ // only right node
            BSTNode* temp = root;
            root = root->right;
            free(temp);
        }else{ // two children
            int new_value = get_min(root->right);
            root->data = new_value;
            root->right = delete_node(root->right, new_value);
        }
    }
    return root;
}

BSTNode* find_in_tree(BSTNode* root, int data){
    if (!root) return NULL;
    if (data < root->data) return find_in_tree(root->left, data);
    else if (data > root->data) return find_in_tree(root->right, data);
    return root;
    
}

int get_successor(BSTNode* root, int data){
    BSTNode* current = find_in_tree(root, data);
    if (!current) return -1;
    if (current->right) return get_min(current->right);
    else{
        int output = -1;
        BSTNode* successor = NULL;
        BSTNode* ancestor = root;
        while (ancestor != current){
            if (data < ancestor->data){
                successor = ancestor;
                output = successor->data;
                ancestor = ancestor->left;
            }else{
                ancestor = ancestor->right;
            }
        }
        return output;
    }

}


// static int main(){
//     int numbers[] = {12, 35, 7, 29, 46, 18, 23, 41, 42, 3, 15, INT_MAX};
//     BSTNode* root = createTree(12);
//     for (int i=1; numbers[i] != INT_MAX; i++){
//         insert(root, numbers[i]);
//     }
//     print_values(root);printf("\n");
//     printf("%d \n", get_successor(root, 23));
// }
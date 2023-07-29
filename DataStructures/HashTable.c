#include <stdio.h>
#include <stdlib.h>
#include "../Algorithms/hash.c"


typedef struct Node Node;
struct Node{
    int data;
    Node* next;

};

typedef struct HashTable HashTable;
struct HashTable{
    Node** array;
    int size;
};

Node* createNode(int data){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
}

HashTable* createHashTable(int size){
    HashTable* hash_table = malloc(sizeof(HashTable));
    Node** array = calloc(size, sizeof(Node*));
    hash_table->array = array;
    hash_table->size = size;
    return hash_table;
}

int hash(int k, int m){
    return divisionHash(k, m);
}

void insert_at_tail(Node* head, int key, int value){

}

void add(HashTable* hash_table, int key, int value){
    int index = hash(key, hash_table->size);
    if (hash_table->array[index] == NULL){
        Node* head = createNode(key);
        hash_table->array[index] = head;
    }
    
}

int main(void){
    HashTable* hash_table = createHashTable(5);
    return 0;
}
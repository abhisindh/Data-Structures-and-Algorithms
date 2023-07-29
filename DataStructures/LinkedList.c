#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node{
    int data;
    Node* next;
};

struct LinkedList{
    Node* head;
    Node* tail;
};

LinkedList* createLinkedList(){
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Node* createNode(int value){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

int size(LinkedList* list){
    Node* current = list->head;
    int output;
    for (output = 0; current != NULL; output++){
        current = current->next;
    }
    return output;
    
}

int empty(LinkedList* list){
    if (!list || !list->head){
        return 1;
    }
    return 0;
}

int value_at(LinkedList* list, int index){
    Node* current = list->head;
    for (int i = 0; i<index; i++){
        if (!current){
            printf("Index out of range, returning error code -1.\n");
            break;
        }
        current = current->next;
    }
    return -1;
}

void push_front(LinkedList* list, int value){
    Node* new_node = createNode(value);
    new_node->next = list->head;
    if (!list->tail) list->tail = new_node; // Empty list scenario
    list->head = new_node;
}

int pop_front(LinkedList* list){
    if (empty(list)) return -1;
    if (list->tail == list->head) list->tail = NULL; // Single Node scenario
    int output = list->head->data;
    Node* temp = list->head;
    list->head = temp->next;
    free(temp);
    return output;
}

void push_back(LinkedList* list, int value){
    Node* new_node = createNode(value);
    if (!list->head && !list->tail){  // Empty list scenario
         list->head = new_node;
         list->tail = new_node;
    }
    list->tail->next = new_node;
    list->tail = new_node;
}

int pop_back(LinkedList* list){
    if (empty(list)) return -1;
    Node *prev, *current = list->head;
    while (current->next){
        prev = current;
        current = current->next;
    }
    int output = current->data;
    list->tail = prev;
    prev->next = NULL;
    free(current);
    return output;
}

int front(LinkedList* list){
    if (empty(list)) return -1;
    return list->head->data;
}

int back(LinkedList* list){
    if (empty(list)) return -1;
    return list->tail->data;  
}

void printList(LinkedList* list){
    Node* current = list->head;
    while (current){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insert(LinkedList* list, int index, int value){
    Node* new_node = createNode(value);

    Node* current = list->head;
    if (index == 0 || current == NULL){
        new_node->next = current;
        list->head = new_node;
        return;
    }
    for (int i=1; i<index && current->next != NULL; i++){
        current = current->next;
    }
    Node* next = current->next;

    current->next = new_node;
    new_node->next = next;
}

void erase(LinkedList* list, int index){
    Node* current = list->head;
    if (index == 0){
       list->head = current->next; 
        free(current);
        return;
    }
    for (int i=1; i< index && current->next != NULL; i++){
        current = current->next;
    }
    Node* to_be_deleted = current->next;
    if (to_be_deleted){
    current->next = to_be_deleted->next;
    free(to_be_deleted);
    }
}

int value_n_from_end(LinkedList* list, int n){
    Node* slow = list->head;
    Node* fast = list->head;
    for (int i=0; i<n && fast->next != NULL; i++){
        fast = fast->next;
    }
    while (fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}

void reverse(LinkedList* list){
    Node *prev = NULL, *current = list->head, *next;
    while (current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}


void remove_value(LinkedList* list, int value){
    Node *prev = NULL,*current = list->head;
    if (current->data == value){
        list->head = current->next;
        free(current);
        return;
    }
    while (current){
        if (current->data == value){
             prev->next = current->next;
             free(current);
             return;
        }
        prev = current;
        current = current->next;
    }
}
// int main(void){
//     LinkedList* list = createLinkedList();
//     for (int i=0; i<5; i++){
//         push_back(list, i);
//     }
//     printList(list);
//     reverse(list);
//     remove_value(list, 0);
//     printList(list);


//     return EXIT_SUCCESS;
// }
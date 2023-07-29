#include "../../DataStructures/LinkedList.c"

Node* push(Node* list, Node* node){
    if (!list) list = node;
    else{
        Node* current = list;
        while (current->next)
        {
            current = current->next;
        }
        current->next = node;
        
    }
    return list;
}

Node* merge(Node* left, Node* right){
    Node* output = NULL;
    Node* temp;
    while (left && right){
        if (left->data <= right->data){
            temp = left->next;
            left->next = NULL;
            output = push(output, left);
            left = temp;

        }else{
            temp = right->next;
            right->next = NULL;
            output = push(output, right);
            right = temp;
        }
    }

    if (left) output = push(output, left);
    if (right) output = push(output, right);
    return output;
}


Node* mergeSort(Node* head){
    if (!head || !head->next) return head;
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp = slow;
    slow = temp->next;
    temp->next = NULL;

    Node* left = mergeSort(head);
    Node* right = mergeSort(slow);

    return merge(left, right);

}

void printNode(Node* head){
    while (head){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n\n");
}


int main(void){
    int list[] = {6,82,69,50,68,13,8,1,84,39,19,17,33,83,23,95,72,22,51,78,64,73,98,36,53,25,66,57,15,43,65,88,44,24,90,42,41,20,58,38,52,54,4,21,32,93,40,59,29,30,37,91,56,28,79,60,99,100,14,16,77,76,5,48,70,97,27,26,9,94,7,80,87,63,55,45,47,71,46,34,92,31,85,67,3,35,96,89,11,2,18,49,86,10,75,74,61,12,81,62, INT_MIN};
    Node* l_list = NULL;
    for (int i=0; list[i]!=INT_MIN; i++){
        Node* node = malloc(sizeof(Node));
        node->data = list[i];
        node->next = NULL;
        l_list = push(l_list, node);
    }
    printNode(l_list);
    l_list = mergeSort(l_list);
    printNode(l_list);
    return 0;


}
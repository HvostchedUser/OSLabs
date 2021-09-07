#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
};
 
struct LinkedList{
    struct Node *head;
};

typedef struct Node Node;
typedef struct LinkedList LinkedList;

void print_list(LinkedList* list) {
    Node* iterator = list->head;
    while (iterator!=NULL){
        printf("%d ", iterator->data);
        iterator = iterator->next;
    }
    printf("\n");
}
void insert_node(Node* after, Node* toInsert) {
    toInsert->next = after->next;
    after->next = toInsert;
}
void delete_node(LinkedList* list, Node *toDelete) {
    Node* iterator = list->head;
    Node* prev = list->head;

    while (iterator != toDelete){
        prev = iterator;
        iterator = iterator->next;
    }
    if(iterator == list->head){
        list->head = iterator->next;
    }else{
        prev->next = iterator->next;
    }
}

int main(){
    Node node;
    node.data = 1;
    node.next = NULL;
    
    LinkedList list;
    list.head = &node;
    
    Node node2;
    node2.data = 2;
    node2.next = NULL;
    insert_node(list.head,&node2);
    
    print_list(&list);
    
    Node node3;
    node3.data = 3;
    node3.next = NULL;
    insert_node(list.head,&node3);
    
    
    print_list(&list);
    
    delete_node(&list,&node2);
    
    print_list(&list);
}

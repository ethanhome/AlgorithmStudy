#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"

void print_node(Node* n){
    if  (n == NULL) {
        printf("node is null\n"); 
        return ;
    }
    printf("val=%d, next=0x%x\n", n->val, n->next);
}

List* new_list(){
    List* l = (List*)malloc(sizeof(List));
    if (l == NULL){
        printf("malloc failed\n"); 
        return NULL;
    }
    l->len = 0;
    l->head.next = NULL;
    l->tail = &l->head;
}
List* init_list(List* l){
    l->len = 0;
    l->head.next = NULL;
    l->tail = &l->head;
}
int insert_head(List* l, int v){
    Node* n = (Node*) malloc(sizeof(Node));
    if (n == NULL) {
        return -1; 
    }
    n->val = v;
    n->next = l->head.next;
    l->head.next = n;
    if(l->len == 0) {
        l->tail = n; 
    }
    l->len++;
    return 0;
}
int insert_node_head(List* l, Node* n){
    n->next = l->head.next;
    l->head.next = n;
    if(l->len == 0) {
        l->tail = n; 
    }
    l->len++;
    return 0;
}
int insert_after(List* l, Node* p, int v){
    Node* n = (Node*) malloc(sizeof(Node));
    if (n == NULL) {
        return -1; 
    }
    n->val = v;
    n->next = p->next;
    p->next = n;
    if (l->tail == p)
        l->tail = n;
    l->len++;
    return 0; 
}

int append(List* l,  int v) {
    Node* n = (Node*) malloc(sizeof(Node));
    if (n == NULL) {
        return -1; 
    }
    n->val = v;
    n->next = l->tail->next;
    l->tail->next = n;
    l->tail = n;
    l->len++;
    return 0; 
}
int append_node(List* l, Node* n){
    n->next = l->tail->next;
    l->tail->next = n;
    l->tail = n;
    l->len++;
    return 0; 
}
int delete(List*l,  int v){
    Node* prev = &l->head;
    Node* p = prev->next;
    while(p!=NULL) {
        if (p->val == v) {
            prev->next = p->next; 
            l->len--;
            if (l->tail == p)
                l->tail = prev;
            return 0;
        }
        prev = p;
        p = p->next;
    }
}
void print_list(List* l){
    Node* p;
    p = l->head.next;
    printf("list print:--------\n");
    while(p!=NULL){
        print_node(p); 
        p = p->next;
    }
    printf("list end:--------\n");
}
Node* find(List* l,  int v) {
    Node* p= l->head.next;
    while(p != NULL){
        if (p->val == v){
            return p; 
        } 
        p = p->next;
    }
    return NULL;
}
int insert_order(List* l, int v){
    Node* n = (Node*) malloc(sizeof(Node));
    if (n == NULL) {
        return -1; 
    }
    n->val = v;
    Node* prev = &l->head;
    Node* p = prev->next;
    while(p!=NULL){
        if(v < p->val) 
            break;
        prev = p;
        p = p->next;
    }
    n->next = prev->next;
    prev->next = n;
    if (l->tail == prev)
        l->tail = n;
    l->len++;
}
int list_revert(List* l){
    Node* p = l->head.next;
    Node* pnext = NULL;
    //empty list
    l->head.next = NULL;
    l->len = 0;
    l->tail = &l->head;

    while(p!=NULL){
        pnext = p->next;
        insert_node_head(l, p);
        p = pnext;
    }
    return 0;
}
int list_revert_ver2(List* l){
    //don't need do anything
    if (l->len < 2)
        return 0;
    Node *prev = l->head.next;
    Node *p = prev->next;
    while(p!=NULL){
        // remove p node
        prev->next = p->next;
        // insert head
        p->next = l->head.next;
        l->head.next = p;
        // check next node
        p = prev->next;

    }
    return 0;
}

List* merge_order_list(List* la,  List* lb){
    List* r = new_list();
    Node* pa = la->head.next;
    Node* pb = lb->head.next;
    Node* p = NULL;
    Node* t;

    init_list(la);    
    init_list(lb);    

    while(pa!=NULL && pb != NULL) {
        if(pa->val < pb->val) {
            t = pa;
            pa = pa->next;
        }else {
            t = pb;
            pb = pb->next;
        }
        append_node(r, t);
    }
    if (pa != NULL)
        p = pa;
    else
        p = pb;


    while(p!=NULL){
        t = p;
        p = p->next;
        append_node(r, t) ;
    }
    return r;
}
// get the large one 
Node* middle_node(List* l){
    Node* slow = l->head.next;
    Node* fast = slow;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next; 
    }
    return slow;
}
// get the small one
Node* middle_node2(List* l){
    Node* slow = l->head.next;
    Node* fast = slow;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        if (fast != NULL)
            slow = slow->next; 
    }
    return slow;
}

int main() {
    Node t;
    t.val = 1;
    t.next = NULL;
    print_node(&t);
    List* mylist = new_list();
    insert_head(mylist, 1);
    int i;
    for( i=2; i<11; i++){
        insert_head(mylist, i) ;
    }
    append(mylist, 11);
    print_list(mylist);
    print_node(find(mylist, 4));
    print_node(find(mylist, 14));
    insert_after(mylist, find(mylist, 4), 24);
    print_list(mylist);
    delete(mylist, 11);
    print_list(mylist);
    delete(mylist, 10);
    print_list(mylist);
    List * order_list = new_list();
    for (i=10; i>0; i--){
        insert_order(order_list, i) ;
    }
    print_list(order_list);
        
    list_revert(order_list);
    print_list(order_list);
    list_revert_ver2(order_list);
    print_list(order_list);

    List* order_list2 = new_list();

    for(i=0; i<11; i+=2){
        insert_order(order_list2, i) ;    
    }
    print_node(middle_node(order_list2));
    print_node(middle_node2(order_list2));
    print_list(merge_order_list(order_list, order_list2));

}

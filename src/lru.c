
typedef struct _Node {
    int val;
    struct _Node* next;
} Node;

typedef struct _List {
    Node head;
    Node *tail;
    int len;
} List;
typedef struct _LruList {
    List* list;
    int maxSize;
} LruList;

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
Node* remove(List* l, int v) {
    Node* prev = &l->head;
    Node* p = prev->next;
    while(p!=NULL) {
        if (p->val == v) {
            prev->next = p->next; 
            l->len--;
            if (l->tail == p)
                l->tail = prev;
            return p;
        }
        prev = p;
        p = p->next;
    }
    return NULL;
}
Node* remove_tail(List* l){
    Node* prev = &l->head;
    Node* p = prev->next;
    while(p!=NULL) {
        if (p == l->tail) {
            prev->next = p->next; 
            l->len--;
            l->tail = prev;
            return p;
        }
        prev = p;
        p = p->next;
    }
    return NULL;
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

LruList* new_lru_list(int size){
    LruList* lru = (LruList*)malloc(sizeof(LruList));
    if (lru == NULL)
        return NULL;
    lru->list = new_list();
    lru->maxSize = size;
    return lru;
}

int lru_set(LruList* lru, int v){
    Node* p = remove(lru->list, v);        
    if (p != NULL){
        insert_node_head(lru->list, p);    
        return 0;
    }
    // new node
    if (lru->list->len == lru->maxSize) {
        p = remove_tail(lru->list);
        if (p != NULL) {
            p->val = v;
            insert_node_head(lru->list, p); 
            return 0;
        }
        return -1;
    } else {
        p = (Node*)malloc(sizeof(Node)); 
        if (p == NULL)
            return -1;
        p->val = v;
        insert_node_head(lru->list, p); 
        return 0;

    }
}



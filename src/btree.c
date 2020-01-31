#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
    int v;
    struct _node* left;
    struct _node* right;
} node_t;
typedef struct _btree {
    node_t* root;
} btree;

void tree_init(btree* r){
    if(r)
        r->root = NULL;
}

node_t* new_node(int v){

    node_t* p = (node_t*)malloc(sizeof(*p));
    if (p == NULL)
        return NULL;
    p->v = v;
    p->left = p->right = NULL;
    return p;
}
node_t* tree_insert(btree* r, int v){
    node_t *n = NULL;
    node_t* cur;

    if(r == NULL)
        return NULL;

    n = new_node(v);
    if(n== NULL)
        return NULL;

    // empty tree
    if(r->root == NULL) {
        r->root = n; 
        return n;
    }
    cur = r->root;
    while(cur!=NULL){
        if(v < cur->v){
            if(cur->left == NULL){
                cur->left = n;
                return n; 
            }
            cur = cur->left; 
        }else {
            //??? cur->v == v ??
            if(cur->right == NULL) {
                cur->right = n;
                return n; 
            }
            cur = cur->right; 
        } 
    }
    return NULL;
}
node_t* tree_find(btree* r, int v){
    node_t* p = r->root;
    while(p!=NULL){
        if(p->v == v) 
            return p;
        if(v < p->v){
            p = p->left; 
        }else {
            p = p->right; 
        }
    }
    return NULL;
}
node_t* tree_remove(btree* r, int v){
    node_t* child;
    node_t* n=r->root;
    node_t **p = &r->root;
    while(n && n->v != v){
        if(v < n->v){
            p = &n->left;
            n = n->left; 
        }else {
            p = &n->right;
            n = n->right; 
        } 
    }
    //not found
    if(!n){
        return NULL; 
    }
    if(n->left && n->right){
        node_t* rn = n->right;
        node_t** rp = &n->right; 
        while (rn->left){
            rp = &rn->left; 
            rn = rn->left;
        }
        n->v = rn->v;
        n = rn;
        p = rp;
    }
    child = n->left ? n->left : n->right;
    *p = child;
    return n;
}


void print_node(node_t* p){
    if(p){
        printf("%d, ",p->v); 
        return ;
    }
    printf("null, ");
}
void preOrder(node_t* r){
    if (r) {
        print_node(r); 
        preOrder(r->left);
        preOrder(r->right);
    }
}
int main(){
    btree root;
    tree_init(&root);
    tree_insert(&root, 1);
    tree_insert(&root, 2);
    tree_insert(&root, 3);
    tree_remove(&root, 3);
    preOrder(root.root);
    printf("\ntest_find:\n");
    print_node(tree_find(&root, 3));
    printf("\n");
    print_node(tree_find(&root, 0));
    printf("\n");
}

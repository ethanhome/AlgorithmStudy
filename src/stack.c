#include<stdio.h>
#include<stdlib.h>

typedef struct _stack {
    int* base;
    int size;
    int top;
} stack_t;

stack_t* new_stack(int size){
    stack_t* st = (stack_t*)malloc(sizeof(*st));
    if (st == NULL)
        return NULL;
    st->base = (int*)malloc(sizeof(int)*size);
    if (st->base == NULL)
        return NULL;

    st->size = size;
    st->top = 0;
    return st;
}

int push(stack_t* st, int v){
    if (st->top >= st->size ){
        printf("stack is full\n"); 
        return -1;
    }
    st->base[st->top++] = v;
    return 0;
}
int pop(stack_t* st){
    if(st->top == 0){
        printf("stack is empty\n"); 
        return -1;
    }

    return st->base[--st->top];
}
int main(){
    stack_t* st = new_stack(5);
    push(st, 1);
    push(st, 2);
    push(st, 3);
    push(st, 4);
    push(st, 5);
    push(st, 6);
    int v;
    while(1){
        v = pop(st);
        if (v == -1)
            break;
        printf("pop:%d\n", v);
    }
}

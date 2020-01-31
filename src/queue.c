#include<stdio.h>
#include<stdlib.h>

typedef stuct _queue {
    int* base;
    int size;
    int head, tail;
} queue_t;

queue_t* new_queue(int size){
    queue_t* q = (queue_t*)malloc(sizeof(*q));
    if (q == NULL){
        printf("malloc queue failed\n"); 
        return NULL;
    }
    q->size = size;
    q->head = q->tail = 0;
    q->base = (int*)malloc(sizeof(int)*size);
    if (q->base == NULL){
        printf("malloc failed\n"); 
        return NULL;
    }
    return q;
}
int enqueue(queue_t* q, int v){
    //(q->tail+1)%q->size == q->head
    if(q->tail == q->size){
        printf("queue is full\n"); 
        return -1;
    }
    q->base[q->tail] = v;
    q->tail++;
    // q->tail = (q->tail+1)%q->size;
    return 0;
}
int dequeue(queue_t* q){
    if (q->head == q->tail){
        printf("queue is empty\n"); 
        return -1;
    }
    int ret = q->base[q->head];
    q->head++;
    // q->head = (q->head+1)% q->size
    return ret;
}


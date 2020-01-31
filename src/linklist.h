#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdio.h>
#include<stdlib.h>


typedef struct _Node {
    int val;
    struct _Node* next;
} Node;

typedef struct _List {
    Node head;
    Node *tail;
    int len;
} List;

#endif

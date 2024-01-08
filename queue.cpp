#include <iostream>
using namespace std;

typedef struct link {
    int element;
    struct link* next;
}Link;

Link* create_link(int it, Link* nextval){
    Link* n = (Link*) malloc(sizeof(Link));

    n->element = it;
    n->next = nextval;
    return n;
}

Link* create_link(Link* nextval){
    Link* n = (Link*) malloc(sizeof(Link));
    n->next = nextval;
    return n;
}

typedef struct {
    Link* front;
    Link* rear;
    int size;
}Queue;

Queue* create_queue(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->rear = create_link(NULL);
    q->front = q->rear;
    return q;
}

void enqueue(Queue* q, int it){
    q->rear->next = create_link(it, NULL);
    q->rear = q->rear->next;
    q->size++;
}

int dequeue(Queue* q){
    if (q->size != 0) {
        int it = q->front->next->element;
        q->front->next = q->front->next->next;
        if (q->front->next == NULL) q->rear = q->front;
        q->size--;
        return it;
    }
    return -1;
}



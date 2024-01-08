#include <iostream>
using namespace std;

typedef struct link{
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

typedef struct stack{
    Link* top;
    int size;
}Stack;

Stack* create_stack(){
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void push(Stack* s, int it){
    s->top = create_link(it, s->top);
    s->size++;
}

int pop(Stack* s){
    if (s->top != NULL){
        int it = s->top->element;
        s->top = s->top->next;
        s->size--;
        return it;
    }
}

int hashf(int x){
    int resultado = x%10;
    return resultado;
}

void display(Stack* s){
    Link* aux = s->top;
    while (aux != NULL){
        cout << aux->element << " ";
        aux = aux->next;
    }
    cout << "\n";
    free(aux);
}

int main(){
    int qtd;
    Stack* array[10];
    cin >> qtd;
    for (int i = 0; i<10; i++){
        array[i] = create_stack();
    }
    for (int i = 0; i<qtd; i++){
        int x;
        cin >> x;
        int idx = hashf(x);
        push(array[idx], x);
    }
    for (int i = 0; i<10; i++){
        cout << i << " ";
        display(array[i]);
    }
    return 0;
}
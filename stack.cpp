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

int main(){
    Stack* stack = create_stack();
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; i++) {
        cout << "Caso " << i + 1 << ":\n";
        string comando = " ";
        int numero;
        while (comando != "end"){
            cin >> comando;
            if (comando == "push") {
                cin >> numero;
                push(stack, numero);
            } else if (comando == "pop"){
                cin >> numero;
                int soma = 0;
                for (int j = 0; j < numero; j++) {
                    soma += pop(stack);
                }
                cout << soma << "\n";
            }
        }
    }

    return 0;
}
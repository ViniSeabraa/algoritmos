#include <iostream>
using namespace std;

typedef struct link{
    char element;
    struct link* next;
}Link;

Link* create_link(char it, Link* nextval){
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
    Link* head;
    Link* tail;
    Link* curr;
    int cnt;
} List;

List* create_list(){
    List* l = (List*) malloc(sizeof(List));
    l->curr = l->tail = l->head = create_link(NULL);
    l->cnt = 0;
    return l;
}

void insert(List* l, char it){
    l->curr->next = create_link(it, l->curr->next);
    if (l->curr == l-> tail){
        l->tail = l->curr->next;
    }
    l->cnt++;
}

void display(List* l){
    l->curr = l->head;
    l->curr = l->curr->next;
    for (int i=0; i<l->cnt; i++){
        cout << l->curr->element;
        l->curr = l->curr->next;
    }
}

int main(){
    string s;
    while(cin >> s){
        List* listadovini = create_list();
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if (c == '['){
                listadovini->curr = listadovini->head;
            }
            else if(c == ']'){
                listadovini->curr = listadovini->tail;
            }
            else{
                insert(listadovini, c);
                if (listadovini->curr != listadovini->tail){
                    listadovini->curr = listadovini->curr->next;
                }
            }
        }
        display(listadovini);
        cout << "\n";
        delete listadovini;
    }
    return 0;
}
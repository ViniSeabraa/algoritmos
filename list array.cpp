#include <iostream>
using namespace std;

typedef struct list{
    int maxSize;
    int listSize;
    int curr;
    int* listArray;
} List;

List* create_list(int size){
    List* l= (List*) malloc(sizeof(List));
    l->maxSize = size;
    l->listSize = l->curr = 0;
    l->listArray = (int*) malloc(size * sizeof(int));
    return l;
}

void insert(List l,int it){
    if (l.listSize >= l. maxSize){
        cout << "erro";
    }
    int i = l.listSize;
    while(i>l.curr){
        l.listArray[i] = l.listArray[i-1];
        i--;
    }
    l.listArray[l.curr] = it;
    l.listSize++;
}

void moveToStart(List l){
    l.curr = 0;
}

void moveToEnd(List l) {
    l.curr = l.listSize;
}

void prev(List l) {
    if (l.curr != 0){
        l.curr--;
    }
}

void next(List l){
    if (l.curr < l.listSize){
        l.curr++;
    }
}

int remove(List l){
    if(l.curr <0 || l.curr>= l.listSize){
        return NULL;
    }
    int it = l.listArray[l.curr];
    int i = l.curr;
    while (i<l.listSize-1){
        l.listArray[i] = l.listArray[i + 1];
        i++;
    }
    l.listSize--;
    return it;
}

void display(List l){
    for (int i=0; i< l.listSize; i++){
        cout << l.listArray[i];
    }
}

int main(){
    int c;
    cin >> c;
    for(int i = 1; i<=c; i++){
        cout << "Caso " << i <<":";
        int n;
        List* lista = create_list(n);
        cin >> n;
        for(int j=0; j<n; j++){
            string comando;
            cin >> comando;
            if(comando == "insert"){
                int x;
                cin >> x;
                insert(lista, x);
            }
        }
        display(lista);
    }
    return 0;
}
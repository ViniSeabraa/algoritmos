#include <iostream>
using namespace std;

typedef struct entry{
    string nome;
    string key;
} Entry;

typedef struct dictionary{
    int m;
    int cnt;
    Entry *H;
    int *Perm;
}Dictionary;

Dictionary* create_dict(int size){
    Dictionary *d = (Dictionary*)malloc(sizeof(Dictionary));
    d->m = size;
    d->cnt = 0;
    d->H = (Entry*)malloc(sizeof(Entry)*size);
    d->Perm = (int*)malloc(sizeof(int)*size-1);
    for (int i = 1; i < size; i++) {
        d->Perm[i-1] = i;
    }
    return d;
}

int hashf(Dictionary* d, string y){
    int soma = 0;
    for (int i = 0; i < y.size(); i++){
        soma += y[i];
    }
    return soma%d->m;
}

int find(Dictionary* d, string y){
    int idx = hashf(d, y);
    if (y == d->H[idx].nome){
        return idx;
    }
    else{
        for( int i = 0; i < d-> m ; i++){
            if(y == d->H[(idx+d->Perm[i])%d->m].nome){
                return (idx+d->Perm[i])%d->m;
            }
        }
        return -1;
    }
}

Dictionary* remove(Dictionary* d, string y){
    int idx = find(d, y);
    if (idx == -1){
        return d;
    }
    else{
        d->H[idx].nome = "deletado";
        d->cnt--;
        return d;
    }
}

void insert(Dictionary *d, string k, string n){
    if (d->cnt < d->m && find(d, n) == -1){
        int pos = hashf(d, n);
        if (!d->H[pos].nome.empty() && d->H[pos].nome != "deletado"){
            int i = 0;
            int newpos = pos;
            while(!d->H[newpos].nome.empty() && d->H[newpos].nome != "deletado"){
                i += 1;
                newpos = (pos + d->Perm[i-1])%d->m;
            }
            pos = newpos;
        }
        d->H[pos].nome = n;
        d->H[pos].key = k;
        d->cnt += 1;
    }
}

int main(){
    int x;
    cin >> x;
    Dictionary* dict = create_dict(x);
    for (int i = 0; i < x; i++){
        string f, p;
        cin >> f >> p;
        if (f=="add"){
            insert(dict, p, p);
        }
        else if (f== "rmv"){
            dict = remove(dict, p);
        }
        else{
            int pos = find(dict, p);
            cout << p << " "<<  pos << "\n";
        }
    }
    string erro;
    cin >> erro;
    return 0;
}
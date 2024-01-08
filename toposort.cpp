#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int size;
    int** matrix;
    int numEdge;
    int* Mark;
}Graph;

Graph* create_graph(int n){
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->Mark = new int[n];
    g->matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        g -> matrix[i] = new int[n];
    }
    g->numEdge = 0;
    g->size = n;
    return g;
}

int first(Graph* g, int v){
    for (int i=0; i<g->size;i++){
        if (g->matrix[v][i] != 0) return i;
    }
    return g->size;
}

int next(Graph* g, int v, int w){
    for(int i = w + 1; i <= g->size -1 ; i++){
        if (g->matrix[v][i] != 0) return i;
    }
    return g->size;
}

void setEdge(Graph* g, int i, int j, int wt){
    if (wt != 0){
        if (g->matrix[i][j] == 0) g->numEdge++;
        g->matrix[i][j] = wt;
    }
}

void setMark(Graph* g, int v, int x){
    g->Mark[v] = x;
}

int getMark(Graph* g, int v){
    return g->Mark[v];
}

void toposort(Graph* g, int start, stack<int>&s){
    setMark(g, start, 1);
    int w  = first(g,start);
    while (w<g->size){
        if (getMark(g, w) == 0) toposort(g,w, s);
        w = next(g,start,w);
    }
    s.push(start);
}

int main(){
    int n,m,x,y;
    cin >> n >> m;
    Graph* grafo = create_graph(n);
    bool arraycond[n];
    for (int k = 0; k < n; k++){
        arraycond[k] = true;
    }
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        setEdge(grafo, x-1, y-1, 1);
        arraycond[y-1] = false;
    }
    int topostart = -1;
    for (int q = 0; q < n; q++){
        if (arraycond[q] == true){
            topostart = q;
            break;
        }
    }
    if (topostart != -1){
        stack<int> stackvini;
        toposort(grafo, topostart, stackvini);
        if (stackvini.size() == n){
            cout << stackvini.top() + 1;
            stackvini.pop();
            for (int i = 1; i < n; i++){
                cout << " " << stackvini.top() + 1;
                stackvini.pop();
            }
        }
        else cout << "Sandro fails.";
    }
    else cout << "Sandro fails.";
    return 0;
}
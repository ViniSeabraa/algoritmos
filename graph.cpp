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

void delEdge(Graph* g, int i, int j){
    if (g->matrix[i][j] != 0) g->numEdge--;
    g->matrix[i][j] = 0;
}

void setMark(Graph* g, int v, int x){
    g->Mark[v] = x;
}

int getMark(Graph* g, int v){
    return g->Mark[v];
}

void BFS(Graph* g, int start, int array[]){
    queue<int>Q;
    int w, v;
    Q.push(start);
    setMark(g, start, 1);
    while(!Q.empty()){
        v = Q.front();
        Q.pop();
        w = first(g, v);
        while (w < g->size){
            if (getMark(g, w) == 0){
                setMark(g, w, 1);
                Q.push(w);
                array[w] = v;
            }
            w = next(g, v, w);
        }
    }
}

int main(){
    int casos, vertices, arestas;
    cin >> casos;
    for (int b = 1; b <= casos; b++){
        cout << "Caso " << b << "\n";
        cin >> vertices >> arestas;
        Graph* grafo = create_graph(vertices);
        for(int w = 0; w < arestas; w++){
            int i,j;
            cin >> i >> j;
            setEdge(grafo, i, j, 1);
        }
        int perguntas;
        cin >> perguntas;
        for (int h=0; h < perguntas; h++){
            int source, target;
            cin >> source >> target;
            for (int v = 0; v <= grafo->size -1; v++) {
                setMark(grafo, v, 0);
            }
            int arraysec[vertices];
            for (int l = 0; l < vertices; l++){
                arraysec[l] = -1;
            }
            BFS(grafo, source, arraysec);
            int z = 0;
            int predecessor = -1;
            int qtd = 0;
            if (source != target){
                while (predecessor != source){
                    z++;
                    if( z == vertices){
                        qtd = -1;
                        break;
                    }
                    predecessor = arraysec[target];
                    target = predecessor;
                    qtd++;
                    if (predecessor == source){
                        break;
                    }
                }
                cout << qtd << "\n";
            }
            else cout << qtd << "\n";
        }
    }
    return 0;
}
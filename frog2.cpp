#include <bits/stdc++.h>
using namespace std;

typedef struct{
    vector<vector<pair<int,int>>> list;
    int size;
    int* pred;
    int* dist;
    int numEdge;
    int* Mark;
}Graph;

Graph* create_graph(int n){
    Graph* g = new Graph;
    g->list.resize(n);
    g->Mark = new int[n];
    g->dist = new int[n];
    g->pred = new int[n];
    for (int i=0; i < n; i++){
        g->dist[i] = INT_MAX;
        g->pred[i] = -1;
        g->Mark[i] = 0;
    }
    g->numEdge = 0;
    g->size = n;
    return g;
}

void setEdge(Graph* g, int i, int j, int wt){
    g->list[i].push_back(make_pair(j,wt));
    g->list[j].push_back(make_pair(i,wt));
    g->numEdge++;
}

void setMark(Graph* g, int v, int x){
    g->Mark[v] = x;
}

int getMark(Graph* g, int v){
    return g->Mark[v];
}

void dijkstra(Graph *g, int s){
    for(int i = 0; i < g->size; i++){
        setMark(g, i, 0);
    }
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> H;
    H.emplace(make_tuple(0,s,s));
    g->dist[s] = 0;

    while(!H.empty()){
        tuple<int,int,int> y = H.top();
        int p = std::get<1>(y);
        int v = std::get<2>(y);
        H.pop();
        setMark(g,v,1);
        g->pred[v] = p;
        for (int m=0; m < g->list[v].size();m++){
            int w = g->list[v][m].first;
            if (getMark(g,w) != 1 && g->dist[w] > g->dist[v] + g->list[v][m].second){
                g->dist[w] = g->dist[v] + g->list[v][m].second;
                H.emplace(g->dist[w],v,w);
            }
        }

    }
}

int main(){
    int n,k;
    cin >> n >> k;
    int array[n];
    int peso;
    int h;
    Graph* grafo = create_graph(n);
    for(int i = 0; i < n; i++){
        cin >> h;
        array[i] = h;
    }
    for (int i = 0; i < n-1; i++){
        for (int j = 1; j <= k; j++){
            if (i+j < n){
                peso = abs(array[i] - array[j+i]);
                setEdge(grafo, i, i+j, peso);
            }
        }
    }
    dijkstra(grafo, 0);
    int resultado = grafo->dist[n-1];
    cout << resultado;
    return 0;
}
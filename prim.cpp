#include <bits/stdc++.h>
using namespace std;

typedef struct{
    vector<vector<pair<int,int>>> list;
    int size;
    int* pred;
    int* dist;
    int numEdge;
    int* Mark;
    int maior;
}Graph;

Graph* create_graph(int n){
    Graph* g = new Graph;
    g->list.resize(n);
    g->Mark = new int[n];
    g->dist = new int[n];
    g->pred = new int[n];
    g->maior = 0;
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

void prim(Graph *g){
    int x = 1;
    for(int i = 0; i < g->size; i++){
        setMark(g, i, 0);
    }
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> H;
    H.emplace(make_tuple(0,0,0));
    g->dist[0] = 0;

    while(!H.empty()){
        tuple<int,int,int> y = H.top();
        int p = std::get<1>(y);
        int v = std::get<2>(y);
        H.pop();
        setMark(g,v,1);
        if (x) {
            g-> maior = g->dist[v];
            x = 0;
        }
        else if (g->dist[v] > g->maior) g-> maior = g->dist[v];
        g->pred[v] = p;
        for (int m=0; m < g->list[v].size();m++){
            int w = g->list[v][m].first;
            if (getMark(g,w) != 1 && g->dist[w] > g->list[v][m].second){
                g->dist[w] = g->list[v][m].second;
                H.emplace(g->dist[w],v,w);
            }
        }

    }
}

int main(){
    int n, m;
    n = 1;
    m = 1;
    cin >> n >> m;
    while(!(n == 0 && m==0)){
        int x = 1;
        Graph *grafo = create_graph(n);
        while (m--){
            int cidade1, cidade2, peso;
            cin >> cidade1 >> cidade2 >> peso;
            setEdge(grafo, cidade1,cidade2, peso);
        }
        prim(grafo);
        for (int i = 0; i < n; i++){
            if (grafo->dist[i] == INT_MAX) x = 0;
        }
        if (x) cout << grafo->maior << "\n";
        else cout << "IMPOSSIBLE\n";
        cin >> n >> m;
    }
    return 0;
}

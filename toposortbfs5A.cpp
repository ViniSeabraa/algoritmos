#include <bits/stdc++.h>
using namespace std;

int main(){
    int na, nv;
    cin >> nv >> na;
    vector<vector<int>> listaadj(nv);
    vector<int> restricoes(nv, 0);
    int x, y;
    while (na--){
        cin >> x >> y;
        listaadj[x-1].push_back(y-1);
        restricoes[y-1]++;
    }
    vector<int> resultado;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < nv; i++) if (restricoes[i] == 0) q.push(i);

    if (q.empty()){
        cout << "Sandro fails.";
    }
    else{
        while (!q.empty()){
            int atual = q.top();
            q.pop();
            resultado.push_back(atual);
            for (int i = 0; i < listaadj[atual].size(); i++){
                restricoes[listaadj[atual][i]]--;
                if (restricoes[listaadj[atual][i]] == 0) q.push(listaadj[atual][i]);
            }
        }
        if (resultado.size() < nv) cout << "Sandro fails.";
        else{
            cout << resultado[0] + 1;
            for (int i = 1; i < nv; i++){
                cout << " " << resultado[i] +1;
            }
        }
    }
    return 0;
}
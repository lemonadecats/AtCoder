#include<bits/stdc++.h>
using namespace std;

struct edge{int to, cap, rev;};

vector<vector<edge>> G;
vector<bool> visited;

int dfs(int v, int t, int f){
    if (v == t) return f;
    visited[v] = true;
    for (int i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if (!visited[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

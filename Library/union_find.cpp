#include<bits/stdc++.h>
using namespace std;

vector<int> root;
vector<int> Rank;

//通常バージョン
int find(int x){
    if (root[x] == x) return x;
    root[x] = find(root[x]);
    return root[x];
}

bool check(int x, int y){
    return find(x) == find(y);
}

void Union(int x, int y){
    x = find(x); y = find(y);
    if (check(x, y)){
        return;
    }
    if (Rank[x] >= Rank[y]) root[y] = x;
    else root[x] = y;
    if (Rank[x] == Rank[y]) Rank[x]++;
}

//sizeありversion
vector<int> root;
vector<int> Rank;
vector<int> u_size;

int find(int x){
    if (root[x] == x) return x;
    root[x] = find(root[x]);
    return root[x];
}

bool check(int x, int y){
    return find(x) == find(y);
}

void Union(int x, int y){
    x = find(x); y = find(y);
    if (check(x, y)){
        return;
    }
    if (Rank[x] >= Rank[y]) 
    {
        u_size[x] += u_size[y];
        u_size[y] = 0;
        root[y] = x;
    }
    else 
    {
        u_size[y] += u_size[x];
        u_size[x] = 0;
        root[x] = y;
    }
    if (Rank[x] == Rank[y]) Rank[x]++;
}

//閉路検出バージョン
//作る必要なくない？？？
int find(int x){
    if (root[x] == - 1) return - 1;
    if (root[x] == x) return x;
    root[x] = find(root[x]);
    return root[x];
}

bool check(int x, int y){
    return find(x) == find(y);
}

void Union(int x, int y){
    x = find(x); y = find(y);
    if (x == - 1 || y == - 1) {
        if (x != - 1) root[x] = - 1;
        if (y != - 1) root[y] = - 1;
        return;
    }
    //もし閉路が存在したら、根を-1にする -> つまりrootに-1があれば閉路が存在
    //じゃあ閉路の数を検索したいときは? -> これじゃダメそう
    if (check(x, y)){
        root[x] = - 1;
        root[y] = - 1;
        return;
    }
    if (Rank[x] >= Rank[y]) root[y] = x;
    else root[x] = y;
    if (Rank[x] == Rank[y]) Rank[x]++;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> set_root(n);
    for (int i = 0; i < n; i++) set_root[i] = i;
    root = set_root;
    vector<int> set_Rank(n, 0);
    Rank = set_Rank;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        Union(u, v);
    }
    for (int i = 0; i < n; i++) find(i);
    set<int> s;
    for (int i = 0; i < n; i++) s.insert(root[i]);
    if (s.find(-1) != s.end()) cout << s.size() - 1 << endl;
    else cout << s.size() << endl;
}
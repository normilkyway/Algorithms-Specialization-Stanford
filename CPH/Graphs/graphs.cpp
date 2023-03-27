#include <bits/stdc++.h>

using namespace std;

void graphs();

int N = 100;
vector<int> g[N];
bool visited[N];
queue<int> q;
int distance[N];

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto u : g[s]) {
        dfs(u);
    }
}

void bfs(int s) {
    visited[s] = true;
    distance[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto u : g[x]) {
            if (visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[x]+1;
            q.push(u);
        }
    }
}

int main() {
    // graphs();
    
    
}

void graphs() {
    vector<vector<int>> v; // array of vectors
                        // N declares the size of array 
    
    v.push_back({1, 2, 3, 4});
    v.push_back({5, 6, 7, 8});
    v.push_back({9, 10, 11, 12});


    for (int i = 0; i < v.size(); i++) {
        for (auto it=v[i].begin(); it!=v[i].end(); it++)
            cout << *it << " ";
        cout <<"\n";
    }

    // weighted graph 
    vector<vector<pair<int, int>>> wg(1000);
    wg[1].push_back({2, 5});
    wg[2].push_back({4, 6});
    wg[2].push_back({3, 7});
    wg[3].push_back({4, 5});
    wg[4].push_back({1,2});
    for (int i=0; i<wg.size(); i++) {
        cout << "Node " << i << ": \n";
        for (auto u : wg[i]) 
            cout << u.first << " | " << u.second << "\n";
    }

    int N = 5;
    array<array<int, 5>, 5> matrix;
    matrix[1][2] = 5;
    matrix[2][1] = 5;
    matrix[2][4] = 6;
    matrix[4][2] = 6;
    matrix[2][3] = 7;
    matrix[3][2] = 7;
    matrix[3][4] = 5;
    matrix[4][3] = 5;
    matrix[4][1] = 2;
    matrix[1][4] = 2;

    tuple<int, int, string> store;
    store = {1, 2, "hello world"};
}
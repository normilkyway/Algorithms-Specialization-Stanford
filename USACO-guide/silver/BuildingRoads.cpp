#include <iostream>

using namespace std;

vector<bool> valid;

vector<bool> dfs(vector<int> g[]) {
    return {false};
}

int main() {
    int n, m;
    cin << n << m; // always require n-1 lines
    
    vector<int> g[n];

    while(m-- > 0) {
        int a, b;
        cin << a << b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    return 0;
}
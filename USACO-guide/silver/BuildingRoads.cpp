#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin << n << m;
    
    vector<int> g[n];
    boolean b[n];

    while(m-- > 0) {
        int a, b;
        cin << a << b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> sieve(int n) {
    vector<int> v(n, 0), j;
    for (int x=2; x<=n; x++) {
        if (v[x]) continue; 
        for (int sk=2*x; sk <= n; sk += x) 
            v[sk] = x;
    }
    for (int x=2; x<n; x++)
        if (!v[x]) j.push_back(x);
    return j;
}

vector<int> factors(int n) {
    vector<int> f;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

int gcd(int a, int b) {
    return (b==0) ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
    return a/gcd(a, b) * b;
}

// Diophantine equations --> {x, y} for ax + by = c when {a, b, c} are given
bool solveable(int a, int b, int c) {
    
}


int main() {
    vector<int> v = sieve(100);
    for (int i : v) cout << i << " ";
    cout << "\n";
    vector<int> f = factors(10);
    for (int i : f) cout << i << " ";
    cout << "\n";
    cout << gcd(15, 5) << endl;
    cout << lcm(12, 24) << endl;
    cout << lcm(1231, 24) << endl;
}
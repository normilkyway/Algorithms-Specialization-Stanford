#include <bits/stdc++.h>
using namespace std;

int maximumScore(int a, int b, int c)
{
    // return min(a + b + c - max({a, b, c}), max({a, b, c}));
    // simulation problem
    priority_queue<int, vector<int>> pq; // max-pq
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int i = 0;
    while (pq.size() > 1)
    {
        int t1, t2;
        t1 = pq.top();
        pq.pop();
        t2 = pq.top();
        pq.pop();
        i += 1;
        if (--t1 > 0)
            pq.push(t1);
        if (--t2 > 0)
            pq.push(t2);
    }
    return i;
}

int main()
{
    cout << maximumScore(2, 4, 6);
}
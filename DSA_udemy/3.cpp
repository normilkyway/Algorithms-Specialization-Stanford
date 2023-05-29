#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> n)
{
    priority_queue<int, vector<int>, greater<int>> pq; // min-pq
    for (int i = 0; i < n.size(); ++i)
        pq.push(n[i]);
    int sum = 0;
    while (!pq.empty() && pq.size() > 1) // O(N log N) tc, O(N) sc
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        sum += (x + y);
        pq.push(x + y);
    }
    return sum;
}
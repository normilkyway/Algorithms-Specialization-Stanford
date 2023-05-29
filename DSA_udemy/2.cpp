#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> n, int k)
{
    // set<int> s(n.begin(), n.end()); // stores unique values from smallest to largest
    sort(n.begin(), n.end());
    return n[n.size() - k];
}
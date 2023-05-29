#include <bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int> n, int k, int x)
{
    int minIndex = -1, maxIndex = -1; // 2 pointers to go forwards and backwards
    int smallestDiff = n[0] - x;
    for (int i = 0; i < n.size(); ++i)
        if (abs(n[i] - x) < smallestDiff)
        {
            smallestDiff = abs(n[i] - x);
            minIndex = maxIndex = i; // starting point?
        }
    // starting point assigned
    vector<int> out;
    while (out.size() < k)
    {
        if (minIndex >= 0 && (maxIndex >= n.size() || abs(n[minIndex] - x) <= abs(n[maxIndex] - x)))
        {
            out.insert(out.begin(), n[minIndex]);
            --minIndex;
        }
        else if (maxIndex < n.size())
        {
            out.push_back(n[maxIndex]);
            maxIndex++;
        }
    }
    sort(out.begin(), out.end());
    return out;
}
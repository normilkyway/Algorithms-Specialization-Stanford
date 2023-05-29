#include <bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int> n, int k, int x)
{
    // 1, 2, 3, 4, 5 | k = 4 | x = 3
    //    1 2 3 4

    int minIndex = -1, maxIndex = -1; // 2 pointers to go forwards and backwards
    int smallestDiff = abs(n[0] - x);
    for (int i = 0; i < n.size(); ++i)
        if (abs(n[i] - x) < smallestDiff)
        {
            smallestDiff = abs(n[i] - x);
            minIndex = i; // starting point... ideally zero...
        }
    // starting point assigned
    maxIndex = minIndex + 1;
    vector<int> out;
    while (out.size() < k)
    {
        if (minIndex >= 0 && (maxIndex >= n.size() || abs(n[minIndex] - x) <= abs(n[maxIndex] - x)))
        {
            out.insert(out.begin(), n[minIndex]);
            --minIndex;
        }
        else if (maxIndex < n.size() || minIndex < 0)
        {
            out.push_back(n[maxIndex]);
            maxIndex++;
        }
    }
    sort(out.begin(), out.end());
    return out;
}

int main()
{
    vector<int> out = findClosestElements(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 4, 2);
    for (auto const &i : out)
        cout << i << " ";
    cout << "\n";
}
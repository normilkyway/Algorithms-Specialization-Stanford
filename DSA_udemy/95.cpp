#include <bits/stdc++.h>
using namespace std;

bool validBfs(int n, vector<int> sequence, vector<vector<int>> edges)
{
    map<int, map<int, bool>> m;
    for (auto e : edges)
        m[e[0]][e[1]] = m[e[1]][e[0]] = true;

    queue<int> q;
    unordered_map<int, bool> visited;

    vector<int> index(n + 1);
    for (int i = 0; i < n; ++i)
        index[sequence[i]] = i;

    q.push(1);
    visited[1] = true;

    int p = 1;
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        vector<int> nbrs;

        for (auto &nbr : m[c])
        {
            if (!visited[nbr.first])
                nbrs.push_back(nbr.first);
        }

        sort(nbrs.begin(), nbrs.end(), [&](int a, int b)
             { return index[a] < index[b]; });

        for (auto &nbr : nbrs)
        {
            if (p >= sequence.size() || nbr != sequence[p])
                return false;
            visited[nbr] = true;
            q.push(nbr);
            p++;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
            return false;
    }

    return true;
}

// #include <bits/stdc++.h>
// using namespace std;

// bool validBfs(int n, vector<int> sequence, vector<vector<int>> edges)
// {
//     map<int, map<int, bool>> m;
//     for (auto e : edges)
//         m[e[0]][e[1]] = m[e[1]][e[0]] = true;
//     queue<int> q;
//     unordered_map<int, bool> visited;
//     q.push(1);
//     visited[1] = true;
//     int p = 1;
//     while (!q.empty())
//     {
//         int c = q.front();
//         q.pop();
//         int n = m[c].size(); // n neighbors
//         for (int i = p; i < p + n; ++i)
//         {
//             if (i >= sequence.size() || m[c].find(sequence[i]) == m[c].end()) // we cannot visit all neighbors OR this specific thing isn't a neighbor
//                 return false;
//             else
//             {
//                 q.push(sequence[i]);
//                 visited[sequence[i]] = true;
//             }
//         }
//         p += n;
//     }
//     for (int i = 1; i <= n; ++i)
//         if (!visited[i])
//             return false;
//     return true;
// }

// /*
// // range of values we can check based on current ideas
//         bool found = false;
//         for (int i = p; i < p + range; ++i)
//             if (sequence[i] == c)
//                 found = true;
//         if (!found)
//             return false;
//         // update the range, visit properly, increment p
//         for (auto p : m[c]) {
//             if (!visited[p]) {

//             }
//         }
// */
#include <bits/stdc++.h>
using namespace std;

int messageRoute(int n, vector<vector<int>> edges)
{
    /**
     * Input: n= 5, edges= [[1,2],[1,3],[1,4],[2,3],[5,4]]
     * 1 -> 2, 3, 4
     * 2 -> 3
     * 4 -> 5
     * 5 -> 4
     *
     * to get to 5, shortest path will be from 1 -> 4 -> 5 (3 computers touched on the network)
     */

    map<int, map<int, bool>> g;
    for (auto edge : edges) // create the connection;
        g[edge[0]][edge[1]] = g[edge[1]][edge[0]] = true;
    // bfs
    queue<int> q;
    unordered_map<int, int> visited;
    q.push(1);
    visited[1] = 1;
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        if (c == n)
            return visited[c];
        for (auto nbr : g[c])
        { // iterate over every neighbor of this current node
            if (!visited[nbr.first])
            {
                visited[nbr.first] = visited[c] + 1;
                q.push(nbr.first);
            }
        }
    }
    return -1; // not found yet
}
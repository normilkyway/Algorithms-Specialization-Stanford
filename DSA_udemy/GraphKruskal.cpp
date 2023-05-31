#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent;

public:
    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
            parent[b] = a;
    }
};

class Graph
{
public:
    map<string, map<string, int>> edges;

    void addEdge(string u, string v, int w)
    {
        edges[u][v] = w;
        edges[v][u] = w;
    }

    void kruskalMST()
    {
        vector<pair<int, pair<string, string>>> sorted_edges;

        for (auto &p : edges)
            for (auto &nbr : p.second)
                sorted_edges.push_back({nbr.second, {p.first, nbr.first}});

        sort(sorted_edges.begin(), sorted_edges.end());

        DSU dsu(edges.size());

        map<string, int> city_to_int;

        int idx = 0;
        for (auto &p : edges)
        {
            city_to_int[p.first] = idx;
            idx++;
        }

        for (auto &p : sorted_edges)
        {
            int w = p.first;
            string city1 = p.second.first;
            string city2 = p.second.second;

            if (dsu.find(city_to_int[city1]) != dsu.find(city_to_int[city2]))
            {
                cout << city1 << " - " << city2 << " : " << w << endl;
                dsu.unite(city_to_int[city1], city_to_int[city2]);
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge("A", "B", 1);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "C", 3);
    g.addEdge("C", "D", 4);

    cout << "Edges in MST are: \n";
    g.kruskalMST();

    return 0;
}

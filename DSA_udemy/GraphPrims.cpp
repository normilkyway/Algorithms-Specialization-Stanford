#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<string, map<string, int>> edges;

    void addEdge(string u, string v, int w)
    {
        edges[u][v] = w;
        edges[v][u] = w;
    }

    void primMST()
    {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        unordered_map<string, bool> inMST;
        unordered_map<string, int> key;
        unordered_map<string, string> parent;

        string start = edges.begin()->first; // get the first node
        for (auto &p : edges)
        {
            string city = p.first;
            key[city] = INT_MAX;
            inMST[city] = false;
            parent[city] = "";
        }

        pq.push({0, start});
        key[start] = 0;

        while (!pq.empty())
        {
            string city = pq.top().second;
            pq.pop();

            inMST[city] = true;

            for (auto &nbr : edges[city])
            {
                string dest = nbr.first;
                int weight = nbr.second;

                if (!inMST[dest] && key[dest] > weight)
                {
                    key[dest] = weight;
                    pq.push({key[dest], dest});
                    parent[dest] = city;
                }
            }
        }

        for (auto &p : parent)
        {
            if (p.second != "")
                cout << p.second << " - " << p.first << " : " << key[p.first] << endl;
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
    g.primMST();

    return 0;
}

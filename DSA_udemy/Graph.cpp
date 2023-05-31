#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *l; // linked-list

public:
    Graph(int v)
    {
        V = v; // vertices (ie. points)
        l = new list<int>[V];
    }
    void addEdge(int i, int j, bool undirected = true)
    {
        l[i].push_back(j);
        if (undirected)
            l[j].push_back(i);
    }
    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "--> ";
            for (auto node : l[i])
                cout << node << " ";
            cout << "\n";
        }
    }
};

int main()
{
    Graph g(10);
    int counter;
    set<int> used;
    while (counter < 10)
    {
        int x, y;
        x = rand() % 10;
        y = rand() % 10;
        if (x != y && used.find(x) == used.end() && used.find(y) == used.end())
        {
            g.addEdge(x, y);
            // used.insert(x);
            // used.insert(y);
            ++counter;
        }
    }
    g.print();
}
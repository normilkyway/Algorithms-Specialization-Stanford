#include <bits/stdc++.h>
using namespace std;

class Node
{
public: // data members should be public to access them outside of the class
    string city;
    vector<pair<string, int>> nbrs; // neighboring cities

    Node(string city)
    {
        this->city = city;
        // nbrs is automatically initialized as an empty vector,
        // no need to create it with 'new'
    }
};

class Graph
{
    unordered_map<string, Node *> m; // the asterisk (*) should be after the data type

public:
    Graph(vector<string> cities)
    {
        for (auto city : cities)
            m[city] = new Node(city); // allocate new Node
    }

    void addEdge(string x, string y, int weight, bool directed = true)
    {
        m[x]->nbrs.push_back({y, weight}); // use 'push_back' instead of 'add'
        if (!directed)
            m[y]->nbrs.push_back({x, weight}); // use 'push_back' instead of 'add'
    }

    void print()
    {
        for (auto &cityPair : m) // it should be a pair (city, Node*)
        {
            cout << cityPair.first << "--> ";       // access city name
            for (auto &nbr : cityPair.second->nbrs) // access neighbors
                cout << nbr << " ";
            cout << endl;
        }
    }

    void BFS()
    {
        vector<int>
    }
};

int main()
{
    vector<string> cities = {"London", "Dehli", "Jesuspur", "NYC"};
    Graph g(cities);
    g.addEdge("London", "Dehli");
    g.addEdge("London", "Jesuspur");
    g.addEdge("Jesuspur", "London");
    g.print(); // added to visualize the output
}

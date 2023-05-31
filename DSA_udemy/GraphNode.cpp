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
                cout << nbr.first << " (" << nbr.second << ") ";
            cout << endl;
        }
    }

    void printPrimsMST()
    {
        unordered_map<string, string> parent;
        unordered_map<string, int> key;
        unordered_map<string, bool> inMST;

        for (auto cityPair : m)
        {
            string city = cityPair.first;
            key[city] = INT_MAX;
            inMST[city] = false;
        }
        // smallest element on top ~ "greater<pair<int, string>>"
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        string start = m.begin()->first; // Let's start with the first city // can be any, the MST will be the same given that everything is valid and there are no equivalent edge weights
        key[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            string city = pq.top().second; // get the city name
            pq.pop();                      // remove the city, recalculates to get the smallest city to the top (bubbles up in the heap of the pq)

            inMST[city] = true;

            for (auto nbr : m[city]->nbrs) // iterate over all neighbors
            {
                string dest = nbr.first;
                int weight = nbr.second;

                if (inMST[dest] == false && key[dest] > weight)
                // if (inMST[dest] == false && key[dest] > weight): This line checks
                // if the neighboring city is not yet included in the MST (inMST[dest] == false)
                // and if the current weight to that city (key[dest]) is greater than the
                // weight of the edge from the current city to the neighboring city. If
                // both conditions are true, it means we have found a shorter path to the neighboring city.
                {
                    key[dest] = weight;
                    pq.push({key[dest], dest});
                    parent[dest] = city;
                }
            }
        }

        for (auto cityPair : m)
        {
            string city = cityPair.first;
            if (city != start)
            {
                cout << parent[city] << " - " << city << " \t" << key[city] << endl;
            }
        }
    }
};

int main()
{
    vector<string> cities = {"London", "Dehli", "Jesuspur", "NYC"};
    // MST requirements: undirected graph | Prims/Kruskals algorithm
    // MSA requirements: directed graph | Edmonds' algorithm
    Graph g(cities);
    g.addEdge("London", "Dehli", 10, false);
    g.addEdge("London", "Jesuspur", 15, false);
    g.addEdge("Jesuspur", "London", 18, false);
    g.print(); // added to visualize the output
}

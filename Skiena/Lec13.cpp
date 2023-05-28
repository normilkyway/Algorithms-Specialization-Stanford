#include <iostream>

using namespace std;

#define MAXV 100 /*maximum number of vertices*/

typedef structure edgenode
{
    int y;                    // adjacency info
    int weight;               // edge weight if any
    structure edgenode *next; // next edge in the list
}
edgenode;

typedef struct
{
    edgenode *edges[MAXV]; // adjacency info
    int degree[MAXV];      // outdegree of each vertex
    int nvertices;         // number of vertices in the graph
    int nedges;            // number of edges in the graph
    int directed;          // is the graph directed?
} graph;

void initialize_graph(graph *g, bool directed)
{
    /* pointer to g, assign to variables through -> */
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;

    for (int i = 0; i <= MAXV; i++) // access starts at 0 (not incrementing any component cause I'm a boss)
    {
        g->degree[i] = 0;   // will be set as we add edges to this implementation.
        g->edges[i] = NULL; // set edge component to null for each index...
    }
}

int main()
{
}

/**
 * Chapter 7: Graph Traversal
 *      * G = (V, E)
 *      *
 */

/**
 * DATE: 5/28/23
 * TODO:
 *      1. IMPLEMENT the basic node, graph, & tree structures and then implement these data-structures in those components
 *      2. Read chapter 7/8
 * Topological Sort
 *      ~ applications of topological sort
 *      ~ kid hitting in the head with rocks
 *      ~ rows of kids hitting each other with rocks
 *      * general idea: find all in-zero nodes,
 *      * add them to the left, remove all in-zero nodes
 *      * and repeat until you have no nodes (if you
 *      * have nodes left, you do NOT have a DAG).
 * MSTs
 *      ~ find the tree with the total minimum weight connecting all vertices that doesn't have any cycles
 *      ~ N^(N-2) total spanning trees, max spanning tree would be a connected graph (every single node is connected? idk revisit)
 *      ~ greedy solution works in finding the MST!
 *      ~ useful in routing applications (ie. suppose you want to route an internet request between connected computers in the shortest amount of time)
 *      ! might be similar to flood-fill algorithms
 *      * general idea: start at an arbitrary node in the graph,
 *      * find the smallest edge connecting this node to a UNCONNECTED
 *      * node, connect these two nodes if the result doesn't result
 *      * in a graph, repeat finding the smallest edge and the
 *      * connections until ALL nodes are connected
 * Prims Algorithm: Algorithm for building the MST ~ O(n*m) WC
 *      ~ greedy approach as outlined in the MST approach above
 * Kruskalls: Algorithm for building the MST ~ O(n*m) WC
 *      ~ greedy approach in a similar manner to topological sort where you are looking at the broad picture
 *      * general idea: look at the graph and rank the order of the edge weights from smallest to largest
 *      * connect the smallest edge weight that does NOT result in a connected graph
 *      * (this means that at specific stages in the cycle you will have a unconnected tree components...)
 */
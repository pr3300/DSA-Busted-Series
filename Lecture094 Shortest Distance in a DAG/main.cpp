#include <bits/stdc++.h>
using namespace std;
/**
 * @class graph
 * @brief Represents a directed graph using an adjacency list.
 */
class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    /**
     * @brief Adds a directed edge from node u to node v with weight w to the adjacency list.
     * @param u The source node.
     * @param v The destination node.
     * @param w The weight of the edge.
     */
    void addEdge(int u, int v, int w)
    {
        pair<int, int> p = make_pair(v, w);
        adj[u].push_back(p);
    }

    /**
     * @brief Prints the adjacency list of the graph.
     */
    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << " , " << j.second << ")";
            }
            cout << endl;
        }
    }

    /**
     * @brief Performs a depth-first search (DFS) traversal of the graph starting from the given node.
     * @param node The starting node for the DFS traversal.
     * @param vis A map to keep track of visited nodes.
     * @param s A stack to store the visited nodes in the order they are visited.
     * @param adj The adjacency list of the graph.
     */
    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &s)
    {
        vis[node] = 1;
        for (auto neigh : adj[node])
        {
            if (!vis[neigh.first])
            {
                dfs(neigh.first, vis, s);
            }
        }
        s.push(node);
    }

    /**
     * @brief Calculates the shortest path from the source node to all other nodes using a topological sort and dynamic programming approach.
     * @param dist A vector to store the shortest distances from the source node to each node.
     * @param src The source node.
     * @param s A stack containing the nodes in topological order.
     */
    void getShortestPath(vector<int> &dist, int src, stack<int> &s)
    {
        dist[src] = 0;

        while (!s.empty())
        {
            int node = s.top();
            s.pop();

            if (dist[node] != INT_MAX)
            {
                for (auto neigh : adj[node])
                {
                    if (dist[node] + neigh.second < dist[neigh.first])
                        dist[neigh.first] = dist[node] + neigh.second;
                }
            }
        }
    }
};

int main()
{
    graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    // topological sort

    int n = 6;
    unordered_map<int, bool> vis;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            g.dfs(i, vis, s);
        }
    }

    int src = 1;
    vector<int> dist(n, INT_MAX);

    g.getShortestPath(dist, src, s);
    cout << "Printing Ans:" << endl;
    for (auto ele : dist)
    {
        if (ele == INT_MAX)
            cout << "INF, ";
        else
            cout << ele << " , ";
    }
    cout << endl;
    return 0;
}
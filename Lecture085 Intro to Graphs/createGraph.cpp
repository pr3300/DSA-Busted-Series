#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, vector<int>> gr;
    void addEdge(int u, int v, bool direction)
    {
        if (find(gr[u].begin(), gr[u].end(), v) == gr[u].end())
        {
            gr[u].push_back(v);
        }
        if (direction == 0)
        {
            if (find(gr[v].begin(), gr[v].end(), u) == gr[v].end())
            {
                gr[v].push_back(u);
            }
        }
    }
    void printGraph()
    {
        for (const auto &i : gr)
        {
            cout << i.first << " -> ";
            for (const auto &j : i.second)
            {
                cout << j << " ,";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "Enter no of nodes: ";
    cin >> n;
    cout << "Enter no of edges: ";
    cin >> m;
    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.printGraph();
    return 0;
}
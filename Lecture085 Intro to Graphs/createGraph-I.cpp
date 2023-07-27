#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    void addEdge(int &u, int &v, int n, int m, vector<vector<int>> &vec)
    {
        vec[u][v] = 1;
    }
    void printGraph(int &u, int &v, int n, int m, vector<vector<int>> &vec)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vec[i][j] == 1)
                {
                    cout << i << " - " << j << ":";
                }
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
    int u, v;
    vector<vector<int>> vec(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {

        cin >> u >> v;
        g.addEdge(u, v, n, m, vec);
    }

    g.printGraph(u, v, n, m, vec);
    return 0;
}
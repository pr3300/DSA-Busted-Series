#include <bits/stdc++.h>
using namespace std;
/**
 * @class DisjointSet
 * @brief A class that implements the disjoint-set data structure.
 * 
 * The disjoint-set data structure is used to keep track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.
 */
class DisjointSet
{
    vector<int> rank, parent;

public:
    /**
     * @brief Constructor that creates a new disjoint-set data structure with a given number of elements.
     * @param n The number of elements in the disjoint-set data structure.
     */
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    /**
     * @brief Finds the parent of a given element in the disjoint-set data structure.
     * @param node The element for which to find the parent.
     * @return The parent of the given element.
     */
    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    /**
     * @brief Merges two subsets together by their rank, ensuring that the smaller subset is merged into the larger subset.
     * @param u The first element of the subset to merge.
     * @param v The second element of the subset to merge.
     */
    void unionByRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return;

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    if (ds.findParent(3) == ds.findParent(7))
        cout << "Same" << endl;
    else
        cout << "Not Same" << endl;
    ds.unionByRank(3, 7);
    if (ds.findParent(3) == ds.findParent(7))
        cout << "Same" << endl;
    else
        cout << "Not Same" << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU
{
public:
    vector<int> parent, rank;
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }
    void union_sets(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};

// Task 1: Basic Operations of DSU
void task1(int n, vector<pair<int, int>> operations)
{
    DSU dsu(n);
    for (auto [op, x] : operations)
    {
        if (op == 1)
        {
            cout << dsu.find(x) << "\n";
        }
        else
        {
            dsu.union_sets(op, x);
        }
    }
}

// Task 2: Union by Rank & Path Compression
void task2(int n, vector<pair<int, int>> operations)
{
    DSU dsu(n);
    for (auto [a, b] : operations)
    {
        dsu.union_sets(a, b);
        for (int i = 1; i <= n; i++)
            cout << dsu.find(i) << "(" << dsu.rank[i] << ") ";
        cout << "\n";
    }
}

// Task 3: Count Connected Components after Each Road Addition
void task3(int n, vector<pair<int, int>> roads)
{
    DSU dsu(n);
    int components = n, largest = 1;
    vector<int> size(n + 1, 1);
    for (auto [a, b] : roads)
    {
        int rootA = dsu.find(a), rootB = dsu.find(b);
        if (rootA != rootB)
        {
            components--;
            dsu.union_sets(a, b);
            int newRoot = dsu.find(a);
            size[newRoot] = size[rootA] + size[rootB];
            largest = max(largest, size[newRoot]);
        }
        cout << components << " " << largest << "\n";
    }
}

// Task 4: Replacing Roads to Keep the Graph Connected
void task4(int n, vector<pair<int, int>> roads)
{
    DSU dsu(n);
    vector<pair<int, int>> extraEdges, newEdges;
    for (auto [a, b] : roads)
    {
        if (dsu.find(a) == dsu.find(b))
            extraEdges.push_back({a, b});
        else
            dsu.union_sets(a, b);
    }
    for (int i = 2; i <= n; i++)
    {
        if (dsu.find(1) != dsu.find(i))
        {
            newEdges.push_back({1, i});
            dsu.union_sets(1, i);
        }
    }
    cout << newEdges.size() << "\n";
    for (size_t i = 0; i < newEdges.size(); i++)
        cout << extraEdges[i].first << " " << extraEdges[i].second << " " << newEdges[i].first << " " << newEdges[i].second << "\n";
}

int main()
{
    // Example: Running Task 1
    int n1 = 9;
    vector<pair<int, int>> operations1 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 2}, {6, 7}, {1, 7}, {7, 8}};
    task4(n1, operations1);
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

const int N = 100005;
int parent[N], sizeSet[N];

void makeSet(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sizeSet[i] = 1;
    }
}

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int a, int b, vector<pair<int, int>> &extraEdges)
{
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB)
    {
        if (sizeSet[rootA] > sizeSet[rootB])
        {
            parent[rootB] = rootA;
            sizeSet[rootA] += sizeSet[rootB];
        }
        else
        {
            parent[rootA] = rootB;
            sizeSet[rootB] += sizeSet[rootA];
        }
    }
    else
    {
        extraEdges.push_back({a, b});
    }
}

int main()
{
    int n;
    cin >> n;

    makeSet(n);
    vector<pair<int, int>> extraEdges, newEdges;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        unionSets(a, b, extraEdges);
    }

    for (int i = 2; i <= n; i++)
    {
        if (find(1) != find(i))
        {
            newEdges.push_back({1, i});
            unionSets(1, i, extraEdges);
        }
    }

    cout << newEdges.size() << endl;
    for (int i = 0; i < newEdges.size(); i++)
    {
        cout << extraEdges[i].first << " " << extraEdges[i].second << " "
             << newEdges[i].first << " " << newEdges[i].second << endl;
    }

    return 0;
}

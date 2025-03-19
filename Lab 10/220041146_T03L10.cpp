#include <iostream>

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

void unionSets(int a, int b, int &components, int &largest)
{
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB)
    {
        components--;
        if (sizeSet[rootA] > sizeSet[rootB])
        {
            parent[rootB] = rootA;
            sizeSet[rootA] += sizeSet[rootB];
            largest = max(largest, sizeSet[rootA]);
        }
        else
        {
            parent[rootA] = rootB;
            sizeSet[rootB] += sizeSet[rootA];
            largest = max(largest, sizeSet[rootB]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int components = n, largest = 1;
    makeSet(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        unionSets(a, b, components, largest);
        cout << components << " " << largest << endl;
    }

    return 0;
}

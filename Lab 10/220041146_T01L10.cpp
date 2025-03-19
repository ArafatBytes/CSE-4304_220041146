#include <iostream>

using namespace std;

const int N = 100005;
int parent[N];

void makeSet(int n)
{
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int find(int x)
{
    if (parent[x] == x)
        return x;
    return find(parent[x]);
}

void unionSets(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB)
        parent[rootB] = rootA;
}

int main()
{
    int n, q;
    cin >> n >> q;
    makeSet(n);

    while (q--)
    {
        int type, a, b;
        cin >> type >> a;
        if (type == 3)
        {
            cin >> b;
            unionSets(a, b);
            for (int i = 0; i < n; i++)
            {
                cout << parent[i] << " ";
            }
            cout << endl;
        }
        else if (type == 2)
        {
            cout << find(a) << endl;
        }
        else if (type == 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << parent[i] << " " << endl;
            }
        }
    }

    return 0;
}

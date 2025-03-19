#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100;
vector<int> adj[MAX_NODES];

int main()
{
    int N, M, a, b;
    cin >> N >> M;

    vector<int> degree(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    int firstDegree = degree[1];
    bool isKRegular = true;

    for (int i = 2; i <= N; i++)
    {
        if (degree[i] != firstDegree)
        {
            isKRegular = false;
            break;
        }
    }

    if (isKRegular)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}

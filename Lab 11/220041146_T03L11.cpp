#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
int inDegree[1005];

int main()
{
    int N, M, u, v;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topoSort;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topoSort.push_back(node);

        for (int neighbor : adj[node])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    if (topoSort.size() != N)
    {
        cout << "[]" << endl;
    }
    else
    {
        for (int i = 0; i < topoSort.size(); i++)
        {
            cout << topoSort[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

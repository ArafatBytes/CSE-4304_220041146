#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adjList(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
    }

    int src, dest;
    cin >> src >> dest;

    vector<bool> visited(N + 1, false);

    vector<int> queue;
    queue.push_back(src);
    visited[src] = true;

    bool found = false;
    while (!queue.empty())
    {
        int node = queue.back();
        queue.pop_back();

        if (node == dest)
        {
            found = true;
            break;
        }

        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                queue.push_back(neighbor);
            }
        }
    }

    if (found)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adjList(V + 1);
    vector<vector<int>> adjMat(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);

        adjMat[u - 1][v - 1] = 1;
        adjMat[v - 1][u - 1] = 1;
    }

    for (int i = 1; i <= V; i++)
    {
        sort(adjList[i].begin(), adjList[i].end());
    }

    cout << "Adjacency List :" << endl;
    for (int i = 1; i <= V; i++)
    {
        cout << i << ": ";
        if (!adjList.empty())
        {
            for (int j = 0; j < adjList[i].size(); j++)
            {
                cout << adjList[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << "Adjacency Matrix: " << endl;
    for (int i = 1; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}
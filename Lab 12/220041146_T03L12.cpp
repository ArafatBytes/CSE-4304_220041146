#include <bits/stdc++.h>
using namespace std;

// BFS function to find the shortest path with k-hops
bool BFS(string src, string dst, int k, unordered_map<string, vector<string>> &adj, vector<string> &path)
{
    unordered_map<string, bool> visited;
    unordered_map<string, string> parent;
    queue<string> q;

    q.push(src);
    visited[src] = true;
    parent[src] = "";

    while (!q.empty())
    {
        string u = q.front();
        q.pop();

        if (u == dst)
        {
            // Construct the path
            while (!u.empty())
            {
                path.push_back(u);
                u = parent[u];
            }
            reverse(path.begin(), path.end());
            return true;
        }

        // Hop exactly `k` cities
        int count = 0;
        for (const string &v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
                count++;
            }
            if (count == k)
                break; // Ensure exactly k hops
        }
    }

    return false; // Destination not reachable
}

int main()
{
    int V, E, Q;
    cin >> V >> E >> Q;

    vector<string> cityNames(V);
    unordered_map<string, vector<string>> adj;

    // Read city names
    for (int i = 0; i < V; i++)
    {
        cin >> cityNames[i];
    }

    // Read edges
    for (int i = 0; i < E; i++)
    {
        string city1, city2;
        cin >> city1 >> city2;
        adj[city1].push_back(city2);
        adj[city2].push_back(city1); // Undirected graph
    }

    // Process queries
    for (int i = 0; i < Q; i++)
    {
        string src, dst;
        int k;
        cin >> src >> dst >> k;

        vector<string> path;
        if (BFS(src, dst, k, adj, path))
        {
            for (const string &city : path)
            {
                cout << city << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}

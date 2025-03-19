#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int distance;
    int predecessor;
    char color;
};

void printAdjList(const unordered_map<int, vector<int>> &adj)
{
    cout << "Adjacency list:\n";
    for (const auto &[node, neighbors] : adj)
    {
        cout << node << ": ";
        for (int neighbor : neighbors)
        {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
}

void BFS(int V, unordered_map<int, vector<int>> &adj, int src)
{
    unordered_map<int, Node> nodes;
    queue<int> q;
    vector<int> bfs_order;
    vector<pair<int, int>> bfs_tree_edges;

    // Initialize all nodes
    for (int i = 1; i <= V; i++)
    {
        nodes[i] = {-1, -1, 'W'};
    }

    // Start BFS
    nodes[src] = {0, -1, 'G'};
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        bfs_order.push_back(u);

        for (int v : adj[u])
        {
            if (nodes[v].color == 'W')
            {
                nodes[v] = {nodes[u].distance + 1, u, 'G'};
                q.push(v);
                bfs_tree_edges.emplace_back(u, v);
            }
        }
        nodes[u].color = 'B'; // Mark as fully explored
    }

    // Print BFS order
    cout << "BFS order: ";
    for (int v : bfs_order)
        cout << v << " ";
    cout << "\n";

    // Print distances
    cout << "Distance from source:\n";
    for (int i = 1; i <= V; i++)
    {
        cout << i << "(" << nodes[i].distance << ") ";
    }
    cout << "\n";

    // Print paths
    cout << "Paths from source:\n";
    for (int i = 1; i <= V; i++)
    {
        cout << i << ": ";
        if (nodes[i].distance == -1)
        {
            cout << "No path\n";
            continue;
        }
        vector<int> path;
        for (int at = i; at != -1; at = nodes[at].predecessor)
        {
            path.push_back(at);
        }
        for (int j = path.size() - 1; j >= 0; j--)
        {
            cout << path[j];
            if (j != 0)
                cout << "->";
        }
        cout << "\n";
    }

    // Print BFS tree edges
    cout << "Edges of BFS tree:\n";
    for (auto &edge : bfs_tree_edges)
    {
        cout << edge.first << " " << edge.second << "\n";
    }
}

int main()
{
    int V, E, src;
    cin >> V >> E >> src;

    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since the graph is undirected
    }

    printAdjList(adj);
    BFS(V, adj, src);

    return 0;
}

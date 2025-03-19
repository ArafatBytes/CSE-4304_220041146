#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int discovery, finish, predecessor;
    char color;
};

int time_counter = 0;
unordered_map<int, Node> nodes;
vector<int> dfs_order;
vector<pair<int, string>> edge_classification;

void classifyEdge(int u, int v)
{
    if (nodes[v].color == 'W')
    {
        edge_classification.push_back({u * 10 + v, "Tree Edge"});
    }
    else if (nodes[v].color == 'G')
    {
        edge_classification.push_back({u * 10 + v, "Back Edge"});
    }
    else if (nodes[u].discovery < nodes[v].discovery)
    {
        edge_classification.push_back({u * 10 + v, "Forward Edge"});
    }
    else
    {
        edge_classification.push_back({u * 10 + v, "Cross Edge"});
    }
}

void DFS_Visit(int u, unordered_map<int, vector<int>> &adj)
{
    nodes[u].color = 'G';
    nodes[u].discovery = ++time_counter;
    dfs_order.push_back(u);

    for (int v : adj[u])
    {
        classifyEdge(u, v);
        if (nodes[v].color == 'W')
        {
            nodes[v].predecessor = u;
            DFS_Visit(v, adj);
        }
    }

    nodes[u].color = 'B';
    nodes[u].finish = ++time_counter;
}

void DFS(int V, unordered_map<int, vector<int>> &adj)
{
    for (int i = 1; i <= V; i++)
    {
        nodes[i] = {-1, -1, -1, 'W'};
    }

    for (int i = 1; i <= V; i++)
    {
        if (nodes[i].color == 'W')
        {
            DFS_Visit(i, adj);
        }
    }

    cout << "DFS order: ";
    for (int v : dfs_order)
        cout << v << " ";
    cout << endl;

    cout << "Timestamps of Vertex (discovery/finishing):\n";
    for (int i = 1; i <= V; i++)
    {
        cout << i << "(" << nodes[i].discovery << "/" << nodes[i].finish << ")" << endl;
    }

    cout << "Edge classification:\n";
    for (auto &[edge, type] : edge_classification)
    {
        int u = edge / 10, v = edge % 10;
        cout << u << " " << v << ": " << type << "\n";
    }
}

void printAdjList(const unordered_map<int, vector<int>> &adj)
{
    cout << "Adjacency list: " << endl;
    for (const auto &[node, neighbors] : adj)
    {
        cout << node << ": ";
        for (int neighbor : neighbors)
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    printAdjList(adj);
    DFS(V, adj);

    return 0;
}

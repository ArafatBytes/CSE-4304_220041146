#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
const int LOG = 10; // log2(1000) < 10

int sparse[MAX_N][LOG];  // Sparse table
int logTable[MAX_N + 1]; // Precomputed log values
int arr[MAX_N];          // Input array

// Function to build the sparse table
void buildSparseTable(int n)
{
    // Compute log values
    logTable[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        logTable[i] = logTable[i / 2] + 1;
    }

    // Initialize sparse table for range [i, i] (single element)
    for (int i = 0; i < n; i++)
    {
        sparse[i][0] = arr[i];
    }

    // Fill sparse table
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// Function to query the minimum in range [L, R]
int query(int L, int R)
{
    int j = logTable[R - L + 1]; // Largest power of 2 within range
    return min(sparse[L][j], sparse[R - (1 << j) + 1][j]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // Read array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Build the sparse table
    buildSparseTable(n);

    // Print the ranges stored in the Sparse Table
    cout << "Ranges to be stored in Sparse Table:\n";
    for (int j = 0; (1 << j) <= n; j++)
    {
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            cout << "(" << i << "," << (i + (1 << j) - 1) << ") ";
        }
        cout << "\n";
    }

    // Print the Sparse Table
    cout << "\nStatus of Sparse Table:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; (1 << j) <= n; j++)
        {
            if (i + (1 << j) - 1 < n)
            {
                cout << sparse[i][j] << " ";
            }
        }
        cout << "\n";
    }

    int q;
    cin >> q;

    // Process queries
    for (int qi = 1; qi <= q; qi++)
    {
        int L, R;
        cin >> L >> R;
        L--;
        R--; // Convert to zero-based index

        int minVal = query(L, R);
        cout << "Query-" << qi << ": Min=" << minVal << " ";

        int j = logTable[R - L + 1];
        cout << "min([" << L << "," << R - (1 << j) + 1 << "],["
             << R - (1 << j) + 1 << "," << R << "])\n";
    }

    return 0;
}

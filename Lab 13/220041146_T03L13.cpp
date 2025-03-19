#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50000;
const int LOG = 16; // log2(50000) < 16

int sparse[MAX_N][LOG];  // Sparse table for range maximum query
int logTable[MAX_N + 1]; // Precomputed log values
int heights[MAX_N];      // Heights array

// Function to build the Sparse Table for range maximum queries
void buildSparseTable(int n)
{
    // Compute log values
    logTable[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        logTable[i] = logTable[i / 2] + 1;
    }

    // Initialize sparse table for single elements
    for (int i = 0; i < n; i++)
    {
        sparse[i][0] = heights[i];
    }

    // Fill sparse table for increasing powers of 2
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
        {
            sparse[i][j] = max(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// Function to get the maximum height in range [L, R]
int queryMax(int L, int R)
{
    if (L > R)
        return 0; // No elements in the range
    int j = logTable[R - L + 1];
    return max(sparse[L][j], sparse[R - (1 << j) + 1][j]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // Read heights
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    // Build the sparse table
    buildSparseTable(n);

    int successfulThrows = 0;

    // Process queries
    for (int i = 0; i < m; i++)
    {
        int A, B;
        cin >> A >> B;
        A--;
        B--; // Convert to zero-based index

        if (A > B)
            swap(A, B); // Ensure A < B for consistency

        // Get max height in the range (A+1 to B-1)
        int maxHeight = queryMax(A + 1, B - 1);

        // Check if the catapult is successful
        if (maxHeight < heights[A])
        {
            successfulThrows++;
        }
    }

    // Output the total successful throws
    cout << successfulThrows << "\n";

    return 0;
}

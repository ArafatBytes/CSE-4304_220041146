#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 1e5;
const int LOG = 20;

int st[MAXN][LOG];
int log2_table[MAXN + 1];

void buildSparseTable(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for (int j = 1; j < LOG; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = st[i][j - 1] | st[i + (1 << (j - 1))][j - 1];

    log2_table[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        log2_table[i] = log2_table[i / 2] + 1;
}

int query(int L, int R)
{
    int j = log2_table[R - L + 1];
    return st[L][j] | st[R - (1 << j) + 1][j];
}

int main()
{
    int N, Q;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    buildSparseTable(A, N);

    cin >> Q;
    while (Q--)
    {
        int L, R, i;
        cin >> L >> R >> i;
        L--;
        R--;
        i--;

        int result = query(L, R);
        if (result == A[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
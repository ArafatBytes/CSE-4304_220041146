#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (auto &e : a)
        cin >> e;

    vector<vector<long long>> sparse(n, vector<long long>(log2(n) + 10));

    for (long long i = 0; i < n; i++)
    {
        sparse[i][0] = a[i];
    }

    for (long long j = 1; j <= log2(n) + 10; j++)
    {
        for (long long i = 0; i < n; i++)
        {
            if (i + (1LL << j) > n)
            {
                break;
            }
            sparse[i][j] = __gcd(sparse[i][j - 1], sparse[i + (1LL << (j - 1))][j - 1]);
        }
    }

    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < log(n) + 10; j++)
        {
            if (i + (1LL << j) > n)
            {
                break;
            }
            cout << "(" << i << "," << i + (1LL << j) - 1 << ") ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < log(n) + 10; j++)
        {
            if (i + (1LL << j) > n)
            {
                break;
            }
            cout << sparse[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    long long q;
    cin >> q;
    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        long long pw = log2(r - l + 1);
        cout << __gcd(sparse[l][pw], sparse[r - (1LL << pw) + 1][pw]) << "\n";
    }
}

int main()
{
    long long t = 1;
    while (t--)
        solve();

    return 0;
}

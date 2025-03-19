#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1, 0);
    vector<int> prefix_zeros(n + 1, 0), prefix_ones(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        prefix_zeros[i] = prefix_zeros[i - 1] + (arr[i] == 0);
        prefix_ones[i] = prefix_ones[i - 1] + (arr[i] == 1);
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int count_zeros = prefix_zeros[r] - prefix_zeros[l - 1];
        int count_ones = prefix_ones[r] - prefix_ones[l - 1];

        if ((r - l + 1) % 2 != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << abs(count_zeros - count_ones) / 2 << endl;
        }
    }
}

int main()
{
    solve();
    return 0;
}

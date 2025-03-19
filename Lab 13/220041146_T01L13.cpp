#include <bits/stdc++.h>
using namespace std;

const int ALPHA = 26; // Number of lowercase English letters

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    int q;
    cin >> q;

    // Prefix frequency array where freq[i][ch] stores occurrences of 'ch' in prefix [0..i]
    vector<vector<int>> freq(n + 1, vector<int>(ALPHA, 0));

    // Compute prefix frequency sum
    for (int i = 0; i < n; i++)
    {
        for (int ch = 0; ch < ALPHA; ch++)
        {
            freq[i + 1][ch] = freq[i][ch]; // Carry forward previous frequency
        }
        freq[i + 1][s[i] - 'a']++; // Increment frequency of current character
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--; // Convert to 0-based index

        // Find the most frequent character in the substring s[l, r]
        int maxFreq = 0;
        char result = 'z'; // Store the lexicographically smallest character in case of a tie

        for (int ch = 0; ch < ALPHA; ch++)
        {
            int count = freq[r + 1][ch] - freq[l][ch]; // Frequency of character ch in range [l, r]
            if (count > maxFreq || (count == maxFreq && (ch + 'a') < result))
            {
                maxFreq = count;
                result = ch + 'a';
            }
        }

        cout << result << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

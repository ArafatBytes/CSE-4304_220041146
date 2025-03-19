#include <bits/stdc++.h>
using namespace std;

int main()
{
    int queries, segments, words;
    cin >> queries >> segments >> words;

    map<string, vector<string>> mappings;

    while (queries--)
    {
        string personName;
        cin >> personName;

        string mergedData = "";
        for (int segmentIdx = 0; segmentIdx < segments; ++segmentIdx)
        {
            string segment;
            cin >> segment;
            mergedData += segment;
        }

        mappings[mergedData].emplace_back(personName);
    }

    for (const auto &[key, names] : mappings)
    {
        for (const auto &name : names)
        {
            cout << name << " ";
        }
        cout << endl;
    }

    return 0;
}

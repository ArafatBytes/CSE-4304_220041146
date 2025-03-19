#include <bits/stdc++.h>
using namespace std;

vector<string> findRepeatedSequences(string s)
{
    unordered_map<string, int> sequenceCount;
    vector<string> result;

    for (int i = 0; i + 10 <= s.size(); ++i)
    {
        string sequence = s.substr(i, 10);
        sequenceCount[sequence]++;
    }

    for (const auto &pair : sequenceCount)
    {
        if (pair.second > 1)
        {
            result.push_back(pair.first);
        }
    }

    return result;
}

int main()
{
    string dna;
    cin >> dna;

    vector<string> repeatedSequences = findRepeatedSequences(dna);

    for (const string &seq : repeatedSequences)
    {
        cout << seq << " ";
    }
    cout << endl;

    return 0;
}

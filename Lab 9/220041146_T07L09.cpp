#include <bits/stdc++.h>
using namespace std;

bool matchesAbbreviation(const string &word, const string &abbreviation)
{
    int j = 0;
    for (char ch : word)
    {
        if (isupper(ch))
        {
            if (j < abbreviation.size() && ch == abbreviation[j])
            {
                j++;
            }
            else
            {
                return false;
            }
        }
    }
    return j == abbreviation.size();
}

int main()
{
    vector<string> words;
    string word, abbreviation;

    while (true)
    {
        cin >> word;
        if (word == "-1")
            break;
        words.push_back(word);
    }

    cin >> abbreviation;

    for (const string &word : words)
    {
        if (matchesAbbreviation(word, abbreviation))
            cout << "T ";
        else
            cout << "F ";
    }

    cout << endl;
    return 0;
}

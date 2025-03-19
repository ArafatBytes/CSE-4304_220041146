#include <bits/stdc++.h>
using namespace std;

string createSignature(const string &word)
{
    set<char> uniqueChars(word.begin(), word.end());
    string signature;
    for (char c : uniqueChars)
    {
        signature += c;
    }
    return signature;
}

int main()
{
    string sentence, word;
    getline(cin, sentence);
    cin >> word;

    string targetSignature = createSignature(word);
    istringstream iss(sentence);
    vector<string> matchingWords;

    string token;
    while (iss >> token)
    {
        if (createSignature(token) == targetSignature)
        {
            matchingWords.push_back(token);
        }
    }

    for (const string &match : matchingWords)
    {
        cout << match << " ";
    }
    cout << endl;

    return 0;
}

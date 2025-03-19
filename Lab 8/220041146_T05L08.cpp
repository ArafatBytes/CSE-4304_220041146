#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> morseCode = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
        ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
        ".--", "-..-", "-.--", "--.."};

    int wordCount;
    cin >> wordCount;

    vector<string> inputWords(wordCount);
    for (int idx = 0; idx < wordCount; ++idx)
    {
        cin >> inputWords[idx];
    }

    set<string> uniqueTransformations;

    for (const auto &word : inputWords)
    {
        string encoded = "";
        for (char ch : word)
        {
            encoded += morseCode[ch - 'a'];
        }
        uniqueTransformations.insert(encoded);
    }

    cout << uniqueTransformations.size() << endl;
    for (const auto &code : uniqueTransformations)
    {
        cout << code << endl;
    }

    return 0;
}

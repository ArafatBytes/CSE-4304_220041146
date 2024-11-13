#include <bits/stdc++.h>
using namespace std;

int main()
{
    string inputText;
    getline(cin, inputText);

    string processedText;
    for (char character : inputText)
    {
        if (isalpha(character) || character == ' ')
        {
            processedText += character;
        }
    }
    unordered_map<string, int> frequencyMap;
    istringstream stream(processedText);
    string currentWord;
    while (stream >> currentWord)
    {
        frequencyMap[currentWord]++;
    }
    for (const auto &pair : frequencyMap)
    {
        if (pair.second > 1)
        {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, string> dictionary;
    string line;

    while (getline(cin, line) && !line.empty())
    {
        istringstream iss(line);
        string english, foreign;
        iss >> english >> foreign;
        dictionary[foreign] = english;
    }

    while (getline(cin, line))
    {
        if (line.empty())
            break;
        if (dictionary.find(line) != dictionary.end())
        {
            cout << dictionary[line] << endl;
        }
        else
        {
            cout << "eh" << endl;
        }
    }

    return 0;
}

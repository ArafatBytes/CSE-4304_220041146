#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> numbers;
    int input;
    while (cin >> input && input != -1)
    {
        numbers.push_back(input);
    }

    int sumTarget;
    cin >> sumTarget;

    unordered_map<int, int> frequencyMap;
    for (int val : numbers)
    {
        frequencyMap[val]++;
    }

    bool isPairFound = false;
    for (int val : numbers)
    {
        int neededValue = sumTarget - val;
        if (frequencyMap[val] > 0 && frequencyMap[neededValue] > 0)
        {
            if (val == neededValue && frequencyMap[val] > 1)
            {
                cout << "(" << val << ", " << neededValue << ")" << endl;
                frequencyMap[val] -= 2;
                isPairFound = true;
            }
            else if (val != neededValue)
            {
                cout << "(" << val << ", " << neededValue << ")" << endl;
                frequencyMap[val]--;
                frequencyMap[neededValue]--;
                isPairFound = true;
            }
        }
    }

    if (!isPairFound)
    {
        cout << "No pairs found" << endl;
    }

    return 0;
}

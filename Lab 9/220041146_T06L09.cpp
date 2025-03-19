#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *children[10];
    int prefixCount;

    TrieNode()
    {
        prefixCount = 0;
        fill(children, children + 10, nullptr);
    }
};

void insertNumber(TrieNode *root, const string &number)
{
    TrieNode *current = root;
    for (char digit : number)
    {
        int index = digit - '0';
        if (current->children[index] == nullptr)
        {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
        current->prefixCount++;
    }
}

int findMaxPrefix(TrieNode *root, const string &number)
{
    TrieNode *current = root;
    int length = 0;

    for (char digit : number)
    {
        int index = digit - '0';
        if (current->children[index] != nullptr)
        {
            length++;
            current = current->children[index];
        }
        else
        {
            break;
        }
    }

    return length;
}

int main()
{
    int size1, size2;
    cin >> size1 >> size2;

    vector<string> list1(size1), list2(size2);
    for (string &num : list1)
    {
        cin >> num;
    }
    for (string &num : list2)
    {
        cin >> num;
    }

    TrieNode *trieRoot = new TrieNode();

    for (const string &number : list2)
    {
        insertNumber(trieRoot, number);
    }

    int maxPrefixLength = 0;
    for (const string &number : list1)
    {
        maxPrefixLength = max(maxPrefixLength, findMaxPrefix(trieRoot, number));
    }

    cout << maxPrefixLength << endl;

    return 0;
}

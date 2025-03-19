#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    bool isEnd;

    TrieNode()
    {
        isEnd = false;
        fill(children, children + 26, nullptr);
    }
};

void addWord(TrieNode *root, const string &word)
{
    TrieNode *current = root;
    for (char c : word)
    {
        int index = c - 'a';
        if (current->children[index] == nullptr)
        {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->isEnd = true;
}

bool isWordPresent(TrieNode *root, const string &word)
{
    TrieNode *current = root;
    for (char c : word)
    {
        int index = c - 'a';
        if (current->children[index] == nullptr)
        {
            return false;
        }
        current = current->children[index];
    }
    return current->isEnd;
}

bool checkSegments(TrieNode *root, const string &target, int position)
{
    if (position == target.size())
    {
        return true;
    }

    TrieNode *current = root;
    for (int i = position; i < target.size(); ++i)
    {
        int index = target[i] - 'a';
        if (current->children[index] == nullptr)
        {
            return false;
        }

        current = current->children[index];
        if (current->isEnd && checkSegments(root, target, i + 1))
        {
            return true;
        }
    }

    return false;
}

bool isConcatenated(TrieNode *root, const string &target)
{
    return checkSegments(root, target, 0);
}

int main()
{
    TrieNode *root = new TrieNode();
    string inputWord;

    while (true)
    {
        cin >> inputWord;
        if (inputWord == "-1")
            break;
        addWord(root, inputWord);
    }

    string targetWord;
    cin >> targetWord;

    if (isConcatenated(root, targetWord))
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }

    return 0;
}

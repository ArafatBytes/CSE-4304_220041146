#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *children[26];
    bool endOfWord;

    Trie()
    {
        endOfWord = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

void insert(Trie *root, string &word)
{
    Trie *current = root;
    for (char c : word)
    {
        int index = c - 'a';
        if (!current->children[index])
        {
            current->children[index] = new Trie();
        }
        current = current->children[index];
    }
    current->endOfWord = true;
}

bool search(Trie *root, string &word)
{
    Trie *current = root;
    for (char c : word)
    {
        int index = c - 'a';
        if (!current->children[index])
        {
            return false;
        }
        current = current->children[index];
    }
    return current->endOfWord;
}

void collect(Trie *root, string prefix, vector<string> &result)
{
    if (root->endOfWord)
    {
        result.push_back(prefix);
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i])
        {
            collect(root->children[i], prefix + char('a' + i), result);
        }
    }
}

void display(Trie *root)
{
    vector<string> words;
    collect(root, "", words);
    for (string &word : words)
    {
        cout << word << " ";
    }
    cout << endl;
}

int main()
{
    Trie *root = new Trie();
    string input;
    string query;

    getline(cin, input);
    vector<string> wordsToInsert;
    string word;
    for (char c : input)
    {
        if (c == ' ')
        {
            wordsToInsert.push_back(word);
            word = "";
        }
        else
        {
            word += c;
        }
    }
    if (!word.empty())
    {
        wordsToInsert.push_back(word);
    }

    for (string &w : wordsToInsert)
    {
        insert(root, w);
    }

    display(root);

    getline(cin, query);
    vector<string> queryList;
    word = "";
    for (char c : query)
    {
        if (c == ' ')
        {
            queryList.push_back(word);
            word = "";
        }
        else
        {
            word += c;
        }
    }
    if (!word.empty())
    {
        queryList.push_back(word);
    }

    for (string &q : queryList)
    {
        cout << (search(root, q) ? "T" : "F") << " ";
    }
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *children[26];
    int wordCount;
    Trie()
    {
        wordCount = 0;
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
        current->wordCount++;
    }
}

int no_of_words(Trie *root, string &prefix)
{
    Trie *current = root;
    for (char c : prefix)
    {
        int index = c - 'a';
        if (!current->children[index])
        {
            return 0;
        }
        current = current->children[index];
    }
    return current->wordCount;
}

string lowerCase(string &str)
{
    string result = str;
    for (char &c : result)
    {
        c = tolower(c);
    }
    return result;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    cin.ignore();

    Trie *root = new Trie();
    unordered_set<string> uniqueWords;

    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        word = lowerCase(word);
        uniqueWords.insert(word);
    }

    for (string word : uniqueWords)
    {
        insert(root, word);
    }

    for (int i = 0; i < Q; i++)
    {
        string prefix;
        cin >> prefix;
        prefix = lowerCase(prefix);
        cout << no_of_words(root, prefix) << endl;
    }

    return 0;
}

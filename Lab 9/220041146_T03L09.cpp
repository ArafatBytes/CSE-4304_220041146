#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *children[26];
    vector<string> words;

    Trie()
    {
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
        if (current->words.size() < 3)
        {
            current->words.push_back(word);
        }
    }
}

vector<vector<string>> getSuggestions(Trie *root, string &searchWord)
{
    vector<vector<string>> result;
    Trie *current = root;

    for (char c : searchWord)
    {
        int index = c - 'a';
        if (current->children[index])
        {
            current = current->children[index];
            result.push_back(current->words);
        }
        else
        {
            result.push_back({});
        }
    }

    return result;
}

int main()
{
    string productLine;
    getline(cin, productLine);
    vector<string> products;
    string product;

    for (char c : productLine)
    {
        if (c == ' ')
        {
            products.push_back(product);
            product = "";
        }
        else
        {
            product += c;
        }
    }
    if (!product.empty())
    {
        products.push_back(product);
    }
    string searchWord;
    cin >> searchWord;

    sort(products.begin(), products.end());

    Trie *root = new Trie();
    for (string &product : products)
    {
        insert(root, product);
    }

    vector<vector<string>> suggestions = getSuggestions(root, searchWord);

    for (auto &suggestion : suggestions)
    {
        if (!suggestion.empty())
        {
            for (string &word : suggestion)
            {
                cout << word << " ";
            }
        }
        else
        {
            cout << "Null";
        }
        cout << endl;
    }

    return 0;
}

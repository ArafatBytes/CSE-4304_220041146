#include <bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *children[2];

    Trie()
    {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

void insert(Trie *root, int num)
{
    Trie *current = root;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (num >> i) & 1;
        if (!current->children[bit])
        {
            current->children[bit] = new Trie();
        }
        current = current->children[bit];
    }
}

int findMaximumXOR(Trie *root, int num)
{
    Trie *current = root;
    int maxXOR = 0;

    for (int i = 31; i >= 0; i--)
    {
        int bit = (num >> i) & 1;

        if (current->children[1 - bit])
        {
            maxXOR |= (1 << i);
            current = current->children[1 - bit];
        }
        else
        {
            current = current->children[bit];
        }
    }

    return maxXOR;
}

int findMaximumXORInCollection(const vector<int> &nums)
{
    if (nums.size() < 2)
        return 0;

    Trie *root = new Trie();
    int maxXOR = 0;

    insert(root, nums[0]);

    for (size_t i = 1; i < nums.size(); i++)
    {
        maxXOR = max(maxXOR, findMaximumXOR(root, nums[i]));
        insert(root, nums[i]);
    }

    return maxXOR;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int maxXOR = findMaximumXORInCollection(nums);

    cout << "Maximum XOR value: " << maxXOR << endl;

    return 0;
}

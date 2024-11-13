#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *buildTree(const vector<char> &preorder, int &index)
{
    if (index >= preorder.size() || preorder[index] == '-')
    {
        index++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(preorder[index]);
    index++;

    node->left = buildTree(preorder, index);
    node->right = buildTree(preorder, index);

    return node;
}

void inorderTraversal(TreeNode *root, string &result)
{
    if (!root)
    {
        result += "- ";
        return;
    }
    inorderTraversal(root->left, result);
    result += root->val;
    result += " ";
    inorderTraversal(root->right, result);
}

void postorderTraversal(TreeNode *root, string &result)
{
    if (!root)
    {
        result += "- ";
        return;
    }
    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    result += root->val;
    result += " ";
}

int main()
{
    vector<char> tree;
    while (true)
    {
        char a;
        if (a == '/')
        {
            break;
        }
        cin >> a;
        tree.push_back(a);
    }
    int index = 0;
    TreeNode *root = buildTree(tree, index);

    string inorder, postorder;
    inorderTraversal(root, inorder);
    postorderTraversal(root, postorder);

    cout << "Inorder: " << inorder << endl;
    cout << "Postorder: " << postorder << endl;

    return 0;
}
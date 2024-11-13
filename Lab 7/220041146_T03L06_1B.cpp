#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int height;
    int subtree_size;
    Node *left, *right, *parent;

    Node(int val) : data(val), height(0), subtree_size(1), left(nullptr), right(nullptr), parent(nullptr) {}
};

int getHeight(Node *node)
{
    return node ? node->height : -1;
}

int getSubtreeSize(Node *node)
{
    return node ? node->subtree_size : 0;
}

void updateNode(Node *node)
{
    if (node)
    {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        node->subtree_size = 1 + getSubtreeSize(node->left) + getSubtreeSize(node->right);
    }
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateNode(y);
    updateNode(x);

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateNode(x);
    updateNode(y);

    return y;
}

int getBalance(Node *node)
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node *insert(Node *node, int key)
{
    if (!node)
        return new Node(key);

    if (key < node->data)
    {
        node->left = insert(node->left, key);
        node->left->parent = node;
    }
    else if (key > node->data)
    {
        node->right = insert(node->right, key);
        node->right->parent = node;
    }
    else
    {
        return node;
    }

    updateNode(node);

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    if (balance > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int lowerCount(Node *root, int key)
{
    int count = 0;
    while (root)
    {
        if (key > root->data)
        {
            count += getSubtreeSize(root->left) + 1;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return count;
}

int main()
{
    Node *root = nullptr;
    while (true)
    {
        int a;
        cin >> a;
        if (a != -1)
        {
            root = insert(root, a);
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        int n;
        cin >> n;
        cout << lowerCount(root, n) << endl;
    }

    return 0;
}

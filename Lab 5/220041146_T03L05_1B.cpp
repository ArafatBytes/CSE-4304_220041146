#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node *parent;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

void insert(node *&root, int val)
{
    node *newNode = new node(val);
    node *temp = root;
    node *target;
    if (temp == nullptr)
    {
        root = newNode;
    }
    else
    {
        while (temp != nullptr)
        {
            target = temp;
            if (newNode->data < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        newNode->parent = target;
        if (newNode->data < target->data)
        {
            target->left = newNode;
        }
        else
        {
            target->right = newNode;
        }
    }
}

void searchLCA(node *&root, int u, int v)
{
    node *temp = root;
    while (temp != nullptr)
    {
        if (u < temp->data && v < temp->data)
        {
            temp = temp->left;
        }
        else if (u > temp->data && v > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            cout << temp->data << endl;
            return;
        }
    }
}

int main()
{
    node *root = nullptr;
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        insert(root, a);
    }
    int op;
    cin >> op;
    while (op--)
    {
        int u, v;
        cin >> u >> v;
        searchLCA(root, u, v);
    }
}
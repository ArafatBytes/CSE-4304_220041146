#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    int height;
    int b_factor;
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

void updateHeight(node *&curr)
{
    node *temp = curr;
    while (temp != nullptr)
    {
        int left = (temp->left != nullptr) ? temp->left->height : -1;
        int right = (temp->right != nullptr) ? temp->right->height : -1;
        temp->height = max(left, right) + 1;
        temp = temp->parent;
    }
}

void updateBalanceFactor(node *&curr)
{
    node *temp = curr;
    while (temp != nullptr)
    {
        int left = (temp->left != nullptr) ? temp->left->height : -1;
        int right = (temp->right != nullptr) ? temp->right->height : -1;
        temp->b_factor = left - right;
        temp = temp->parent;
    }
}

void insert(node *&root, int val)
{
    node *newNode = new node(val);
    newNode->height = 0;
    node *temp = root;
    node *target;
    if (temp == nullptr)
    {
        root = newNode;
        root->height = 0;
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
    updateHeight(newNode);
    updateBalanceFactor(newNode);
}

void printTree(node *&root)
{
    node *temp = root;
    if (temp == nullptr)
    {
        return;
    }
    printTree(temp->left);
    cout << temp->data << "(" << temp->b_factor << ") ";
    printTree(temp->right);
}

int main()
{
    node *root = nullptr;
    while (true)
    {
        int a;
        cin >> a;
        if (a != -1)
        {
            insert(root, a);
            printTree(root);
            cout << endl;
        }
        else
        {
            break;
        }
    }
}
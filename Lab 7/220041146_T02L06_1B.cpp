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

void right_rotate(node *&y, node *&root)
{
    cout << "right_rotate(" << y->data << ")" << endl;
    node *x = y->left;
    node *xR = x->right;

    if (y == root)
    {
        root = x;
    }
    x->parent = y->parent;
    if (y->parent != nullptr && y == y->parent->right)
    {
        y->parent->right = x;
    }
    else if (y->parent != nullptr && y == y->parent->left)
    {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
    y->left = xR;
    if (xR != nullptr)
    {
        xR->parent = y;
    }

    return;
}

void left_rotate(node *&y, node *&root)
{
    cout << "left_rotate(" << y->data << ")" << endl;
    node *x = y->right;
    node *xL = x->left;

    if (y == root)
    {
        root = x;
    }
    x->parent = y->parent;
    if (y->parent != nullptr && y == y->parent->right)
    {
        y->parent->right = x;
    }
    else if (y->parent != nullptr && y == y->parent->left)
    {
        y->parent->left = x;
    }
    x->left = y;
    y->parent = x;
    y->right = xL;
    if (xL != nullptr)
    {
        xL->parent = y;
    }

    return;
}

void checkBalance(node *&curr, int val, node *&root)
{
    int balance;
    while (curr != nullptr && curr->b_factor <= 1 && curr->b_factor >= -1)
    {
        curr = curr->parent;
    }
    if (curr != nullptr)
    {
        balance = curr->b_factor;
    }
    else
    {
        cout << "\nBalanced\n";
        return;
    }
    if (balance > 1)
    {
        if (val < curr->left->data)
        {
            cout << "Imbalance at node: " << curr->data << "\nLL case" << endl;
            right_rotate(curr, root);
        }
        else
        {
            cout << "Imbalance at node: " << curr->data << "\nLR case" << endl;
            left_rotate(curr->left, root);
            right_rotate(curr, root);
        }
    }
    else if (balance < -1)
    {
        if (val > curr->right->data)
        {
            cout << "Imbalance at node: " << curr->data << "\nRR case" << endl;
            left_rotate(curr, root);
        }
        else
        {
            cout << "Imbalance at node: " << curr->data << "\nRL case" << endl;
            right_rotate(curr->right, root);
            left_rotate(curr, root);
        }
    }
}

void print_avl(node *&root)
{
    node *temp = root;
    if (temp == nullptr)
    {
        return;
    }
    print_avl(temp->left);
    cout << temp->data << "(" << temp->b_factor << ") ";
    print_avl(temp->right);
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
        root->parent = nullptr;
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
    print_avl(root);
    checkBalance(newNode, val, root);
    updateHeight(newNode);
    updateBalanceFactor(newNode);
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
            cout << endl;
            cout << "Status: ";
            print_avl(root);
            cout << "\nRoot=" << root->data << endl;
        }
        else
        {
            break;
        }
    }
}
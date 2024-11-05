#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    int height;
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
}

void inOrder(node *&root)
{
    node *temp = root;
    if (temp == nullptr)
    {
        return;
    }
    inOrder(temp->left);
    if (temp->parent != nullptr)
    {
        cout << temp->data << "(" << temp->parent->data << ")" << " ";
    }
    else
    {
        cout << temp->data << "(null) " << endl;
    }
    inOrder(temp->right);
}

void preOrder(node *&root)
{
    node *temp = root;
    if (temp == nullptr)
    {
        return;
    }
    if (temp->parent != nullptr)
    {
        cout << temp->data << "(" << temp->parent->data << ")" << " ";
    }
    else
    {
        cout << temp->data << "(null) " << endl;
    }
    preOrder(temp->left);
    preOrder(temp->right);
}

void postOrder(node *&root)
{
    node *temp = root;
    if (temp == nullptr)
    {
        return;
    }
    postOrder(temp->left);
    postOrder(temp->right);
    if (temp->parent != nullptr)
    {
        cout << temp->data << "(" << temp->parent->data << ")" << " ";
    }
    else
    {
        cout << temp->data << "(null) ";
    }
}

void levelOrder(node *&root)
{
    queue<node *> level;
    node *temp = root;
    level.push(temp);
    int Level = 1;
    while (!level.empty())
    {
        cout << "Level " << Level << ": ";
        int levelSize = level.size();
        while (levelSize > 0)
        {
            node *curr = level.front();
            level.pop();
            if (curr->parent != nullptr)
            {
                cout << curr->data << "(" << curr->parent->data << ")" << " ";
            }
            else
            {
                cout << curr->data << "(null) ";
            }
            if (curr->left != nullptr)
            {
                level.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                level.push(curr->right);
            }
            levelSize--;
        }
        Level++;
        cout << endl;
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
    while (true)
    {
        int op;
        cin >> op;
        switch (op)
        {
        case 1:
            inOrder(root);
            break;
        case 2:
            preOrder(root);
            break;
        case 3:
            postOrder(root);
            break;
        case 4:
            levelOrder(root);
            break;
        default:
            return 0;
        }
    }
}
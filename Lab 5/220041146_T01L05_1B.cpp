#include <iostream>
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

void printTree(node *&root)
{
    node *temp = root;
    if (temp == nullptr)
    {
        return;
    }
    printTree(temp->left);
    cout << temp->data << " ";
    printTree(temp->right);
}

node *Search(node *&root, int val)
{
    node *temp = root;
    if (temp->data == val)
    {
        return temp;
    }
    while (temp != nullptr && temp->data != val)
    {
        if (val < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (temp == nullptr)
    {
        cout << "Not found" << endl;
    }
    else if (temp->left == nullptr && temp->right != nullptr)
    {
        cout << "Present" << endl;
        cout << "Parent(" << temp->parent->data << "), Left(null), Right(" << temp->right->data << ")" << endl;
    }
    else if (temp->left != nullptr && temp->right == nullptr)
    {
        cout << "Present" << endl;
        cout << "Parent(" << temp->parent->data << "), Left(" << temp->left->data << "), Right(null)" << endl;
    }
    else if (temp->left == nullptr && temp->right == nullptr)
    {
        cout << "Present" << endl;
        cout << "Parent(" << temp->parent->data << "), Left(null), Right(null)" << endl;
    }
    return temp;
}

node *tree_maximum(node *&root)
{
    node *temp = root;
    while (temp->right != nullptr)
    {
        temp = temp->right;
    }
    return temp;
}

node *tree_minimum(node *&root)
{
    node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}

void Height(node *&root, int val)
{
    node *temp = Search(root, val);
    cout << temp->height << endl;
}

void before_after(node *&root, int val)
{
    node *temp = Search(root, val);
    node *after;
    node *pa;
    node *before;
    node *pb;
    if (temp == tree_maximum(root))
    {
        after = nullptr;
    }
    else if (temp->right != nullptr)
    {
        after = tree_minimum(temp->right);
    }
    else
    {
        pa = temp->parent;
        while (pa->data < temp->data)
        {
            pa = pa->parent;
        }
        after = pa;
    }
    if (temp == tree_minimum(root))
    {
        before = nullptr;
    }
    else if (temp->left != nullptr)
    {
        before = tree_maximum(temp->left);
    }
    else
    {
        pb = temp->parent;
        while (pb->data > temp->data)
        {
            pb = pb->parent;
        }
        before = pb;
    }
    if (before == nullptr && after != nullptr)
    {
        cout << "null " << after->data << endl;
    }
    else if (before != nullptr && after == nullptr)
    {
        cout << before->data << " null" << endl;
    }
    else if (before == nullptr && after == nullptr)
    {
        cout << "null null" << endl;
    }
    else
    {
        cout << before->data << " " << after->data << endl;
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
        case 2:
            printTree(root);
        case 3:
            int v;
            cin >> v;
            Search(root, v);
            break;
        case 4:
            int value;
            cin >> value;
            Height(root, value);
            break;
        case 5:
            int val;
            cin >> val;
            before_after(root, val);
            break;
        default:
            return 0;
        }
    }
}
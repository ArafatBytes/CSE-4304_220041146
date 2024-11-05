#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void printList(node *&head, node *&tail)
{
    node *odd = head;
    node *even = head->next;
    while (odd != nullptr)
    {
        cout << odd->data << " ";
        if (odd->next != nullptr)
        {
            odd = odd->next->next;
        }
        else
        {
            break;
        }
    }
    while (even != nullptr)
    {
        cout << even->data << " ";
        if (even->next != nullptr)
        {
            even = even->next->next;
        }
        else
        {
            break;
        }
    }
    cout << endl;
}

void insert_back(node *&head, node *&tail, int key)
{
    node *newNode = new node();
    newNode->data = key;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int main()
{
    node *head = nullptr;
    node *tail = nullptr;
    while (true)
    {
        int n;
        cin >> n;
        if (n == -1)
        {
            break;
        }
        else
        {
            insert_back(head, tail, n);
        }
    }
    printList(head, tail);
}
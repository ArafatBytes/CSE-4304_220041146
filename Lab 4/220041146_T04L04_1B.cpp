#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

void insert_back(node *&head, node *&tail, int key)
{
    node *newNode = new node();
    newNode->data = key;
    newNode->next = nullptr;
    if (tail != nullptr)
    {
        tail->next = newNode;
        newNode->prev = tail;
    }
    tail = newNode;
    if (head == nullptr)
    {
        head = newNode;
    }
}

void remove_end(node *&head, node *&tail)
{
    if (head == nullptr)
    {
        cout << "Underflow!" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    node *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}

void printList(node *&head, node *&tail)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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
            if (tail->prev != nullptr && tail->prev->data == tail->data)
            {
                remove_end(head, tail);
            }
        }
    }
    printList(head, tail);
}
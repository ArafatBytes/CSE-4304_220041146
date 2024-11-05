#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

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

void push_front(node *&head, node *&tail, int key, int &count)
{
    node *newNode = new node();
    newNode->data = key;
    newNode->prev = nullptr;
    if (head != nullptr)
    {
        head->prev = newNode;
        newNode->next = head;
    }
    head = newNode;
    if (tail == nullptr)
    {
        tail = newNode;
    }
    count++;
    printList(head, tail);
}

void push_back(node *&head, node *&tail, int key, int &count)
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
    count++;
    printList(head, tail);
}

int pop_front(node *&head, node *&tail, int &count)
{
    if (head == nullptr)
    {
        cout << "Underflow!" << endl;
        tail = nullptr;
        return 0;
    }
    node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    count--;
    printList(head, tail);
}

int pop_back(node *&head, node *&tail, int &count)
{
    if (head == nullptr)
    {
        cout << "Underflow!" << endl;
        return 0;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return 0;
    }
    node *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
    count--;
    printList(head, tail);
}

int Size(int count)
{
    return count;
}

int main()
{
    node *head = nullptr;
    node *tail = nullptr;
    int count = 0;
    while (true)
    {
        int a;
        cin >> a;
        if (a == 6)
        {
            return 0;
        }
        else
        {
            switch (a)
            {
            case 1:
                int b;
                cin >> b;
                push_front(head, tail, b, count);
                break;
            case 2:
                int c;
                cin >> c;
                push_back(head, tail, c, count);
                break;
            case 3:
                pop_front(head, tail, count);
                break;
            case 4:
                pop_back(head, tail, count);
                break;
            case 5:
                cout << Size(count) << endl;
                break;
            default:
                cout << "Invalid Operation!" << endl;
            }
        }
    }
}
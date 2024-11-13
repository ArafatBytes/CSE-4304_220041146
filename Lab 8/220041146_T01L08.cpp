#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;
int table[MAX_SIZE];
int tableSize, numElements = 0;
int collisionResolutionType;

int hashFunction(int x)
{
    return x % tableSize;
}

int hash2(int x)
{
    int R = 7;
    return R - (x % R);
}

double loadFactor()
{
    return static_cast<double>(numElements) / tableSize;
}

void insert(int key)
{
    int index = hashFunction(key);
    bool inserted = false;
    if (table[index] == -1)
    {
        table[index] = key;
        numElements++;
        cout << "Inserted: Index-" << index << " (L.F= " << loadFactor() << ")" << endl;
        inserted = true;
        return;
    }

    for (int i = 0; i < 6; i++)
    {
        int probeIndex;

        if (collisionResolutionType == 1)
        {
            probeIndex = (index + i) % tableSize;
        }
        else if (collisionResolutionType == 2)
        {
            probeIndex = (index + i * i) % tableSize;
        }
        else if (collisionResolutionType == 3)
        {
            probeIndex = (index + i * hash2(key)) % tableSize;
        }

        if (table[probeIndex] == -1)
        {
            table[probeIndex] = key;
            numElements++;
            cout << "Inserted: Index-" << probeIndex << " (L.F= " << loadFactor() << ")" << endl;
            inserted = true;
            break;
        }
        else
        {
            cout << "Collision: Index-" << probeIndex << endl;
        }
    }
    if (!inserted)
    {
        cout << "Input Abandoned" << endl;
    }
}

int main()
{
    int N, Q;
    cin >> collisionResolutionType >> N >> Q;
    tableSize = N;
    fill(table, table + tableSize, -1);

    for (int i = 0; i < Q; i++)
    {
        int key;
        cin >> key;
        insert(key);
    }

    return 0;
}

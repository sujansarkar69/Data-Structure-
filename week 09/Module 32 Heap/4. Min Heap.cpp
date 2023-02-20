#include <bits/stdc++.h>
using namespace std;
class MinHeap
{
public:
    vector<int> nodes;
    MinHeap()
    {
    }

    void up_heapify(int idx)
    {
        while (idx > 0 && nodes[idx] < nodes[(idx - 1) / 2])
        {
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    void Insert(int value)
    {
        nodes.push_back(value);
        up_heapify(nodes.size() - 1);
    }

    void printheap()
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i] << " ";
        }
        cout << "\n";
    }
};
int main()
{
    MinHeap mh;
    mh.Insert(2);
    mh.Insert(4);
    mh.Insert(7);
    mh.Insert(3);
    mh.Insert(10);
    mh.Insert(12);
    mh.Insert(1);
    mh.Insert(20);
    mh.Insert(6);
    mh.printheap();
}
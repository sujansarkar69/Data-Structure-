#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int> nodes;
    MaxHeap()
    {
    }

    // O(logn)
    void up_heapify(int idx)
    {
        while (idx > 0 && nodes[idx] > nodes[(idx - 1) / 2])
        {
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }
    // O(logn)
    void Insert(int value)
    {
        nodes.push_back(value);
        up_heapify(nodes.size() - 1);
    }
    // O(n)
    void printheap()
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i] << " ";
        }
        cout << "\n";
    }
    // O(logn)
    void down_heapify(int idx)
    {
        while (1)
        {
            int largest = idx;
            int l = 2 * idx + 1;
            int r = 2 * idx + 2;
            if (l < nodes.size() && nodes[largest] < nodes[l])
            {
                largest = l;
            }
            if (r < nodes.size() && nodes[largest] < nodes[r])
            {
                largest = r;
            }
            if (largest == idx)
            {
                break;
            }
            swap(nodes[idx], nodes[largest]);
            idx = largest;
        }
    }
    // O(logn)
    void Delete(int idx)
    {
        if (idx >= nodes.size())
            return;
        swap(nodes[idx], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(idx);
    }
    // O(1)
    int getMax()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty!";
            return -1;
        }
        return nodes[0];
    }
    // O(logn)
    int ExtractMax()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty!";
            return -1;
        }
        int returnnMax = nodes[0];
        Delete(0);
        return returnnMax;
    }
};
int main()
{
    MaxHeap mh;
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

    while (!mh.nodes.empty())
    {
        cout << "Max: " << mh.ExtractMax() << "\n";
    }
}
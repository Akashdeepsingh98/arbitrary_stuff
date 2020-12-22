#include <iostream>
#include <vector>
using namespace std;

void printheap(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void max_heapify(vector<int> &v, int index, int heapsize)
{
    int left = 2 * index;      //left child
    int right = 2 * index + 1; //right child
    int largest;               // store index of largest among parent, left and right child
    if (left <= heapsize && v[index] < v[left])
    {
        largest = left;
    }
    else
    {
        largest = index;
    }
    if (right <= heapsize && v[right] > v[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(v[largest], v[index]);
        max_heapify(v, largest, heapsize);
    }
}

void build_maxheap(vector<int> &v, int heapsize)
{
    for (int i = (heapsize >> 1); i >= 1; i--)
    {
        max_heapify(v, i, heapsize);
    }
}

int main()
{
    vector<int> v = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int heapsize = v.size() - 1;
    printheap(v);
    build_maxheap(v, heapsize);
    printheap(v);
}
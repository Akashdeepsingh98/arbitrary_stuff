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

void heapsort(vector<int> &v, int heapsize)
{
    build_maxheap(v, heapsize);
    for (int i = heapsize; i >= 2; i--)
    {
        swap(v[1], v[i]);
        heapsize--;
        max_heapify(v, 1, heapsize);
    }
}

int main()
{
    vector<int> v = {0, 16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int heapsize = v.size() - 1;
    printheap(v);
    heapsort(v, heapsize);
    printheap(v);
}
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

int heap_max(vector<int> &v)
{
    return v[1];
}

int extract_max(vector<int> &v, int heapsize)
{
    int result = heap_max(v);
    v[1] = v[heapsize];
    v.pop_back();
    heapsize--;
    max_heapify(v, 1, heapsize);
    return result;
}

void heap_increase_key(vector<int> &v, int target, int val)
{
    if (val < v[target])
    {
        cout << "Provided value should be greater" << endl;
        return;
    }
    v[target] = val;
    while (target > 1 && v[target / 2] < v[target])
    {
        swap(v[target], v[target / 2]);
        target = (target >> 1);
    }
}

void heap_insert(vector<int> &v, int val, int &heapsize)
{
    heapsize++;
    v.push_back(INT32_MIN);
    heap_increase_key(v, heapsize, val);
}

int main()
{
    vector<int> v = {0, 16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
    int heapsize = v.size() - 1;
    printheap(v);
    heap_insert(v, 15, heapsize);
    printheap(v);
}
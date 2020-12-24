#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v, int p, int r)
{
    int q = r;
    int left = p;
    for (int i = p; i <= q - 1; i++)
    {
        if (v[i] <= v[q])
        {
            swap(v[left], v[i]);
            left++;
        }
    }
    swap(v[q], v[left]);
    return left;
}

int select(vector<int> &v, int low, int high, int pos)
{
    if (low == high)
        return v[low];
    int q = partition(v, low, high);
    int k = q - low + 1;
    if (pos == k)
    {
        return v[q];
    }
    else if (pos < k)
    {
        return select(v, low, q - 1, pos);
    }
    else
    {
        return select(v, q + 1, high, pos - k);
    }
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    int index = select(v, 0, v.size() - 1, 10);
    cout << index << endl;
}
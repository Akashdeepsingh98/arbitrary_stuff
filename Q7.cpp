#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void printvec(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

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

void quicksort(vector<int> &v, int p, int r)
{
    if (p < r)
    {
        int q = partition(v, p, r);
        quicksort(v, p, q - 1);
        quicksort(v, q + 1, r);
    }
}

int main()
{
    vector<int> v = {10,
                     20,
                     80,
                     30,
                     60,
                     50,
                     110,
                     100,
                     130,
                     170};
    quicksort(v, 0, v.size() - 1);
    printvec(v);
}
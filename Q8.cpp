#include <iostream>
#include <vector>
using namespace std;

void printvec(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void count_equal(vector<int> &v, vector<int> &equal, int m)
{
    for (int i = 0; i < v.size(); i++)
    {
        equal[v[i]]++;
    }
}

void count_less(vector<int> &v, vector<int> &equal, vector<int> &less, int m)
{
    less[0] = 0;
    for (int i = 1; i < m; i++)
    {
        less[i] = less[i - 1] + equal[i - 1];
    }
}

void rearrange(vector<int> &v, vector<int> &less, int m, vector<int> &sorted)
{
    for (int i = 0; i < v.size(); i++)
    {
        int key = v[i];
        int index = less[key]++;
        sorted[index] = key;
    }
}

vector<int> counting_sort(vector<int> &v, int m)
{
    vector<int> equal(m, 0);
    count_equal(v, equal, m);
    vector<int> less(m, 0);
    count_less(v, equal, less, m);
    vector<int> sorted(v.size());
    rearrange(v, less, m, sorted);
    return sorted;
}

int main()
{
    vector<int> v = {4, 1, 5, 0, 1, 6, 5, 1, 5, 3};
    vector<int> sorted = counting_sort(v, 7);
    printvec(sorted);
}
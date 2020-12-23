#include <iostream>
#include <list>
#include <vector>
using namespace std;

void printvec(vector<float> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void bucket_sort(vector<float> &v)
{
    const int n = v.size();
    vector<list<float>> buckets(n);

    for (int i = 0; i < n; i++)
    {
        int bucket_no = v[i] * n;
        buckets[bucket_no].push_back(v[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        buckets[i].sort();
        for (auto it = buckets[i].begin(); it != buckets[i].end(); it++)
        {
            v[k++] = *it;
        }
    }
}

int main()
{
    vector<float> v = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    printvec(v);
    bucket_sort(v);
    printvec(v);
}
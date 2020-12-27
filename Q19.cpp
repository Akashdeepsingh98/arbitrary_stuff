#include <bits/stdc++.h>
using namespace std;

void printvec(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << '\n';
}

void binarySearch(vector<int> &v, int x)
{
    int k = 0;
    int n = v.size();
    for (int b = (n >> 1); b >= 1; b = (b >> 1))
    {
        while (k + b < n && v[k + b] <= x)
        {
            k += b;
            cout << k << '\n';
        }
    }

    if (v[k] == x)
    {
        cout << "Found at " << k << '\n';
    }
    else
    {
        cout << "Not found" << '\n';
    }
}

int main()
{
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4,9};
    sort(v.begin(), v.end());
    printvec(v);
    binarySearch(v, 100);
    printvec(v);
}
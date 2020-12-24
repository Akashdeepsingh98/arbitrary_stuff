#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printvec(string msg, vector<int> &v)
{
    cout << msg << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int median_pos(int n)
{
    if (n & 1)
    {
        return (n >> 1);
    }
    return (n >> 1) - 1;
}

int partition(vector<int> &v, int p, int r, int x)
{
    int q = r;
    int left = p;
    int xpos = (v.back() == x) ? r : 0;
    for (int i = p; i <= q - 1; i++)
    {
        if (v[i] == x)
        {
            xpos = i;
        }
        else if (v[i] < x)
        {
            swap(v[left], v[i]);
            left++;
        }
    }
    swap(v[xpos], v[left]);
    return left;
}

int give_median(vector<int> &v)
{
    return v[median_pos(v.size())];
}

int select(vector<int> &v, int low, int high, int pos)
{
    if (low >= high)
    {
        return v[low];
    }
    const int n = high - low + 1;
    vector<int> medians;
    //cout << "n:" << n << endl;
    if (n % 5 == 0)
    {
        medians.resize(n / 5);
    }
    else
    {
        medians.resize(n / 5 + 1);
    }

    int i = 0;
    for (i = 0; i < n / 5; i++)
    {
        sort(v.begin() + i * 5, v.begin() + i * 5 + 5);
        medians[i] = *(v.begin() + low + i * 5 + 2);
    }
    if (n != i * 5)
    {
        sort(v.begin() + i * 5, v.end());
        medians.back() = *(v.begin() + low + i * 5 + median_pos(high - low - i * 5));
    }
    //cout << "medians ready for" << low << " " << high << endl;
    //printvec("medians: ", medians);
    //int x = select(medians, 0, medians.size() - 1, median_pos(medians.size()));
    int x = give_median(medians);
    int q = partition(v, low, high, x);
    int k = q - low + 1;
    if (pos == k)
    {
        return x;
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
    vector<int> v = {1, 22, 3, 4, 55, 6, 7, 8, 9, 10};
    int pos;
    cin>>pos;
    int index = select(v, 0, v.size() - 1, pos);
    // cout << partition(v, 0, v.size() - 1, 9) << endl;
    cout << index << endl;
}
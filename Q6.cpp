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

void selection_sort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[minimum])
            {
                minimum = j;
            }
        }
        swap(v[i], v[minimum]);
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

    selection_sort(v);
    printvec(v);
}
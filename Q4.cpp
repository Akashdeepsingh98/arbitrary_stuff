#include <iostream>
#include <vector>
using namespace std;

void sentinel_search(vector<int> &v, int &result, int key)
{
    if (v[v.size() - 1] == key)
    {
        result = v.size() - 1;
        return;
    }
    int temp = v[v.size() - 1];
    v[v.size() - 1] = key;
    int i = 0;
    while (v[i] != key)
    {
        i++;
    }
    v[v.size() - 1] = temp;
    if (i < v.size() - 1)
    {
        result = i;
        return;
    }
    else
    {
        result = -1;
        return;
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
    int key;
    cin >> key;
    int result;
    sentinel_search(v, result, key);
    cout << result << endl;
}
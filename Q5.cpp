#include <iostream>
#include <vector>
using namespace std;

void binary_search(vector<int> &v, int &result, int key);

int main()
{
    vector<int> v = {1, 2, 3, 4, 7, 8, 10, 11, 13, 14, 15};
    int key;
    cin >> key;
    int result;
    binary_search(v, result, key);
    cout << result << endl;
}

void binary_search(vector<int> &v, int &result, int key)
{
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (v[mid] == key)
        {
            result = mid;
            return;
        }
        else if (v[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    result = -1;
}
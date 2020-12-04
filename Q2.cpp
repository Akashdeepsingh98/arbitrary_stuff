#include <bits/stdc++.h>
using namespace std;

void find_max_subarray(vector<int> &v, int low, int high, int &start, int &end, int &sum)
{
    sum = INT_MIN;
    for (int i = low; i <= high; i++)
    {
        int cursum = v[i];
        if (cursum > sum)
        {
            sum = cursum;
            start = end = i;
        }
        for (int j = i + 1; j <= high; j++)
        {
            cursum += v[j];
            if (cursum > sum)
            {
                sum = cursum;
                start = i;
                end = j;
            }
        }
    }
}

int main()
{
    vector<int> v = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int start, end, sum;
    find_max_subarray(v, 0, v.size() - 1, start, end, sum);
    cout << start << " " << end << " " << sum << endl;
}
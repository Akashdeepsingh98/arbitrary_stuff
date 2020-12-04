/*
    This is a O(nlogn) solution to finding maximum subarray in a given array instead of the naive O(n^2) solution
*/

#include <bits/stdc++.h>
using namespace std;

void find_max_cross(vector<int> &v, int low, int mid, int high, int &crossstart, int &crossend, int &crosssum)
{
    int leftsum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += v[i];
        if (sum > leftsum)
        {
            leftsum = sum;
            crossstart = i;
        }
    }

    int rightsum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += v[i];
        if (sum > rightsum)
        {
            rightsum = sum;
            crossend = i;
        }
    }
    crosssum = rightsum + leftsum;
}

void find_max_subarray(vector<int> &v, int low, int high, int &start, int &end, int &sum)
{
    if (high <= low)
    {
        start = end = low;
        sum = v[low];
        return;
    }
    else
    {
        int mid = low + ((high - low) >> 1);
        int leftsum, rightsum, crosssum, leftstart, leftend, rightstart, rightend, crossstart, crossend;
        find_max_subarray(v, low, mid, leftstart, leftend, leftsum);
        find_max_subarray(v, mid + 1, high, rightstart, rightend, rightsum);
        find_max_cross(v, low, mid, high, crossstart, crossend, crosssum);
        if (leftsum >= rightsum && leftsum >= crosssum)
        {
            start = leftstart;
            end = leftend;
            sum = leftsum;
            return;
        }
        else if (rightsum >= leftsum && rightsum >= crosssum)
        {
            start = rightstart;
            end = rightend;
            sum = rightsum;
            return;
        }
        else
        {
            start = crossstart;
            end = crossend;
            sum = crosssum;
            return;
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
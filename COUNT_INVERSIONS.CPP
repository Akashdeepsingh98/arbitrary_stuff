/*
Every pair of numbers in an array such that a[j]<a[i] when i>j is an inversion.
{2, 3, 8, 6, 1} has 5 inversions.
I modified merge sort a bit to calculate number of inversions in O(n log(n)) time as naive method takes O(n^2) time.
However the array is also sorted as a by-product. If you want, then keep a copy of array saved.
*/

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

void count_util2(vector<int> &v, int &num_inv, int low, int mid, int high)
{
    int i = low, j = mid + 1;
    vector<int> L(mid - low + 1);
    vector<int> R(high - mid);
    for (i = low; i <= mid; i++)
    {
        L[i - low] = v[i];
    }
    for (j = mid + 1; j <= high; j++)
    {
        R[j - mid - 1] = v[j];
    }
    //printvec(L);
    //printvec(R);

    i = low, j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (L[i - low] <= R[j - mid - 1])
        {
            v[k++] = L[i - low];
            i++;
        }
        else
        {
            v[k++] = R[j - mid - 1];
            j++;
            num_inv += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        v[k++] = L[i - low];
        i++;
    }

    while (j <= high)
    {
        v[k++] = R[j - mid - 1];
        j++;
    }
}

void count_util1(vector<int> &v, int &num_inv, int low, int high)
{
    if (high > low)
    {
        int mid = low + ((high - low) >> 1);
        count_util1(v, num_inv, low, mid);
        count_util1(v, num_inv, mid + 1, high);
        count_util2(v, num_inv, low, mid, high);
    }
}

int main()
{
    // give your array here in "v"
    vector<int> v = {2, 3, 8, 6, 1};
    int num_inv = 0;
    count_util1(v, num_inv, 0, v.size() - 1);
    printvec(v);
    // print number of inversions
    cout << num_inv << endl;
}
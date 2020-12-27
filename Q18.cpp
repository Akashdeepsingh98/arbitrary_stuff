#include <bits/stdc++.h>
using namespace std;

int maxsub(vector<int> &v)
{
    int global_max = INT32_MIN;
    int local_max = 0;
    int local_maxl = 0, local_maxr, global_maxl, global_maxr;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > v[i] + local_max)
        {
            local_max = v[i];
            local_maxl = local_maxr = i;
        }
        else
        {
            local_max += v[i];
            local_maxr = i;
        }
        if (local_max > global_max)
        {
            global_max = local_max;
            global_maxl = local_maxl;
            global_maxr = local_maxr;
        }
    }
    cout << global_maxl << " " << global_maxr << '\n';
    return global_max;
}

int main()
{
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxsub(v) << '\n';
}
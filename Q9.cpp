#include <iostream>
#include <vector>
using namespace std;

void count_equal(vector<string> &v, vector<int> &equal, int d)
{
    for (int i = 0; i < v.size(); i++)
    {
        char key = v[i][d];
        if (key >= 'A' && key <= 'Z')
        {
            equal[int(key - 'A')]++;
        }
        else
        {
            equal[int(key - '0' + 26)]++;
        }
    }
}

void count_less(vector<string> &v, vector<int> &less, vector<int> &equal)
{
    less[0] = 0;
    for (int i = 1; i < less.size(); i++)
    {
        less[i] = less[i - 1] + equal[i - 1];
    }
}

void rearrange(vector<string> &v, vector<int> &less, vector<string> &sorted, int d)
{
    for (int i = 0; i < v.size(); i++)
    {
        char key = v[i][d];
        if (key >= 'A' && key <= 'Z')
        {
            int index = less[int(key - 'A')]++;
            sorted[index] = v[i];
        }
        else
        {
            int index = less[int(key - '0' + 26)]++;
            sorted[index] = v[i];
        }
    }
}

void radix_sort(vector<string> &v, int m)
{
    vector<string> sorted(v.size());
    vector<int> equal(m);
    vector<int> less(m);
    for (int i = v[0].size() - 1; i >= 0; i--)
    {
        fill(equal.begin(), equal.end(), 0);
        count_equal(v, equal, i);
        fill(less.begin(), less.end(), 0);
        count_less(v, less, equal);
        rearrange(v, less, sorted, i);
        v = sorted;
    }
}

void printvec(vector<string> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    //vector<string> v = {"F6", "E5", "R6", "X6", "X2", "T5", "F2", "T3"};
    vector<string> v = {"XI7FS6", "PL4ZQ2", "JI8FR9", "XL8FQ6", "PY2ZR5", "KV7WS9", "JL2ZV3", "KI4WR2"};
    radix_sort(v, 36);
    printvec(v);
}
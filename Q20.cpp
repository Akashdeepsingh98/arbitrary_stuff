#include <bits/stdc++.h>
using namespace std;

class Board
{
public:
    int count, n;
    vector<bool> column;
    vector<bool> ul2dr;
    vector<bool> ur2dl;
    Board(int n)
    {
        this->n = n;
        this->count = 0;
        this->column.resize(n, false);
        this->ul2dr.resize((n << 1) - 1, false);
        this->ur2dl.resize((n << 1) - 1, false);
    }

    void search(int row)
    {
        if (row == n)
        {
            count++;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (column[i] || ul2dr[i - row + n - 1] || ur2dl[i + row])
            {
                continue;
            }
            column[i] = ul2dr[i - row + n - 1] = ur2dl[i + row] = true;
            search(row+1);
            column[i] = ul2dr[i - row + n - 1] = ur2dl[i + row] = false;
        }
    }
};

int main()
{
    Board b(16);
    b.search(0);
    cout << b.count << '\n';
}
#include <bits/stdc++.h>
using namespace std;

class Board
{
public:
    int n;
    vector<vector<bool>> b;
    int count;
    Board(int n)
    {
        this->n = n;
        b.resize(n, vector<bool>(n, false));
        count = 0;
    }

    bool canMoveUp(int x, int y)
    {
        if (x <= 0 || b[x - 1][y])
        {
            return false;
        }
        return true;
    }

    bool canMoveDown(int x, int y)
    {
        if (x >= n - 1 || b[x + 1][y])
        {
            return false;
        }
        return true;
    }

    bool canMoveLeft(int x, int y)
    {
        if (y <= 0 || b[x][y - 1])
        {
            return false;
        }
        return true;
    }

    bool canMoveRight(int x, int y)
    {
        if (y >= n - 1 || b[x][y + 1])
        {
            return false;
        }
        return true;
    }

    void start()
    {
        b[0][0] = true;
        int doneBlocks = 1;
        moveTo(1, 0, 'v', doneBlocks);
        count = (count << 1);
    }

    bool bothSides(int x, int y, char orient)
    {
        if (orient == 'v')
        {
            if (canMoveLeft(x, y) && canMoveRight(x, y))
            {
                return true;
            }
            return false;
        }
        if (canMoveUp(x, y) && canMoveDown(x, y))
        {
            return true;
        }
        return false;
    }

    bool canMoveForward(int x, int y, char orient)
    {
        if (orient == 'v')
        {
            if (canMoveUp(x, y) || canMoveDown(x, y))
            {
                return true;
            }
            return false;
        }

        if (canMoveLeft(x, y) || canMoveRight(x, y))
        {
            return true;
        }
        return false;
    }

    void moveTo(int x, int y, char orient, int doneBlocks)
    {
        b[x][y] = true;
        doneBlocks++;

        if (x == n - 1 && y == n - 1) // if we are at the final block
        {
            if (doneBlocks == n * n) // if all blocks done
            {
                count++;
                b[x][y] = false;
                return;
            }
            else // and if all blocks not done
            {
                b[x][y] = false;
                return;
            }
        }

        if (!canMoveForward(x, y, orient) && bothSides(x, y, orient)) // if cannot move forward but can go both sides
        {
            b[x][y] = false;
            return;
        }

        // move up, down, left, right one at a time
        if (canMoveUp(x, y))
        {
            moveTo(x - 1, y, 'v', doneBlocks);
        }
        if (canMoveDown(x, y))
        {
            moveTo(x + 1, y, 'v', doneBlocks);
        }
        if (canMoveLeft(x, y))
        {
            moveTo(x, y - 1, 'h', doneBlocks);
        }
        if (canMoveRight(x, y))
        {
            moveTo(x, y + 1, 'h', doneBlocks);
        }
        b[x][y] = false;
    }
};

int main()
{
    Board xyz(7);
    xyz.start();
    cout << xyz.count << '\n';
}
#include <bits/stdc++.h>
using namespace std;

void printmat(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> addmat(vector<vector<int>> &A, vector<vector<int>> &B, int ar1, int ar2, int ac1, int ac2)
{
    vector<vector<int>> C(ar2 - ar1 + 1, vector<int>(ac2 - ac1 + 1));
    for (int i = ar1; i <= ar2; i++)
    {
        for (int j = ac1; j <= ac2; j++)
        {
            C[i - ar1][j - ac1] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> submat(vector<vector<int>> &A, vector<vector<int>> &B, int ar1, int ar2, int ac1, int ac2)
{
    vector<vector<int>> C(ar2 - ar1 + 1, vector<int>(ac2 - ac1 + 1));
    for (int i = ar1; i <= ar2; i++)
    {
        for (int j = ac1; j <= ac2; j++)
        {
            C[i - ar1][j - ac1] = A[i][j] - B[i][j];
        }
    }
    return C;
}

vector<vector<int>> strassen(vector<vector<int>> &A, vector<vector<int>> &B, int ar1, int ar2, int ac1, int ac2, int br1, int br2, int bc1, int bc2)
{
    int arm = ar1 + ((ar2 - ar1) >> 1);
    int acm = ac1 + ((ac2 - ac1) >> 1);
    int brm = br1 + ((br2 - br1) >> 1);
    int bcm = bc1 + ((bc2 - bc1) >> 1);
    //cout << arm << endl;
    //cout << acm << endl;
    //cout << brm << endl;
    //cout << bcm << endl;

    vector<vector<int>> C(ar2 - ar1 + 1, vector<int>(bc2 - bc1 + 1));
    //printmat(C);
    if (ar1 == ar2)
    {
        C[0][0] = A[ar1][ac1] * B[br1][bc1];
        return C;
    }

    vector<vector<int>> temp1 = strassen(A, B, ar1, arm, ac1, acm, br1, brm, bcm + 1, bc2);
    vector<vector<int>> temp2 = strassen(A, B, ar1, arm, ac1, acm, brm + 1, br2, bcm + 1, bc2);
    vector<vector<int>> P1 = submat(temp1, temp2, 0, temp1.size() - 1, 0, temp1[0].size() - 1);
    //printmat(P1);

    temp1 = strassen(A, B, ar1, arm, ac1, acm, brm + 1, br2, bcm + 1, bc2);
    temp2 = strassen(A, B, ar1, arm, acm + 1, ac2, brm + 1, br2, bcm + 1, bc2);
    vector<vector<int>> P2 = addmat(temp1, temp2, 0, temp1.size() - 1, 0, temp1[0].size() - 1);

    temp1 = strassen(A, B, arm + 1, ar2, ac1, acm, br1, brm, bc1, bcm);
    temp2 = strassen(A, B, arm + 1, ar2, acm + 1, ac2, br1, brm, bc1, bcm);
    vector<vector<int>> P3 = addmat(temp1, temp2, 0, temp1.size() - 1, 0, temp1[0].size() - 1);

    temp1 = strassen(A, B, arm + 1, ar2, acm + 1, ac2, brm + 1, br2, bc1, bcm);
    temp2 = strassen(A, B, arm + 1, ar2, acm + 1, ac2, br1, brm, bc1, bcm);
    vector<vector<int>> P4 = submat(temp1, temp2, 0, temp1.size() - 1, 0, temp1[0].size() - 1);

    vector<vector<int>> temp3, temp4;
    temp1 = strassen(A, B, ar1, arm, ac1, acm, br1, brm, bc1, bcm);
    temp2 = strassen(A, B, ar1, arm, ac1, acm, brm + 1, br2, bcm + 1, bc2);
    temp3 = strassen(A, B, arm + 1, ar2, acm + 1, ac2, br1, brm, bc1, bcm);
    temp4 = strassen(A, B, arm + 1, ar2, acm + 1, ac2, brm + 1, br2, bcm + 1, bc2);
    vector<vector<int>> P5 = addmat(temp1, temp2, 0, temp1.size() - 1, 0, temp1[0].size() - 1);
    P5 = addmat(P5, temp3, 0, P5.size() - 1, 0, P5[0].size() - 1);
    P5 = addmat(P5, temp4, 0, P5.size() - 1, 0, P5[0].size() - 1);

    temp1 = strassen(A, B, ar1, arm, acm + 1, ac2, brm + 1, br2, bc1, bcm);
    temp2 = strassen(A, B, ar1, arm, acm + 1, ac2, brm + 1, br2, bcm + 1, bc2);
    temp3 = strassen(A, B, arm + 1, ar2, acm + 1, ac2, brm + 1, br2, bc1, bcm);
    temp4 = strassen(A, B, arm + 1, ar2, acm + 1, ac2, brm + 1, br2, bcm + 1, bc2);
    vector<vector<int>> P6 = addmat(temp1, temp2, 0, temp1.size() - 1, 0, temp1[0].size() - 1);
    P6 = submat(P6, temp3, 0, P6.size() - 1, 0, P6[0].size() - 1);
    P6 = submat(P6, temp4, 0, P6.size() - 1, 0, P6[0].size() - 1);

    temp1 = strassen(A, B, ar1, arm, ac1, acm, br1, brm, bc1, bcm);
    temp2 = strassen(A, B, ar1, arm, ac1, acm, br1, brm, bcm + 1, bc2);
    temp3 = strassen(A, B, arm + 1, ar2, ac1, acm, br1, brm, bc1, bcm);
    temp4 = strassen(A, B, arm + 1, ar2, ac1, acm, br1, brm, bcm + 1, bc2);
    vector<vector<int>> P7 = addmat(temp1, temp2, 0, temp1.size() - 1, 0, temp1[0].size() - 1);
    P7 = submat(P7, temp3, 0, P7.size() - 1, 0, P7[0].size() - 1);
    P7 = submat(P7, temp4, 0, P7.size() - 1, 0, P7[0].size() - 1);

    temp1 = addmat(P5, P4, 0, P5.size() - 1, 0, P5[0].size() - 1);
    temp1 = submat(temp1, P2, 0, temp1.size() - 1, 0, temp1[0].size() - 1);
    temp1 = addmat(temp1, P6, 0, temp1.size() - 1, 0, temp1[0].size() - 1);
    //printmat(temp1);

    temp2 = addmat(P1, P2, 0, P1.size() - 1, 0, P1[0].size() - 1);
    //printmat(temp2);

    temp3 = addmat(P3, P4, 0, P3.size() - 1, 0, P3[0].size() - 1);
    //printmat(temp3);

    temp4 = addmat(P5, P1, 0, P5.size() - 1, 0, P5[0].size() - 1);
    temp4 = submat(temp4, P3, 0, temp4.size() - 1, 0, temp4[0].size() - 1);
    temp4 = submat(temp4, P7, 0, temp4.size() - 1, 0, temp4[0].size() - 1);
    //printmat(temp4);

    for (int i = ar1; i <= arm; i++)
    {
        for (int j = ac1; j <= acm; j++)
        {
            C[i - ar1][j - ac1] = temp1[i - ar1][j - ac1];
        }
    }

    for (int i = ar1; i <= arm; i++)
    {
        for (int j = acm + 1; j <= ac2; j++)
        {
            C[i - ar1][j - ac1] = temp2[i - ar1][j - acm - 1];
        }
    }

    for (int i = arm + 1; i <= ar2; i++)
    {
        for (int j = ac1; j <= acm; j++)
        {
            C[i - ar1][j - ac1] = temp3[i - arm - 1][j - ac1];
        }
    }

    for (int i = arm + 1; i <= ar2; i++)
    {
        for (int j = acm + 1; j <= ac2; j++)
        {
            C[i - ar1][j - ac1] = temp4[i - arm - 1][j - acm - 1];
        }
    }

    return C;
}

int main()
{
    vector<vector<int>> A(4, vector<int>(4));
    vector<vector<int>> B(4, vector<int>(4));
    //A[0][0] = 1;
    //A[0][1] = 3;
    //A[1][0] = 7;
    //A[1][1] = 5;
    //B[0][0] = 6;
    //B[0][1] = 8;
    //B[1][0] = 4;
    //B[1][1] = 2;

    A[0] = {1, 2, 3, 4};
    A[1] = {5, 6, 7, 8};
    A[2] = {1, 2, 3, 4};
    A[3] = {5, 6, 7, 8};
    B[0] = {1, 2, 3, 4};
    B[1] = {5, 6, 7, 8};
    B[2] = {1, 2, 3, 4};
    B[3] = {5, 6, 7, 8};

    vector<vector<int>> C = strassen(A, B, 0, A.size() - 1, 0, A[0].size() - 1, 0, B.size() - 1, 0, B[0].size() - 1);
    printmat(C);
}
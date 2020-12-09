#include <iostream>
#include <vector>
#include <list>
using namespace std;

void printadj(vector<vector<int>> &adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        cout << i << " ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void printlist(list<int> l)
{
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void printvec(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void topo_sort(vector<vector<int>> &adj, vector<int> &linear_order)
{
    vector<int> indegree(adj.size(), 0);
    for (int i = 1; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            indegree[adj[i][j]]++;
        }
    }
    list<int> next;
    for (int i = 1; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            next.push_back(i);
        }
    }

    while (!next.empty())
    {
        int u = next.front();
        next.pop_front();
        linear_order.push_back(u);
        for (int i = 0; i < adj[u].size(); i++)
        {
            indegree[adj[u][i]]--;
            if (indegree[adj[u][i]] == 0)
            {
                next.push_back(adj[u][i]);
            }
        }
    }
}

int main()
{
    vector<vector<int>> adj = {{}, {3}, {4}, {4, 5}, {6}, {6}, {7, 11}, {8}, {13}, {10}, {11}, {12}, {13}, {14}, {}};
    vector<int> linear_order;
    topo_sort(adj, linear_order);
    printvec(linear_order);
}
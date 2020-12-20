/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
private:
public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
        this->data = 0;
        this->left = this->right = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

void diameterUtil(Node *root, int &height, int &diameter)
{
    int lh, rh, ldia, rdia;
    if (root == nullptr)
    {
        height = 0;
        diameter = 0;
        return;
    }

    diameterUtil(root->left, lh, ldia);
    diameterUtil(root->right, rh, rdia);

    height = max(lh, rh) + 1;
    diameter = max(lh + rh + 1, max(ldia, rdia));
}

int main()
{
    int T;
    cin >> T;
    Node *root = new Node();
    {
        int r;
        cin >> r;
        root->data = r;
    }
    for (int i = 0; i < T - 1; i++)
    {
        string path;
        cin >> path;
        Node *newnode = new Node();
        cin >> newnode->data;
        Node *ptr = root;
        for (int j = 0; j < path.size() - 1; j++)
        {
            if (path[j] == 'L')
            {
                if (ptr->left == nullptr)
                    ptr->left = new Node();
                ptr = ptr->left;
            }
            else
            {
                if (ptr->right == nullptr)
                    ptr->right = new Node();
                ptr = ptr->right;
            }
        }
        if (path[path.size() - 1] == 'L')
        {
            if (ptr->left == nullptr)
                ptr->left = newnode;
            else
            {
                ptr->left->data = newnode->data;
            }
        }
        else
        {
            if (ptr->right == nullptr)
            {
                ptr->right = newnode;
            }
            else
            {
                ptr->right->data = newnode->data;
            }
        }
    }

    int height, diameter;
    diameterUtil(root, height, diameter);
    cout << diameter << endl;
}
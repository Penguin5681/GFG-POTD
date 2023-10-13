// Day 5: 13/10/23 13:10
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

class Solution
{

public:
    int floor(Node *root, int x)
    {
        if (root == nullptr)
        {
            return -1;
        }

        if (root->data == x)
        {
            return x;
        }
        else if (root->data > x)
        {
            return floor(root->left, x);
        }
        else
        {
            int rightFloor = floor(root->right, x);
            return (rightFloor != -1 && rightFloor <= x) ? rightFloor : root->data;
        }
    }
};

Node *insert(Node *tree, int val)
{
    Node *temp = NULL;
    if (tree == NULL)
        return new Node(val);

    if (val < tree->data)
    {
        tree->left = insert(tree->left, val);
    }
    else if (val > tree->data)
    {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// Day 6: 14/10/23 01:27
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{

    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N")
        {

            currNode->left = new Node(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {

            currNode->right = new Node(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
private:
    void fn(Node* root, vector<int> &vec) {
        if (!root)
            return;
        fn(root->left, vec);
        vec.push_back(root->data);
        fn(root->right, vec);
    }
public:
    vector<int> findCommon(Node *root1, Node *root2)
    {
        vector<int> root1_vec;
        vector<int> root2_vec;

        fn(root1, root1_vec);
        fn(root2, root2_vec);

        vector<int> rsl;
        int i = 0, j = 0;
        
        while (i < root1_vec.size() and j < root2_vec.size()) {
            if (root1_vec[i] == root2_vec[j]) {
                rsl.push_back(root1_vec[i]);
                i++; j++;
            }
            else if (root1_vec[i] < root2_vec[j])
                i++;
            else 
                j++;
        }

        return rsl;
    }
};

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        Node *root2 = buildTree(s);
        Solution ob;
        vector<int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }

    return 1;
}

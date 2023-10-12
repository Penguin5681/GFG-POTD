// Day 4: 12/10/23 20:43
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;

    Node(char x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct Node *buildTree(string str)
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
public:
    string traverse(Node* root, unordered_map<string, int> &m) {
        if (root == NULL)
            return "";
        string trs = traverse(root->left, m) + to_string(root->data) + traverse(root->right, m);
        m[trs]++;
        return trs;
    }

    int dupSub(Node *root) {
        unordered_map<string, int> mp;
        traverse(root, mp);
        for (auto it : mp)
            if (it.first.length() > 2 and it.second > 1)
                return 1;
        return 0;
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string treeString;
        getline(cin >> ws, treeString);
        struct Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.dupSub(root) << "\n";
    }
    return 0;
}

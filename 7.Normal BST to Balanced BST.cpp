
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void inorderTraversal(Node *root, vector<Node *> &nodes)
    {
        if (root == nullptr)
            return;
        inorderTraversal(root->left, nodes);
        nodes.push_back(root);
        inorderTraversal(root->right, nodes);
    }

    Node *constructBalancedBST(vector<Node *> &nodes, int start, int end)
    {
        if (start > end)
            return nullptr;
        int mid = (start + end) / 2;
        Node *newNode = nodes[mid];

        newNode->left = constructBalancedBST(nodes, start, mid - 1);
        newNode->right = constructBalancedBST(nodes, mid + 1, end);

        return newNode;
    }

    Node *buildBalancedTree(Node *root)
    {

        vector<Node *> nodes;
        inorderTraversal(root, nodes);

        int n = nodes.size();
        return constructBalancedBST(nodes, 0, n - 1);
    }
};

Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

void preOrder(Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    int lDepth = height(node->left);
    int rDepth = height(node->right);
    if (lDepth > rDepth)
        return (lDepth + 1);
    else
        return (rDepth + 1);
}
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

Node *buildBalancedTree(Node *root);

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        struct Node *root = NULL;
        int n, temp;
        string tree;
        getline(cin, tree);
        root = buildTree(tree);

        Solution obj;
        root = obj.buildBalancedTree(root);
        cout << height(root) << endl;
    }
    return 0;
}

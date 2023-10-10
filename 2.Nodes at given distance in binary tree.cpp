// Day 2: 10/10/23 22:16

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *buildTree(string str)
{

    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = newNode(stoi(ip[0]));

    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < ip.size())
    {

        Node *currNode = q.front();
        q.pop();

        string currVal = ip[i];

        if (currVal != "N")
        {

            currNode->left = newNode(stoi(currVal));

            q.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {

            currNode->right = newNode(stoi(currVal));

            q.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    void dfs(Node *node, Node *par, unordered_map<Node *, Node *> &parent)
    {
        if (node == NULL)
            return;
        parent[node] = par;
        dfs(node->left, node, parent);
        dfs(node->right, node, parent);
    }

    void dfs(Node *node, int k, unordered_map<Node *, bool> &visited, unordered_map<Node *, Node *> &parent, vector<int> &result)
    {
        if (node == NULL || visited[node])
            return;

        visited[node] = true;

        if (k == 0)
        {
            result.push_back(node->data);
            return;
        }

        dfs(node->left, k - 1, visited, parent, result);
        dfs(node->right, k - 1, visited, parent, result);
        dfs(parent[node], k - 1, visited, parent, result);
    }

    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        unordered_map<Node *, Node *> parent;
        unordered_map<Node *, bool> visited;
        vector<int> result;

        dfs(root, NULL, parent);

        Node* targetNode = NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* currNode = q.front();
            q.pop();
            if(currNode->data == target){
                targetNode = currNode;
                break;
            }
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }

        if(targetNode == NULL) return result;

        dfs(targetNode, k, visited, parent, result);

        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
    int t;
    cin >> t;
    getchar();

    Solution x = Solution();

    while (t--)
    {
        string s;
        getline(cin, s);
        Node *head = buildTree(s);

        int target, k;
        cin >> target >> k;
        getchar();

        vector<int> res = x.KDistanceNodes(head, target, k);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

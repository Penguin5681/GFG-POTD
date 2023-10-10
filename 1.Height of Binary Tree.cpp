// Day 1: 09/10/23 16:05

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int height(struct Node* node) {
    if (node == NULL) return 0;
    return max(height(node->left), height(node->right)) + 1;
}

signed main() {

}
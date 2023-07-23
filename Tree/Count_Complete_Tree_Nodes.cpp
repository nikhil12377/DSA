// https://leetcode.com/problems/count-complete-tree-nodes/description

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int _val)
    {
        val = _val;
        left = right = NULL;
    }
};

int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int totalNodes = 0;
    queue<TreeNode *> qt;
    qt.push(root);
    while (!qt.empty())
    {
        totalNodes++;
        TreeNode *node = qt.front();
        qt.pop();

        if (node->left)
            qt.push(node->left);
        if (node->right)
            qt.push(node->right);
    }

    return totalNodes;
}
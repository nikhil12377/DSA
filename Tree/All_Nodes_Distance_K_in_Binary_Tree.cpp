// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

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

void findParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentOf)
{
    if (root == NULL)
        return;

    if (root->left)
    {
        parentOf[root->left] = root;
        findParent(root->left, parentOf);
    }
    if (root->right)
    {
        parentOf[root->right] = root;
        findParent(root->right, parentOf);
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parentOf;
    unordered_map<TreeNode *, bool> Visited;
    findParent(root, parentOf);
    queue<TreeNode *> qt;
    qt.push(target);
    int level = 0;
    while (!qt.empty() && level < k)
    {
        if (level == k)
            break;
        int size = qt.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = qt.front();
            Visited[node] = true;
            qt.pop();
            if (parentOf[node] && !Visited[parentOf[node]])
            {
                qt.push(parentOf[node]);
            }
            if (node->left && !Visited[node->left])
            {
                qt.push(node->left);
            }
            if (node->right && !Visited[node->right])
            {
                qt.push(node->right);
            }
        }
        level++;
    }

    vector<int> ans;
    while (!qt.empty())
    {
        ans.push_back(qt.front()->val);
        qt.pop();
    }

    return ans;
}
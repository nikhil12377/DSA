// https://leetcode.com/problems/two-sum-iv-input-is-a-bst
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

void inorderTraversal(TreeNode *root, vector<int> &inorder)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}

bool findTarget(TreeNode *root, int k)
{
    if (!root->left && !root->right)
        return false;

    vector<int> inorder;
    inorderTraversal(root, inorder);
    int i = 0, j = inorder.size() - 1;
    while (i < j)
    {
        int sum = inorder[i] + inorder[j];
        if (sum == k)
            return true;
        if (sum < k)
            i++;
        else
            j--;
    }

    return false;
}
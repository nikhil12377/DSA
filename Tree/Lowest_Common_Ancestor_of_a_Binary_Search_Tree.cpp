// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
        return root;
    TreeNode *lt = lowestCommonAncestor(root->left, p, q);
    TreeNode *rt = lowestCommonAncestor(root->right, p, q);

    if (lt == NULL)
        return rt;
    else if (rt == NULL)
        return lt;
    else
        return root;
}
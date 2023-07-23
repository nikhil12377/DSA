// https://leetcode.com/problems/search-in-a-binary-search-tree
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

TreeNode *searchBST(TreeNode *root, int val)
{
    while (root != NULL)
    {
        if (root->val == val)
            return root;
        if (root->val > val)
            root = root->left;
        else
            root = root->right;
    }

    return NULL;
}
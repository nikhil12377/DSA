// https://leetcode.com/problems/validate-binary-search-tree
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

bool checkBST(TreeNode *root, long minno, long maxno)
{
    if (root == NULL)
        return true;
    if (root->val <= minno || root->val >= maxno)
        return false;

    return checkBST(root->left, minno, root->val) && checkBST(root->right, root->val, maxno);
}

bool isValidBST(TreeNode *root)
{
    return checkBST(root, LONG_MIN, LONG_MAX);
}
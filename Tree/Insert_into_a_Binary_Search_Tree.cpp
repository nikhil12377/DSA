// https://leetcode.com/problems/insert-into-a-binary-search-tree
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

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    TreeNode *node = new TreeNode(val);
    if (root == NULL)
        return node;
    TreeNode *temp = root;

    while (temp != NULL)
    {
        if (temp->val > val)
        {
            if (temp->left != NULL)
                temp = temp->left;
            else
                break;
        }
        else
        {
            if (temp->right != NULL)
                temp = temp->right;
            else
                break;
        }
    }

    if (temp->val > val)
        temp->left = node;
    else
        temp->right = node;

    return root;
}
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal
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

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int n = preorder.size();
    TreeNode *root = new TreeNode(preorder[0]);
    if (n == 1)
        return root;

    int i = 1;
    while (i < n)
    {
        int val = preorder[i];
        TreeNode *node = new TreeNode(val);
        TreeNode *temp = root;
        while (true)
        {
            if (temp->val > val)
            {
                if (temp->left != NULL)
                    temp = temp->left;
                else
                {
                    temp->left = node;
                    break;
                }
            }
            else
            {
                if (temp->right != NULL)
                    temp = temp->right;
                else
                {
                    temp->right = node;
                    break;
                }
            }
        }
        i++;
    }

    return root;
}
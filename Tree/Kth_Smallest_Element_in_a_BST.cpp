// https://leetcode.com/problems/kth-smallest-element-in-a-bst
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

int ans = INT_MIN;
void findkth(TreeNode *root, int &k)
{
    if (!root)
        return;
    findkth(root->left, k);
    k--;
    if (k == 0)
    {
        ans = root->val;
        return;
    }
    findkth(root->right, k);
}

int kthSmallest(TreeNode *root, int k)
{
    if (!root)
        return 0;

    findkth(root, k);
    return ans;
}
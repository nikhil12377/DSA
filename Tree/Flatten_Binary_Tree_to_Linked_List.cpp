// https://leetcode.com/problems/flatten-binary-tree-to-linked-list
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

void flatten(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *temp = new TreeNode(0);
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        temp->right = node;
        temp->left = NULL;
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
        temp = temp->right;
    }
}
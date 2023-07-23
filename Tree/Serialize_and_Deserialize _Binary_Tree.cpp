// https://leetcode.com/problems/serialize-and-deserialize-binary-tree
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

string serialize(TreeNode *root)
{
    if (!root)
        return "";
    string ans = "";
    queue<TreeNode *> qt;
    qt.push(root);
    while (!qt.empty())
    {
        TreeNode *node = qt.front();
        qt.pop();

        if (node == NULL)
            ans.append("N,");
        else
            ans.append(to_string(node->val) + ',');
        if (node != NULL)
        {
            qt.push(node->left);
            qt.push(node->right);
        }
    }

    return ans;
}

TreeNode *deserialize(string data)
{
    if (data == "")
        return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    int n = data.size();
    queue<TreeNode *> qt;
    qt.push(root);
    while (!qt.empty())
    {
        TreeNode *node = qt.front();
        qt.pop();

        getline(s, str, ',');
        if (str == "N")
            node->left = NULL;
        else
        {
            node->left = new TreeNode(stoi(str));
            qt.push(node->left);
        }

        getline(s, str, ',');
        if (str == "N")
            node->right = NULL;
        else
        {
            node->right = new TreeNode(stoi(str));
            qt.push(node->right);
        }
    }

    return root;
}
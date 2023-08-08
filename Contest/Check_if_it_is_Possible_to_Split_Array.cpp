// https://leetcode.com/problems/check-if-it-is-possible-to-split-array/
#include <bits/stdc++.h>
using namespace std;

bool canSplitArray(vector<int> &nums, int m)
{
    int n = nums.size();
    if (n == 1 || n == 2)
        return true;
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] + nums[i + 1] >= m)
            return true;
    }

    return false;
}
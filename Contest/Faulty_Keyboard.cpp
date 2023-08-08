// https://leetcode.com/problems/faulty-keyboard
#include <bits/stdc++.h>
using namespace std;

string finalString(string s)
{
    string ans = "";
    for (char &c : s)
    {
        if (c == 'i')
            reverse(ans.begin(), ans.end());
        else
            ans.push_back(c);
    }

    return ans;
}
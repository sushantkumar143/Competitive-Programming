#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    void fun(TreeNode* root, int sm, int tar, vector<int>& temp, vector<vector<int>>& ans) {
        if (!root) return;

        sm += root->val;
        temp.push_back(root->val);

        if (!root->left && !root->right) {
            if (sm == tar)
                ans.push_back(temp);
        } 
        else {
            fun(root->left, sm, tar, temp, ans);
            fun(root->right, sm, tar, temp, ans);
        }

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(root, 0, targetSum, temp, ans);
        return ans;
    }
};

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt = 0;

    void fun(TreeNode* root, int t) {
        if(!root) return;

        if(root->val == t) cnt++;
        if((long long)t-root->val < INT_MIN) return;
        t -= root->val;
        fun(root->left, t);
        fun(root->right, t);
    }

    void preOrder(TreeNode* root, int targetSum) {
        if(!root) return;

        fun(root, targetSum);
        preOrder(root->left, targetSum);
        preOrder(root->right, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        preOrder(root, targetSum);
        return cnt;
    }
};
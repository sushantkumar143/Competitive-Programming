#include<bits/stdc++.h>
using namespace std;class Solution {

public:
    vector<int> sizes;

    int fun(TreeNode* root) {
        if (!root) return 0;

        int left = fun(root->left);
        int right = fun(root->right);

        if (left == -1 || right == -1 || left != right) return -1;

        int size = left + right + 1;
        sizes.push_back(size);

        return size;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        fun(root);

        if (sizes.size() < k) return -1;

        sort(sizes.begin(), sizes.end(), greater<int>());
        return sizes[k - 1];
    }
};
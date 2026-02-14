#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        queue<TreeNode*> q;
        q.push(root);

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;

            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            pq.push(sum);
            if (pq.size() > k) pq.pop();
        }

        return pq.size() < k ? -1 : pq.top();
    }
};
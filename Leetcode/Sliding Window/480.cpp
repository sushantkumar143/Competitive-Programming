class Solution {
public:
    priority_queue<int> maxHeap; // smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // larger half
    unordered_map<int,int> delayed;
    
    void pruneMax() {
        while (!maxHeap.empty() && delayed[maxHeap.top()] > 0) {
            delayed[maxHeap.top()]--;
            maxHeap.pop();
        }
    }

    void pruneMin() {
        while (!minHeap.empty() && delayed[minHeap.top()] > 0) {
            delayed[minHeap.top()]--;
            minHeap.pop();
        }
    }

    void balance() {
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            pruneMin();
        }
        else if (maxHeap.size() > minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            pruneMax();
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {

            // INSERT (same logic as yours)
            if (minHeap.empty() || nums[i] >= minHeap.top())
                minHeap.push(nums[i]);
            else
                maxHeap.push(nums[i]);

            balance();

            // REMOVE outgoing element
            if (i >= k) {
                int out = nums[i - k];
                delayed[out]++;

                if (!minHeap.empty() && out >= minHeap.top())
                    pruneMin();
                else
                    pruneMax();

                balance();
            }

            // GET MEDIAN
            if (i >= k - 1) {
                if (k % 2 == 0)
                    ans.push_back(((double)minHeap.top() + maxHeap.top()) / 2.0);
                else
                    ans.push_back(minHeap.top());
            }
        }

        return ans;
    }
};

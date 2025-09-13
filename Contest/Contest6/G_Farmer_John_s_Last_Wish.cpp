#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

const int MAX_A = 200005;
std::vector<int> divisors[MAX_A];
int counts[MAX_A];
int sz[MAX_A];
int dp_len[MAX_A];
int dp_ans[MAX_A];

// Precompute all divisors up to MAX_A to be efficient.
void precompute_divisors() {
    for (int i = 1; i < MAX_A; ++i) {
        for (int j = i; j < MAX_A; j += i) {
            divisors[j].push_back(i);
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    // Keep track of which array indices to clean up for the next test case.
    std::vector<int> touched_divisors; 
    touched_divisors.reserve(2000); 

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int overall_max_ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        
        // Update counts for all divisors of the new element.
        for (int d : divisors[x]) {
            if (counts[d] == 0) touched_divisors.push_back(d);
            counts[d]++;
        }

        std::vector<int>& divs_x = divisors[x];
        
        // Recompute sz for affected divisors, from largest to smallest.
        for (int j = divs_x.size() - 1; j >= 0; --j) {
            int d = divs_x[j];
            sz[d] = counts[d];
            for (int k = 2 * d; k < MAX_A; k += d) {
                if (counts[k] > 0) { 
                    sz[d] -= sz[k];
                }
            }
        }
        
        // Recompute dp for affected divisors, from largest to smallest.
        for (int j = divs_x.size() - 1; j >= 0; --j) {
            int d = divs_x[j];
            dp_len[d] = sz[d];
            dp_ans[d] = 0;

            int max_sub_len = 0;
            int max_sub_ans = 0;

            for (int k = 2 * d; k < MAX_A; k += d) {
                if (counts[k] > 0) {
                    if (dp_len[k] > max_sub_len) {
                        max_sub_len = dp_len[k];
                        max_sub_ans = dp_ans[k];
                    } else if (dp_len[k] == max_sub_len) {
                        max_sub_ans = std::max(max_sub_ans, dp_ans[k]);
                    }
                }
            }

            if (max_sub_len > 0) {
                dp_len[d] += max_sub_len;
                dp_ans[d] = sz[d] + max_sub_ans;
            }
            overall_max_ans = std::max(overall_max_ans, dp_ans[d]);
        }
        
        std::cout << overall_max_ans << (i == n - 1 ? "" : " ");
    }
    std::cout << '\n';

    // Cleanup for the next test case by resetting only the touched indices.
    for(int d : touched_divisors) {
        counts[d] = 0;
        sz[d] = 0;
        dp_len[d] = 0;
        dp_ans[d] = 0;
    }
}

int main() {
    // This precomputation is done only once.
    precompute_divisors();
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
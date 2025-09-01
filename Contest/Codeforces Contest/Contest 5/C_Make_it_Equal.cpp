#include <iostream>
#include <vector>
#include <map>
#include <cmath>

bool solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> s(n);
    std::vector<long long> t(n);
    std::map<long long, int> s_count;
    std::map<long long, int> t_count;

    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        s_count[s[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
        t_count[t[i]]++;
    }

    if (s_count.size() != t_count.size()) {
        return false;
    }

    while (!s_count.empty()) {
        long long current_s = s_count.begin()->first;
        if (t_count.find(current_s) != t_count.end() && s_count[current_s] == t_count[current_s]) {
            s_count.erase(current_s);
            t_count.erase(current_s);
        } else {
            long long target_s = -1;
            if (t_count.find(current_s + k) != t_count.end()) {
                target_s = current_s + k;
            } else if (t_count.find(std::abs(current_s - k)) != t_count.end()) {
                target_s = std::abs(current_s - k);
            }
            
            if (target_s != -1 && s_count[current_s] <= t_count[target_s] && current_s <= target_s) {
                int count = s_count[current_s];
                t_count[target_s] -= count;
                if (t_count[target_s] == 0) {
                    t_count.erase(target_s);
                }
                s_count.erase(current_s);
            } else {
                return false;
            }
        }
    }

    return t_count.empty();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        if (solve()) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
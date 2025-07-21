#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

const int ALPHABET_SIZE = 26;

bool findAlphabetOrder(const vector<string>& names, string& order) {
    vector<set<int>> adj(ALPHABET_SIZE);
    vector<int> indegree(ALPHABET_SIZE, 0);

    // Build graph from adjacent name comparisons
    for (int i = 0; i + 1 < names.size(); ++i) {
        const string& w1 = names[i];
        const string& w2 = names[i + 1];
        int len = min(w1.size(), w2.size());
        bool found = false;

        for (int j = 0; j < len; ++j) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';
                if (!adj[u].count(v)) {
                    adj[u].insert(v);
                    indegree[v]++;
                }
                found = true;
                break;
            }
        }

        if (!found && w1.size() > w2.size()) {
            return false; // Invalid case: prefix conflict
        }
    }

    // Topological sort
    queue<int> q;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
        if (indegree[i] == 0)
            q.push(i);

    string result;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        result += (char)(u + 'a');
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    if (result.size() != ALPHABET_SIZE)
        return false;

    order = result;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; ++i)
        cin >> names[i];

    string alphabetOrder;
    if (findAlphabetOrder(names, alphabetOrder)) {
        cout << alphabetOrder << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
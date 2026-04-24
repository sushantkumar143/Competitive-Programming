#include<bits/stdc++.h>
using namespace std;

class TreeLock {
    int n, m;
    vector<int> lb; 
    vector<int> ldc;

public:
    TreeLock(int n, int m) : n(n), m(m) {
        lb.assign(n, 0);
        ldc.assign(n, 0);
    }

    vector<int> getPath(int x) {
        vector<int> path;
        while (true) {
            path.push_back(x);
            if (x == 0) break;
            x = (x - 1) / m;
        }
        reverse(path.begin(), path.end());
        return path;
    }

    bool lockNode(int x, int uid) {
        vector<int> path = getPath(x);

        if (lb[x] != 0 || ldc[x] > 0)
            return false;

        for (int i = 0; i < (int)path.size() - 1; i++) {
            if (lb[path[i]] != 0)
                return false;
        }

        if (lb[x] != 0) return false;
        lb[x] = -1;

        if (ldc[x] > 0) {
            lb[x] = 0;
            return false;
        }

        for (int i = 0; i < (int)path.size() - 1; i++) {
            if (lb[path[i]] != 0) {
                lb[x] = 0;
                return false;
            }
        }

        lb[x] = uid;

        for (int i = 0; i < (int)path.size() - 1; i++) {
            ldc[path[i]]++;
        }

        return true;
    }

    bool unlockNode(int x, int uid) {
        vector<int> path = getPath(x);

        if (lb[x] != uid)
            return false;

        lb[x] = -1;

        if (lb[x] != -1) return false; // safety (rare case)

        lb[x] = 0;

        for (int i = 0; i < (int)path.size() - 1; i++) {
            ldc[path[i]]--;
        }

        return true;
    }

    bool upgradeNode(int x, int uid) {
        vector<int> path = getPath(x);

        if (lb[x] != 0 || ldc[x] == 0)
            return false;

        for (int i = 0; i < (int)path.size() - 1; i++) {
            if (lb[path[i]] != 0)
                return false;
        }

        if (lb[x] != 0) return false;
        lb[x] = -1;

        vector<int> to_unlock;
        queue<int> q;
        q.push(x);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int i = 1; i <= m; i++) {
                int c = u * m + i;
                if (c >= n) break;

                if (lb[c] > 0) {
                    if (lb[c] != uid) {
                        lb[x] = 0;
                        return false;
                    }
                    to_unlock.push_back(c);
                }

                if (ldc[c] > 0)
                    q.push(c);
            }
        }

        for (int node : to_unlock) {
            lb[node] = 0;

            int curr = node;
            while (curr > 0) {
                curr = (curr - 1) / m;
                ldc[curr]--;
            }
        }

        for (int i = 0; i < (int)path.size() - 1; i++) {
            if (lb[path[i]] != 0) {
                lb[x] = 0;
                return false;
            }
        }

        lb[x] = uid;

        for (int i = 0; i < (int)path.size() - 1; i++) {
            ldc[path[i]]++;
        }

        return true;
    }
};




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, q;
	cin >> n >> m >> q;

	unordered_map<string, int> mp;
	mp.reserve(n);

	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		mp[s] = i;
	}

	TreeLock tree(n,m);

	for(int i=0; i<q; i++) {
		int op, uid;
		string name;
		cin >> op >> name >> uid;
		int x = mp[name];
		bool ans = false;

		if(op == 1) ans = tree.lockNode(x, uid);
		else if(op == 2) ans = tree.unlockNode(x, uid);
		else if(op == 3) ans = tree.upgradeNode(x, uid);

		if(ans) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}
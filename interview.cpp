#include<bits/stdc++.h>
using namespace std;

class TreeLock {
	int n, m;
	vector<int> lb;
	vector<int> ldc;
    vector<mutex> node_mutex;

	public:
	TreeLock(int n, int m) : n(n), m(m) {
		lb.assign(n, 0);
		ldc.assign(n, 0);
        node_mutex.resize(n);
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

        for (int node : path) {
            node_mutex[node].lock();
        }

        // Critical Section
        if (lb[x] != 0 || ldc[x] > 0) {
            for (int i = path.size() - 1; i >= 0; i--)
                node_mutex[path[i]].unlock();
            return false;
        }

        for (int i = 0; i < (int)path.size() - 1; i++) {
            if (lb[path[i]] != 0) {
                for (int j = path.size() - 1; j >= 0; j--)
                    node_mutex[path[j]].unlock();
                return false;
            }
        }

        lb[x] = uid;

        for (int i = 0; i < (int)path.size() - 1; i++) {
            ldc[path[i]]++;
        }

        for (int i = path.size() - 1; i >= 0; i--)
            node_mutex[path[i]].unlock();

        return true;
    }

	bool unlockNode(int x, int uid) {
        vector<int> path = getPath(x);

        for (int node : path)
            node_mutex[node].lock();

        // Critical Section
        if (lb[x] != uid) {
            for (int i = path.size() - 1; i >= 0; i--)
                node_mutex[path[i]].unlock();
            return false;
        }

        lb[x] = 0;

        for (int i = 0; i < (int)path.size() - 1; i++) {
            ldc[path[i]]--;
        }

        for (int i = path.size() - 1; i >= 0; i--)
            node_mutex[path[i]].unlock();

        return true;
    }

	// bool upgradeNode(int x, int uid) {
	// 	if(lb[x] != 0) return false;
	// 	if(ldc[x] == 0) return false;

	// 	int curr = x;
	// 	while(curr > 0) {
	// 		curr = (curr-1)/m;
	// 		if(lb[curr] != 0) return false;
	// 	}

	// 	vector<int> to_unlock;
	// 	queue<int> q;
	// 	q.push(x);

	// 	while(!q.empty()) {
	// 		int u = q.front();
	// 		q.pop();

	// 		for(int i=1; i<=m; i++) {
	// 			int c = u*m + i;
	// 			if(c >= n) break;
	// 			if(lb[c] != 0) {
	// 				if(lb[c] != uid) return false;
	// 				to_unlock.push_back(c);
	// 			}
	// 			if(ldc[c] > 0) {
	// 				q.push(c);
	// 			}
	// 		}
	// 	}

	// 	for(int desc : to_unlock) {
	// 		unlockNode(desc, uid);
	// 	}
	// 	lockNode(x, uid);

	// 	return true;
	// }



    bool upgradeNode(int x, int uid) {
        vector<int> path = getPath(x);

        for (int node : path)
            node_mutex[node].lock();

        // Critical Section
        if (lb[x] != 0 || ldc[x] == 0) {
            for (int i = path.size() - 1; i >= 0; i--)
                node_mutex[path[i]].unlock();
            return false;
        }

        for (int i = 0; i < (int)path.size() - 1; i++) {
            if (lb[path[i]] != 0) {
                for (int j = path.size() - 1; j >= 0; j--)
                    node_mutex[path[j]].unlock();
                return false;
            }
        }

        vector<int> to_unlock;
        queue<int> q;
        q.push(x);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int i = 1; i <= m; i++) {
                int c = u * m + i;
                if (c >= n) break;

                if (lb[c] != 0) {
                    if (lb[c] != uid) {
                        for (int i = path.size() - 1; i >= 0; i--)
                            node_mutex[path[i]].unlock();
                        return false;
                    }
                    to_unlock.push_back(c);
                }

                if (ldc[c] > 0)
                    q.push(c);
            }
        }

        for (int desc : to_unlock) {
            lb[desc] = 0;

            int curr = desc;
            while (curr > 0) {
                curr = (curr - 1) / m;
                ldc[curr]--;
            }
        }

        lb[x] = uid;
        for (int i = 0; i < (int)path.size() - 1; i++) {
            ldc[path[i]]++;
        }

        for (int i = path.size() - 1; i >= 0; i--)
            node_mutex[path[i]].unlock();

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



























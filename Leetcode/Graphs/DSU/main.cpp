#include<bits/stdc++.h>
using namespace std;

int find(int i, vector<int>& parent) {
    if(i == parent[i]) {
        return i;
    }

    return parent[i] = find(parent[i], parent);
}

void unionByRank(int a, int b, vector<int>& parent, vector<int>& rank) {
    int parent_a = find(a, parent);
    int parent_b = find(b, parent);

    if(parent_a == parent_b) return;

    if(rank[parent_a] > rank[parent_b]) {
        parent[parent_b] = parent_a;
    }
    else if(rank[parent_a] < rank[parent_b]) {
        parent[parent_a] = parent_b;
    }
    else {
        parent[parent_b] = parent_a;
        rank[parent_a]++;
    }
}

int main() {
    int n = 10; // number of nodes
    vector<int> parent(n), rank(n, 0);

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
}
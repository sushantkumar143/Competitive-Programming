#include <bits/stdc++.h>
using namespace std;

struct ArrayInfo {
    vector<int> data;
    int oi;
    int lexico_rank;
};

bool compareArrays(const ArrayInfo& a, const ArrayInfo& b) {
    return a.data < b.data;
}

struct Element {
    int col;
    int val;
    int array_idx;

    bool operator<(const Element& other) const {
        if (col != other.col) return col < other.col;
        if (val != other.val) return val < other.val;
        return array_idx < other.array_idx;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<ArrayInfo> arrays(n);

    long long total_elements = 0;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        arrays[i].data.resize(k);
        arrays[i].oi = i;

        total_elements += k;
        
        for (int j = 0; j < k; ++j) {
            cin >> arrays[i].data[j];
        }
    }

    sort(arrays.begin(), arrays.end(), compareArrays);
    
    vector<ArrayInfo> aq(n);

    for(int i = 0; i < n; ++i) {
        arrays[i].lexico_rank = i;
        aq[arrays[i].oi] = arrays[i];
    }

    vector<Element> elements;
    elements.reserve(total_elements);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < aq[i].data.size(); ++j) {
            elements.push_back({j, aq[i].data[j], aq[i].lexico_rank});
        }
    }
    

    sort(elements.begin(), elements.end());

    vector<bool> used(n, false);
    int cc = 0;
    size_t elem_ptr = 0;
    bool first_print = true;


    while (elem_ptr < elements.size()) {

        while (elem_ptr < elements.size() && 
               (used[elements[elem_ptr].array_idx] || elements[elem_ptr].col < cc)) {
            elem_ptr++;
        }

        if (elem_ptr == elements.size()) {
            break;
        }

        cc = elements[elem_ptr].col;
        
        int bar = elements[elem_ptr].array_idx;
        const auto& y = arrays[bar].data;

        for (size_t i = cc; i < y.size(); ++i) {
            if (!first_print) std::cout << " ";
            std::cout << y[i];
            first_print = false;
        }

        used[bar] = true;
        cc = y.size();
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

}
#include<bits/stdc++.h>
using namespace std;

int n;
void rotate90(vector<vector<int>>& image) {
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            swap(image[i][j], image[j][i]);
        }
    }

    for(int i=0; i<n; i++) {
        reverse(image[i].begin(), image[i].end());
    }
}

void fun(vector<vector<int>>& image, int h, int v, int r) {

    // Rotation
    int times = (r / 90) % 4;
    while(times--) {
        // transpose
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                swap(image[i][j], image[j][i]);
            }
        }

        // reverse each row
        for(int i=0; i<n; i++) {
            reverse(image[i].begin(), image[i].end());
        }
    }

    // Horizontal Flip (top-bottom)
    if(h) {
        reverse(image.begin(), image.end());
    }

    // Vertical Flip (left-right)
    if(v) {
        for(int i=0; i<n; i++) {
            reverse(image[i].begin(), image[i].end());
        }
    }
}

int main() {
    cin >> n;
    
    vector<vector<int>> image(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> image[i][j];
        }
    }

    int horizontal, vertical, rotate;

    cin >> horizontal >> vertical >> rotate;

    fun(image, horizontal, vertical, rotate);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << image[i][j] << " ";
        }
        cout << '\n';
    }
}
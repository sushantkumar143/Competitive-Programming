#include <bits/stdc++.h>
using namespace std;

// GOOD QUESTION

int headRequired = 0;

double dp[3000][3000];

double rec(int n, int h, double p[]) {
	if(n < 0) return (double) h >= headRequired;

	if(dp[n][h] != -1.0) return dp[n][h];

	double head = p[n] * rec(n - 1, h + 1, p);
	double tail = (1.0 - p[n]) * rec(n - 1, h, p);

	return dp[n][h] = head + tail;
}

int main() {
	cout << fixed << setprecision(10);
	int n; cin >> n;
	headRequired = (n + 1) / 2;
	double p[n];
	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dp[i][j] = -1.0;

	cout << rec(n - 1, 0, p) << endl;
}
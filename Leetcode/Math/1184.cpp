#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sm = accumulate(distance.begin(), distance.end(), 0);
        int s = 0;
        int n = distance.size();
        int i = start;
        while(i != destination) {
            s += distance[i];
            i = (i+1) % n;
        }

        int dist1 = s;
        int dist2 = abs(sm - s);

        return min(dist1, dist2);
    }
};
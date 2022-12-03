#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define inf LONG_LONG_MAX

int main() {
    int n, s, f;
    cin >> n >> s >> f;
    s--;
    f--;
    vector<vector<int>> edges(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> edges[i][j];
        }
    }
    vector<int> used(n);
    vector<long long> distance(n, inf);
    distance[s] = 0;
    while (true) {
        long long m = inf, g = -1;
        for (int i = 0; i < n; i++) {
            if (distance[i] < m && used[i] != 1) {
                m = distance[i];
                g = i;
            }
        }
        if (m == inf) {
            break;
        }
        used[g] = 1;
        for (int i = 0; i < n; i++) {
            long long c = inf;
            if (edges[g][i] != -1) {
                c = edges[g][i] + distance[g];
                distance[i] = min(c, distance[i]);
            }
        }
    }
    if (distance[f] == inf) {
        cout << -1;
    }
    else {
        cout << distance[f];
    }
}
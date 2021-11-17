/*
ID: dr.yste1
TASK: cowtour
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "cowtour"

int main() {
    ifstream fin(PROBLEM ".in");
    ofstream fout(PROBLEM ".out");
    int n;
    fin >> n;
    vector<pair<int,int>> points(n);
    for (int i = 0; i < n; i++) {
        fin >> points[i].first >> points[i].second;
    }
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    auto dist = [](auto &a, auto &b) {
        int x = a.first - b.first;
        int y = a.second - b.second;
        return sqrt(x * x + y * y);
    };
    vector<vector<double>> d(n, vector<double> (n, 1e9));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == '1') {
                d[i][j] = d[j][i] = dist(points[i], points[j]);
            } else if (i == j) {
                d[i][i] = 0;
            }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    auto tmp = d;
    double best = 1e9;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++) 
            if (tmp[x][y] > 1e8) {
                d = tmp;
                // need Dijkstra here
                d[x][y] = d[y][x] = dist(points[x], points[y]);
                for (int k = 0; k < n; k++)
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < n; j++) 
                            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                double maxd = 0;
                for (int i = 0; i < n; i++) 
                    for (int j = 0; j < n; j++)
                        maxd = max(maxd, d[i][j]);
                best = min(best, maxd);
            }
    fout << fixed << setprecision(6) << best << '\n';
    fin.close();
    fout.close();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int,vector<pair<int,int>>> s;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            s[a[i] + a[j]].push_back(make_pair(i + 1, j + 1));
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (pair<int,int> p : s[x - a[i] - a[j]])
                if (i + 1 != p.first && j + 1 != p.first &&  i + 1 != p.second && j + 1 != p.second) {
                    cout << i + 1 << ' ' << j + 1 << ' ' << p.first << ' ' << p.second << '\n';
                    return 0;
                }
    cout << "IMPOSSIBLE\n";
    return 0;
}

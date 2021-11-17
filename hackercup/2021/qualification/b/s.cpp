#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    for (int _t = 1; _t <= tt; _t++) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> cnt(1000000, 0);
        for (int i = 0; i < n; i++) {
            int e = 0, o = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '.') e++;
                if (a[i][j] == 'O') o++;
            }
            if (o == 0) cnt[e]++;
            e = 0, o = 0;
            for (int j = 0; j < n; j++) {
                if (a[j][i] == '.') e++;
                if (a[j][i] == 'O') o++;
            }
            if (o == 0) cnt[e]++;
        }
        int total = -1;
        for (int i = 0; i < cnt.size(); i++)
            if (cnt[i] > 0) {
                total = i;
                break;
            }
        cout << "Case #" << _t << ": ";
        if (total == -1) {
            cout << "Impossible\n";
        } else {
            int sets = cnt[total];
            if (total == 1) {
                set<pair<int,int>> sp;
                for (int i = 0; i < n; i++) {
                    int e = 0, o = 0;
                    for (int j = 0; j < n; j++) {
                        if (a[i][j] == '.') e++;
                        if (a[i][j] == 'O') o++;
                    }
                    if (o == 0 && e == total) {
                        for (int j = 0; j < n; j++) {
                            if (a[i][j] == '.') sp.insert({i, j});
                        }
                    }
                    e = 0, o = 0;
                    for (int j = 0; j < n; j++) {
                        if (a[j][i] == '.') e++;
                        if (a[j][i] == 'O') o++;
                    }
                    if (o == 0 && e == total) {
                        for (int j = 0; j < n; j++) {
                            if (a[j][i] == '.') sp.insert({j, i});
                        }
                    }
                }
                sets = sp.size();
             }
            cout << total << ' ' << sets << '\n';
        }
    }
    return 0;
}

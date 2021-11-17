#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        while (1) {
            n++;
            int _n = n;
            vector<int> d;
            for (; _n > 0; _n /= 10)
                d.push_back(_n % 10);
            sort(d.begin(), d.end());
            bool g = true;
            for (int i = 1; i < d.size(); i++)
                g &= d[i] != d[i - 1];
            if (g)
                break;
        }
        cout << n << '\n';
    }
    return 0;
}

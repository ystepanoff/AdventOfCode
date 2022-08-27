#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<int> a(2 * n + 1), b(2 * n + 1);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[x] = y;
        a[x + y]++;
        b[n - x + y]++;
    }
    int total = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++) {
                a[i + p[i]]--; b[n - i + p[i]]--;
                a[j + p[j]]--; b[n - j + p[j]]--;
                a[k + p[k]]--; b[n - k + p[k]]--;
                
                // (2,3,1)
                a[i + p[j]]++; b[n - i + p[j]]++;
                a[j + p[k]]++; b[n - j + p[k]]++;
                a[k + p[i]]++; b[n - k + p[i]]++;
                total += a[i + p[j]] <= 1 && a[j + p[k]] <= 1 && a[k + p[i]] <= 1 &&
                    b[n - i + p[j]] <= 1 && b[n - j + p[k]] <= 1 && b[n - k + p[i]] <= 1;
                a[i + p[j]]--; b[n - i + p[j]]--;
                a[j + p[k]]--; b[n - j + p[k]]--;
                a[k + p[i]]--; b[n - k + p[i]]--;

                // (3,1,2)
                a[i + p[k]]++; b[n - i + p[k]]++;
                a[j + p[i]]++; b[n - j + p[i]]++;
                a[k + p[j]]++; b[n - k + p[j]]++;
                total += a[i + p[k]] <= 1 && a[j + p[i]] <= 1 && a[k + p[j]] <= 1 &&
                    b[n - i + p[k]] <= 1 && b[n - j + p[i]] <= 1 && b[n - k + p[j]] <= 1;
                a[i + p[k]]--; b[n - i + p[k]]--;
                a[j + p[i]]--; b[n - j + p[i]]--;
                a[k + p[j]]--; b[n - k + p[j]]--;
                
                a[i + p[i]]++; b[n - i + p[i]]++;
                a[j + p[j]]++; b[n - j + p[j]]++;
                a[k + p[k]]++; b[n - k + p[k]]++;
            }
    cout << total << '\n';
    return 0;
}

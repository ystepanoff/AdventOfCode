#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    if (n == 1) {
        cout << "0\n";
    } else {
        long long k = 1;
        while ((1LL << k) <= n)
            k++;
        k--;
        cout << k << '\n'; 
    }
    return 0;
}

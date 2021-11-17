#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<char> st;
    for (int i = 0; i < n; i++) {
        if (st.size() > 0 && st.back() == s[i]) {
            st.pop_back();
        } else {
            st.push_back(s[i]);
        }
    }
    for (char c : st) {
        cout << c;
    }
    cout << '\n';
    return 0;
}

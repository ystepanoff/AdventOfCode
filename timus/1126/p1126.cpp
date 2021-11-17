#include <bits/stdc++.h>
using namespace std;

struct mstack {
    vector<int> s, smax;
    void push(int x) {
        s.push_back(x);
        smax.push_back(smax.empty() ? x : ::max(x, smax.back()));
    }
    int pop() {
        int r = s.back();
        s.pop_back();
        smax.pop_back();
        return r;
    }
    bool empty() {
        return s.empty();
    }
    int max() {
        return smax.empty() ? INT_MIN : smax.back();
    }
};

mstack st1, st2;

void enqueue(int x) {
    st2.push(x);
}

void dequeue() {
    if (st1.empty()) {
        while (!st2.empty())
            st1.push(st2.pop());
    }
    st1.pop();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    for (int i = 1; ; i++) {
        int v;
        cin >> v;
        if (v == -1) {
            break;
        }
        enqueue(v);
        if (i >= m) {
            cout << max(st1.max(), st2.max()) << '\n';
            dequeue();
        }
    }
    return 0;
}

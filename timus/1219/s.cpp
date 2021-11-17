#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 1000000; i++) {
        cout << alpha[rand() % alpha.length()];
    }
    cout << '\n';
    return 0;
}

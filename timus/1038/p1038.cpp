#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string text = "";
    string s;
    while (getline(cin, s))
        text += s + " ";
    auto check_word = [&](string w) {
        int total = 0;
        for (int i = 1; i < w.length(); i++)
            total += w[i] >= 'A' && w[i] <= 'Z';
        return total;
    };
    bool new_sentence = true;
    string w = "";
    int total = 0;
    for (int i = 0; i <= text.length(); i++) {
        if (i == text.length()) {
            total += check_word(w);
        } else {
            //cout << text[i] << " " << (new_sentence?"1":"0") << " " << w << "\n";
            if (new_sentence) {
                if (text[i] >= 'a' && text[i] <= 'z') {
                    total++;
                    new_sentence = false;
                }
                if (text[i] >= 'A' && text[i] <= 'Z') {
                    new_sentence = false;
                }
            }
            if (isalpha(text[i])) {
                w += text[i];
            } else {
                if (w.length() > 0) {
                    total += check_word(w);
                }
                w = "";
                if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
                    new_sentence = true;
                }
            }
        }
    }
    cout << total << '\n';
    return 0;
}

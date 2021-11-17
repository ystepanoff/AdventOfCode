#include <bits/stdc++.h>
using namespace std;

void convert(int n) {
    if (!n)
        return;
    convert((n - 1) / 26);
    putchar('A' + ((n - 1) % 26));
}

int main() {
    int n;
    scanf("%d", &n);
    char s[256];
    while (n--) {
        scanf("%s", s);
        int r, c;
        if (sscanf(s, "R%dC%d", &r, &c) == 2) {
            convert(c);
            printf("%d\n", r);
        } else {
            sscanf(s, "%*[A-Z]%d", &r);
            int c = 0;
            for (int i = 0; i < 256; i++)
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    c = c * 26 + s[i] - 'A' + 1;
                } else {
                    break;
                }
            printf("R%dC%d\n", r, c);
        }
    }
    return 0;
}

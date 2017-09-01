#include <bits/stdc++.h>

using namespace std;

int const N = 1010;

char s[N];
int main() {
    int n, p;
    scanf("%d %d %s", &n, &p, s);
    p += 'a';
    for (int i = strlen(s) - 1; i >= 0; --i) {
        bool f = 0;
        while (s[i] + 1 < p) {
            ++s[i];
            if (i > 0 && s[i] == s[i - 1]) continue;
            if (i > 1 && s[i] == s[i - 2]) continue;
            f = 1;
            break;
        }
        if (f) {
            int len = strlen(s);
            for (int j = i + 1; j < len; ++j) {
                s[j] = 'a';
                while (s[j] + 1 < p) {
                    if (j > 0 && s[j] == s[j - 1]) ++s[j];
                    else if (j > 1 && s[j] == s[j - 2]) ++s[j];
                    else break;
                }
            }
            puts(s);
            return 0;
        }
    }
    puts("NO");
    return 0;
}
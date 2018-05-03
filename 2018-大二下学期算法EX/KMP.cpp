#include <iostream>
#include <cstring>

#ifdef ALG_MAIN

using namespace std;

int *calNext(const char *p) {
    int *next = new int[strlen(p)];
    int t = next[0] = -1;
    int j = 0;
    while (j < strlen(p) - 1) {
        if (t < 0 || p[t] == p[j]) {
            j++;
            t++;
            next[j] = (p[j] != p[t] ? t : next[t]);
        } else {
            t = next[t];
        }
    }

    return next;
}

int strStr(const char *T, const char *P) {
    if (!T || !P) return -1;
    int pLen = strlen(P), j = 0;
    int tLen = strlen(T), i = 0;
    if (pLen == 0 || tLen == 0) return -1;
    int *next = calNext(P);
    while (j < pLen && i < tLen) {
        if (j < 0 || T[i] == P[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j != pLen) {
        return -1;
    }
    return i - j;
}

int main() {
    string t, p;
    while (cin >> t >> p) {
        cout << strStr(t.c_str(), p.c_str()) << endl;
    }

}

#endif
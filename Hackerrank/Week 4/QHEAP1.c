#include <stdio.h>
#include <stdlib.h>

#define MAX 100000   

int h[MAX];   
int sz = 0;   


void swp(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}


void up(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] > h[i]) {
            swp(&h[p], &h[i]);
            i = p;
        } else break;
    }
}


void down(int i) {
    while (2 * i + 1 < sz) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int s = i;

        if (l < sz && h[l] < h[s]) s = l;
        if (r < sz && h[r] < h[s]) s = r;

        if (s != i) {
            swp(&h[i], &h[s]);
            i = s;
        } else break;
    }
}


void add(int v) {
    h[sz] = v;
    up(sz);
    sz++;
}


void rem(int v) {
    int idx = -1;
    for (int i = 0; i < sz; i++) {
        if (h[i] == v) {
            idx = i;
            break;
        }
    }
    if (idx == -1) return;

    h[idx] = h[sz - 1];
    sz--;

    up(idx);
    down(idx);
}


int getMin() {
    return h[0];
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int t, v;
        scanf("%d", &t);

        if (t == 1) {
            scanf("%d", &v);
            add(v);
        } else if (t == 2) {
            scanf("%d", &v);
            rem(v);
        } else if (t == 3) {
            printf("%d\n", getMin());
        }
    }
    return 0;
}

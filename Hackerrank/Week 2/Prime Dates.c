#include <stdio.h>

int monthDays(int m, int y) {
    if (m == 1) return 31;
    if (m == 2) {
        if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0))
            return 29;
        else
            return 28;
    }
    if (m == 3) return 31;
    if (m == 4) return 30;
    if (m == 5) return 31;
    if (m == 6) return 30;
    if (m == 7) return 31;
    if (m == 8) return 31;
    if (m == 9) return 30;
    if (m == 10) return 31;
    if (m == 11) return 30;
    return 31;
}

int main() {
    int d1, m1, y1;
    int d2, m2, y2;
    scanf("%d-%d-%d", &d1, &m1, &y1);
    scanf("%d-%d-%d", &d2, &m2, &y2);

    int ans = 0;
    while (1) {
        long long val = d1 * 1000000 + m1 * 10000 + y1;

        if (val % 4 == 0 || val % 7 == 0) { 
            ans++;
        }

        if (d1 == d2 && m1 == m2 && y1 == y2) break;

        d1++;
        if (d1 > monthDays(m1, y1)) {
            d1 = 1;
            m1++;
            if (m1 > 12) {
                m1 = 1;
                y1++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

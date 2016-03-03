#include <cstdio>
#include <algorithm>
int k, n, l[10010], mi=0,m,sum=0;
int bs(int s, int e) {
    while (s<=e) {
        m = (s + e) / 2;
        int v = 0;
        for (int i = 0; i < k; i++)
            v += l[i] / m;
        if (v >= n) s = m + 1;
        else if (v < n) e = m - 1;
    }
    return e;	
}
int main() {
    scanf("%d %d", &k, &n);
    for (int i = 0; i<k; i++) {
        scanf("%d", &l[i]);
        mi = std::max(mi, l[i]);
    }
    printf("%d",(n==1)?mi:bs(1, mi));
}

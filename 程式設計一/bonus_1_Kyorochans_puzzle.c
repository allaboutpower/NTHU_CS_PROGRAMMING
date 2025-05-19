#include <stdio.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
#define maxn 200000
#define int long long
#define scan(x) scanf("%lld", &x)
#define print(x) printf("%lld ", x)

int a[maxn] = { 0 };

int cal(int v) { return (v + 1) * v / 2; }

void solve() {
    int n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    rep(i, 0, n) a[i] = 0;
    int l = 0, r = (int)1e6;
    while (l < r) {
        int mid = (l + r) / 2;
        if (cal(mid) < m) l = mid + 1;
        else r = mid;
    }
    if (n < r) {
        printf("-1\n");
        return;
    }
    rep(i, 0, r) {
        a[i] = k;
    }
    int diff = cal(r) - m;
    int id = 0;
    while (diff) {
        if (id >= n) {
            printf("-1\n");
            return;
        }
        l = 0; r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (cal(mid) < diff) l = mid + 1;
            else r = mid;
        }
        r -= (cal(r) == diff ? 0 : 1);
        rep(i, id, id + r) {
            a[i] = 2 * k;
        }
        id += r + 1;
        diff -= cal(r);
    }
    rep(i, 0, n) {
        if (a[i] == 0) {
            a[i] = k + 1;
        }
        print(a[i]);
    }
    printf("\n");
}


signed main() {
    int t = 1;
    scan(t);
    while (t--) {
        solve();
    }
    return 0;
}
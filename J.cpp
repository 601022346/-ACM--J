#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
#define met(a, b) memset(a, b, sizeof(a))
struct MATION {
    int l, r, id;
} q[2 * maxn];
ll cnt = 0;
int pos[maxn], block, val[maxn], ANS[maxn], a[maxn];
bool vis[maxn];
int d, n, m, top = 0;
int cmp(MATION a, MATION b) {
    if(pos[a.l] != pos[b.l]) return pos[a.l] < pos[b.l];
    else return a.r < b.r;
}
void solve() {
    met(val, 0);
    int ans = 0;
    int l = q[0].l, r = q[0].l - 1;
    for(int i = 0; i < top; i++) {
        while(l < q[i].l) {
            val[a[l]]--;
            if(val[a[l]] == 0) ans--;
            l++;
        }
        while(l > q[i].l) {
            l--;
            val[a[l]]++;
            if(val[a[l]] == 1) ans++;
        }
        while(r < q[i].r) {
            r++;
            val[a[r]]++;
            if(val[a[r]] == 1) ans++;
        }
        while(r > q[i].r) {
            val[a[r]]--;
            if(val[a[r]] == 0) ans--;
            r--;
        }
        ANS[q[i].id] = ans;
    }
}
int main() {
    while(~scanf("%d%d", &n, &m)) {
        met(vis, false);
        cnt = 0;
        block = sqrt(n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            pos[i] = (i - 1) / block + 1;
            pos[i + n] = (i + n - 1) / block + 1;
            a[i + n] = a[i];
            if(!vis[a[i]]) {
                vis[a[i]] = true;
                cnt++;
            }
        }
        int l, r;
        top = 0;
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &l, &r);
            if(r <= l) {
                ANS[i] = cnt;
                continue;
            }
            q[top].l = r;
            q[top].r = n + l;
            q[top].id = i;
            top++;
        }
        sort(q, q + top, cmp);

        solve();
        for(int i = 0; i < m; i++) {
            //cout << ANS[i * 2] << " * " << ANS[i * 2 + 1] << endl;
            printf("%d\n",ANS[i]);
        }
    }
    return 0;
}

#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    int a[n+1];
    a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i] += a[i-1];
    int res = 0;
    int lp = 0;
    for (int i = 0; i <= n; i++) {
        //cout << "Psum at " << i << " = " << a[i] << '\n';
        if (s.count(a[i]) != 0) {
            res++;
            //cout << "LP before: " << lp << '\n';
            while (lp < i-1) {
                s.erase(a[lp]);
                lp++;
            }
            //cout << "LP after: " << lp << '\n';
        }
        s.insert(a[i]);
    }
    cout << res << '\n';
}
/*

 */
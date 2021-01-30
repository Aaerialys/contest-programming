#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        if (n <= 2) {
            cout << "1\n";
        } else {
            n -= 2;
            n = ceil((double)n/(double)x);
            cout << 1+n << '\n';
        }
    }
}
/*

 */
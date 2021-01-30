#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;
int f(int x) {
    int cur = x+1;
    int y = ceil((double)n/(double)cur);
    return x+y;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int sq = sqrt(n);
        int res = 1e9;
        for (int i = max((int)0,sq-10); i <= sq+10; i++) res = min(res, f(i));
        cout << res-1 << '\n';
    }
}
/*

 */
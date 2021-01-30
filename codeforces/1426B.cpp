#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        bool flag = false;
        bool dia = false;
        set<pair<pair<int,int>,pair<int,int>>> s;
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if (b == c) dia = true;
            s.insert({{a,b}, {c,d}});
            if (s.count({{a,c}, {b,d}})) flag = true;
        }
        if (m == 2 && dia) {
            cout << "YES\n";
            continue;
        }
        if (m%2==0 && flag && dia) cout << "YES\n";
        else cout << "NO\n";
    }
}
/*
1
2 4

 */
#include <bits/stdc++.h>

#define int long long

using namespace std;

set<int> s;
void recur(int ar, int as, int ap, int br, int bs, int bp, int cur) {
    //cout << "Cur = " << cur << '\n';
    //cout << "rec " << ar << " " << as << " " << ap << " " << br << " " << bs << " " << bp << '\n';
    if (ar == 0 && as == 0 && ap == 0 && br == 0 && bs == 0 && bp == 0) {
        s.insert(cur);
        return;
    }
    if (ar > 0 && br > 0) recur(ar-min(ar,br),as,ap,br-min(ar,br),bs,bp,cur);
    if (ar > 0 && bs > 0) recur(ar-min(ar,bs),as,ap,br,bs-min(ar,bs),bp,cur+min(ar,bs));
    if (ar > 0 && bp > 0) recur(ar-min(ar,bp),as,ap,br,bs,bp-min(ar,bp),cur);

    if (as > 0 && br > 0) recur(ar,as-min(as,br),ap,br-min(as,br),bs,bp,cur);
    if (as > 0 && bs > 0) recur(ar,as-min(as,bs),ap,br,bs-min(as,bs),bp,cur);
    if (as > 0 && bp > 0) recur(ar,as-min(as,bp),ap,br,bs,bp-min(as,bp),cur+min(as,bp));

    if (ap > 0 && br > 0) recur(ar,as,ap-min(ap,br),br-min(ap,br),bs,bp,cur+min(ap,br));
    if (ap > 0 && bs > 0) recur(ar,as,ap-min(ap,bs),br,bs-min(ap,bs),bp,cur);
    if (ap > 0 && bp > 0) recur(ar,as,ap-min(ap,bp),br,bs,bp-min(ap,bp),cur);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ar, as, ap, br, bs, bp;
    cin >> ar >> as >> ap >> br >> bs >> bp;
    recur(ar,as,ap,br,bs,bp,0);
    cout << *s.begin() << ' ' << *s.rbegin() << '\n';
}
/*

 */
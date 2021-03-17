#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

#define MOD 1000000007
#define INF 2000000000

int GLL(LL& x) {
    return scanf("%lld", &x);
}

int GI(int& x) {
    return scanf("%d", &x);
}

const int MAXN = 100005;
int q[2][MAXN], qInv[2][MAXN], qCopy[2][MAXN];

int n, x;

vector<int> merged;

LL inversions(int p[], int l, int r) {
    if (l != r) {
        int m = (l+r) / 2;  // [l,m], [m+1,r]

        LL res = inversions(p, l, m) + inversions(p, m + 1, r);

        merged.clear();

        int i = l; int j = m + 1;

        while (i <= m && j <= r) {
            if (p[i] < p[j]) {
                res += j - (m + 1);
                merged.PB(p[i]);
                i++;
            }
            else {
                merged.PB(p[j]);
                j++;
            }
        }
        while (i <= m) {
            res += j - (m + 1);
            merged.PB(p[i]);
            i++;
        }
        while (j <= r) {
            merged.PB(p[j]);
            j++;
        }

        i = 0;
        for (j = l; j <= r; j++) {
            p[j] = merged[i];
            i++;
        }

        return res;
    }
    else {
        return 0;
    }
}

int main() {
    GI(n);

    FORN(seq, 2) FOR1(i, n) {
        GI(q[seq][i]);
        qInv[seq][q[seq][i]] = i;
    }

    FORN(seq, 2) FOR1(i, n) {
        qCopy[seq][i] = qInv[1-seq][q[seq][i]];
    }

    FORN(seq, 2) FOR1(i, n) {
        q[seq][i] = qCopy[seq][i];
    }

    LL res = 1LL*INF*INF;

    FORN(seq, 2) {
        LL cur = inversions(q[seq], 1, n);

        for (int i = n; i >= 1; i--) {
            cur += 2 * qCopy[seq][i] - n - 1;
            res = min(res, cur);
        }
    }

    printf("%lld\n", res);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)

#define pb push_back

const long double pi = acos(-1.0L);

signed main() {
	int n;
	cin >> n;
	long double x[n], y[n];
	F0R(i,n) cin >> x[i] >> y[i];
	int ans = 0;
	F0R(i,n) {
		vector<long double> v;
		F0R(j,n) if (j != i) {
			v.pb(atan2(y[j]-y[i],x[j]-x[i]));
		}
		sort(v.begin(), v.end());
		int f[n-1], s[n-1];
		int k = 0;
		F0R(j,n-1) {
			while (k < n-1 && v[k] < v[j]+pi) ++k;
			f[j] = k;
			s[j] = (j?s[j-1]:0)+f[j];
		}
		F0R(j,n-1) {
			ans += (s[f[j]-1]-s[j])-(f[j])*(f[j]-j-1);
		}
	}
	cout << ans*(n-4)/2 << endl;
}

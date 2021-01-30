#include <bits/stdc++.h>

#define int long long

using namespace std;

int mod = 1e9+7;
int binpow(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 1) return (a*binpow(a,b-1))%mod;
    int v = binpow(a,b/2);
    return (v*v)%mod;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int psum[4][n+1]; // a = 0, b = 1, c = 2, ? = 3
    for (int i = 0; i < 4; i++) for (int j = 0; j <= n; j++) psum[i][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) psum[j][i] += psum[j][i-1];
        if (s[i-1] == 'a') psum[0][i]++;
        if (s[i-1] == 'b') psum[1][i]++;
        if (s[i-1] == 'c') psum[2][i]++;
        if (s[i-1] == '?') psum[3][i]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        //abc
        if (s[i-1] == 'b') {
            int aLeft = psum[0][i];
            int cRight = psum[2][n]-psum[2][i];
            int marks = psum[3][n];
            int cont = ((binpow(3,marks)*aLeft)%mod)*cRight;
            cont %= mod;
            res += cont;
            res %= mod;
        }
        //a??
        if (s[i-1] == 'a') {
            int marksRight = psum[3][n]-psum[3][i];
            int marks = psum[3][n];
            int cont = binpow(3,marks-2)*((((marksRight*(marksRight-1))/2))%mod);
            cont %= mod;
            res += cont;
            res %= mod;
        }
        // ?b?
        if (s[i-1] == 'b') {
            int marksRight = psum[3][n]-psum[3][i];
            int marksLeft = psum[3][i];
            int marks = psum[3][n];
            int cont = binpow(3,marks-2)*(((marksRight*marksLeft))%mod);
            cont %= mod;
            res += cont;
            res %= mod;
        }
        // ??c
        if (s[i-1] == 'c') {
            int marksLeft = psum[3][i];
            int marks = psum[3][n];
            int cont = binpow(3,marks-2)*((((marksLeft*(marksLeft-1))/2))%mod);
            cont %= mod;
            res += cont;
            res %= mod;
        }
        // ab?
        if (s[i-1] == 'b') {
            int aLeft = psum[0][i];
            int mRight = psum[3][n]-psum[3][i];
            int marks = psum[3][n];
            int cont = ((binpow(3,marks-1)*aLeft)%mod)*mRight;
            cont %= mod;
            res += cont;
            res %= mod;
        }
        // a?c
        if (s[i-1] == '?') {
            int aLeft = psum[0][i];
            int cRight = psum[2][n]-psum[2][i];
            int marks = psum[3][n];
            int cont = ((binpow(3,marks-1)*aLeft)%mod)*cRight;
            cont %= mod;
            res += cont;
            res %= mod;
        }
        // ?bc
        if (s[i-1] == 'b') {
            int mLeft = psum[3][i];
            int cRight = psum[2][n]-psum[2][i];
            int marks = psum[3][n];
            int cont = ((binpow(3,marks-1)*cRight)%mod)*mLeft;
            cont %= mod;
            res += cont;
            res %= mod;
        }
        // ???
        if (s[i-1] == '?') {
            int mLeft = psum[3][i-1];
            int mRight = psum[3][n]-psum[3][i];
            int marks = psum[3][n];
            int cont = ((binpow(3,marks-3)*mLeft)%mod)*mRight;
            cont %= mod;
            res += cont;
            res %= mod;
        }
    }
    cout << res << '\n';
}
/*

 */
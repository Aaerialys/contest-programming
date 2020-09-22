#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<int> s[50];
int t;
bool e;
string in;

int hsh(char in[]) {
    int k = in[0] * 1000000 + in[1] * 10000 + in[2] * 100 + in[3];
    int m = in[0] * 11 + in[1] * 101 + in[2] * 1009 + in[3] * 10007;
    return k % m;
}

int main() {    
    for (int i = 0; i < 5; i++) {
        int h;
        cin >> h;
        for (char a = 'A'; a <= 'Z'; a++)
        for (char b = 'A'; b <= 'Z'; b++)
        for (char c = 'A'; c <= 'Z'; c++)
        for (char d = 'A'; d <= 'Z'; d++) {
            char s[5] = {a,b,c,d,'\0'};
            if (hsh(s) == h) {
                cout << s << endl;
                break;
            }
        }
    }
}
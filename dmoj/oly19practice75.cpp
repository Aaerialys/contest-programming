/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: allen
 *
 * Created on December 5, 2018, 8:25 PM
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct penta {
    lli x, y, x2, y2, tint;

    penta(lli a, lli b, lli c, lli d, lli e) : x(a), y(b), x2(c), y2(d), tint(e) {
    }
    penta(){
        x=0;
        y=0;
        x2=0;
        y2=0;
        tint=0;
    }
};

/*
 *
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, t;
    lli a, b, c, d, e;
    cin>>n; t=1;
    penta panes[n];
    set<lli> xcoords;
    set<lli> ycoords;
    for (lli i = 0; i < n; i++) {
        cin >> a >> d >> c >> b; e=1; a+=1e9; b+=1e9; c+=1e9; d+=1e9;
        xcoords.insert(a);
        xcoords.insert(c);
        ycoords.insert(b);
        ycoords.insert(d);
        panes[i] = penta(a, b, c , d , e);
    }
    lli pre[xcoords.size() + 1][ycoords.size() + 1];
    memset(pre, 0, sizeof (pre));
        vector<lli> xcoords2;
    vector<lli> ycoords2;
    xcoords2.push_back(-1);
    ycoords2.push_back(-1);
    for (auto a:xcoords) {
        xcoords2.push_back(a);
    }
    for(auto a:ycoords){
        ycoords2.push_back(a);
    }
    for (penta temp : panes) {
        a = lower_bound(xcoords2.begin(),xcoords2.end(),temp.x) - xcoords2.begin();
        b = lower_bound(ycoords2.begin(),ycoords2.end(),temp.y) - ycoords2.begin();
        c = lower_bound(xcoords2.begin(),xcoords2.end(),temp.x2) - xcoords2.begin();
        d = lower_bound(ycoords2.begin(),ycoords2.end(),temp.y2) - ycoords2.begin();
        pre[a][b] += temp.tint;
        pre[a][d] -= temp.tint;
        pre[c][b] -= temp.tint;
        pre[c][d] += temp.tint;
    }
    lli ans = 0;
    for (lli i = 1; i < xcoords2.size()-1; i++) {
        for (lli j = 1; j < ycoords2.size()-1; j++) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            if (pre[i][j] >= t) {
                ans += (xcoords2[i+1]-xcoords2[i])*(ycoords2[j+1]-ycoords2[j]);
            }
        }
    }
    printf("%lli",ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n,l,r=2e9,x;
int main()
{
    freopen("moobuzz.in", "r", stdin); freopen("moobuzz.out", "w", stdout); ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    while(l<r){
        x=(l+r)/2;
        if(x-x/3-x/5+x/15<n) l=x+1;
        else r=x;
    }
    cout<<r<<endl;
    return 0;
}

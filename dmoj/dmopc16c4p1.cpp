#include <bits/stdc++.h>

using namespace std;

long long n,x;

int main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
    if(x&(x-1))
        cout<<"F\n";
    else
        cout<<"T\n";
    }
    return 0;
}
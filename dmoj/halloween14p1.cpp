#include <bits/stdc++.h>

using namespace std;

int a,b;

int main() {
    cin>>a>>b;
    if(a<b)
        cout<<b-a;
    else
        cout<<min(a%b,b-a%b);
    return 0;
}
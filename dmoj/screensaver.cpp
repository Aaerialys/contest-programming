#include <bits/stdc++.h>

using namespace std;

long long a,b,c,d;
int main() {
    cin>>b>>a>>c>>d; a*=c; b*=d;
    printf("%.6f",sqrt(a*a+b*b));
    return 0;
}
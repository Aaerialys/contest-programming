#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

bool f(int n)
{
    fori(1,500)
        if((int)sqrt(n-i*i)==sqrt(n-i*i))
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    return 0;
}
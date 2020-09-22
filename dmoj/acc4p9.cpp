#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

vector<int> num;
int M=998244353;

vector<int> f(int n)
{
    num.push_back(1);
    fori(1,n)
        num.push_back(1LL*num[i-1]*(i+1)%M);
    return num;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    return 0;
}
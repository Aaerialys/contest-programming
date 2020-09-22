#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,numb[1000010],best[1000010][2];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>numb[i];
    best[0][1]=max(0LL,numb[0]); best[0][0]=0;
    fori(1,n)
    {
        best[i][0]=max(best[i][0],best[i-1][1]);
        best[i][1]=max(best[i][0],best[i-1][0]+numb[i]);
    }
    cout<<best[n-1][1];
    return 0;
}
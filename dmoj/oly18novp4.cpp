#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,l,a,b;
    cin>>n>>m;
    l=floor(log2(n))+1;
    int numb[n];
    int st[l][n];
    fori(0,n)
    {
        cin>>numb[i];
        st[0][i]=numb[i];
    }
    fori(1,l)
    {
        forj(0,n)
        {
            if(j+(1<<(i))<=n)
                st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    fori(0,m)
    {
        cin>>a>>b;
        a--;
        b--;
        l=floor(log2(b-a+1));
        cout<<max(st[l][a],st[l][b-(1<<l)+1])<<"\n";
    }
    return 0;
}
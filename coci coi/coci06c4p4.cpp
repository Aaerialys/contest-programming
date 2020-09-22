#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,c,seq[2][30010];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>c;
    if(c==0)
    {
        cout<<1;
        return 0;
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    seq[0][0]=seq[1][0]=1;
    fori(1,c+1)
        seq[0][i]=seq[1][i]=2;
    fori(3,n+1)
    {
        seq[1][0]=1;
        forj(1,c+1)
        {
            seq[1][j]=seq[1][j-1]+seq[0][j];
            if(j>=i)
                seq[1][j]-=seq[0][j-i];
        }
        forj(0,c+1)
            seq[0][j]=seq[1][j]%1000000007;
    }
    cout<<(seq[1][c]-seq[1][c-1]+1000000007)%1000000007<<endl;
    return 0;
}
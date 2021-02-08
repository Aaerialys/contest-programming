#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,K;
char ch[9]={'*','x','*',' ','x','x','*',' ','*'},x[76][76];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>K;
    fori(0,3)
        forj(0,3)
            fork(i*K,i*K+K)
                for(int l=j*K;l<j*K+K;l++)
                    x[k][l]=ch[i*3+j];
    fori(0,3*K)
    {
        forj(0,3*K)
            cout<<x[i][j];
        cout<<"\n";
    }
    return 0;
}
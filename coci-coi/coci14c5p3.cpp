#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int N=100010;
int n,k,x,y;
int row[N],col[N],d1[2*N],d2[2*N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    fori(0,n)
    {
        cin>>x>>y;
        row[x]++;
        col[y]++;
        d1[x+y]++;
        d2[x-y+N]++;
        if(row[x]>=k||col[y]>=k||d1[x+y]>=k||d2[x-y+N]>=k)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
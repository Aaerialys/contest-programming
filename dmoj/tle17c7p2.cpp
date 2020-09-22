#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,b,c;
    cin>>n>>m;
    vector<int> flight[n];
    vector<int> start[n];
    fori(0,m)
    {
        cin>>a>>b>>c;
        a--;
        c++;
        start[a].push_back(b);
        flight[a].push_back(c);
    }
    c=0;
    fori(1,n)
    {
        b=INT_MAX/8;
        forj(0,start[i-1].size())
        {
            a=ceil((c-start[i-1][j])/24.0)*24;
            b=min(b,start[i-1][j]+flight[i-1][j]+a);
        }
        c=b;
    }
    cout<<"Day "<<floor(b/24.0)<<" Hour "<<b%24<<endl;
    return 0;
}
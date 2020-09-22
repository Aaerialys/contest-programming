#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,d,a,b,c;
    cin>>n>>m>>d;
    vector<int> recipe[n];
    int first[n];
    fori(0,n) first[i]=INT_MAX;
    fori(0,m)
    {
        cin>>a>>b;
        a--;
        fori(0,b)
        {
            cin>>c;
            c--;
            recipe[a].push_back(c);
        }
    }
    fori(0,d)
    {
        cin>>a;
        a--;
        first[a]=min(i+1,first[a]);
    }
    for(int i=n-1;i>=0;i--)
    {
        a=recipe[i].size();
        b=0;
        forj(0,a)
        {
            b=max(b,first[recipe[i][j]]);
        }
        if(a==0)
            b=INT_MAX;
        first[i]=min(first[i],b);
    }
    if(first[0]==INT_MAX)
        cout<<-1;
    else
        cout<<first[0];
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,c[200100];
pair<int,int> x[200100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>x[i].first>>x[i].second>>c[i];
        x[i].second=i;
    }
    sort(x,x+n);
    fori(1,n-1)
    {
        if((c[x[i].second]+c[x[i-1].second]+c[x[i+1].second])%3!=0)
        {
            cout<<x[i-1].second+1<<" "<<x[i].second+1<<" "<<x[i+1].second+1;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
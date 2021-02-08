#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int ranc,n,x;
multiset<int> lead;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    lead.insert(0);
    fori(0,n)
    {
        cin>>ranc;
        if(lead.lower_bound(ranc)==lead.begin())
        {
            cout<<"NO";
            return 0;
        }
        x=*next(lead.lower_bound(ranc),-1);
        lead.erase(next(lead.lower_bound(ranc),-1));
        lead.insert(ranc); lead.insert(ranc);
    }
    cout<<"YES";
    return 0;
}
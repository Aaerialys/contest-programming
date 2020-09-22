#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int q,x;
    char ch;
    deque<int> l;
    unordered_map<int,int> lc,nu;
    cin>>q;
    fori(0,q)
    {
        cin>>ch>>x;
        if(ch=='F')
        {
            l.push_front(x);
            lc[x]=0;
        }
        if(ch=='E')
        {
            l.push_back(x);
            lc[x]=1;
        }
        if(ch=='R')
        {
            lc[x]=-1;
            nu[x]++;
        }
    }
    fori(0,l.size())
    {
        if(lc[l[i]]==0)
        {
            cout<<l[i]<<"\n";
            lc[l[i]]=-1;
        }
        if(lc[l[i]]==1)
        {
            if(nu[l[i]]==0)
                cout<<l[i]<<"\n";
            else
                nu[l[i]]--;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,x,j=1;
vector<int> numb[3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>x;
        numb[x%3].push_back(x);
    }
    if(numb[0].size()>numb[1].size()+numb[2].size()+1||(numb[0].size()==0&&min(numb[1].size(),numb[2].size())>0))
    {
        cout<<"impossible\n";
        return 0;
    }
    fori(0,numb[1].size())
    {
        if(j<numb[0].size())
        {
            cout<<numb[0][j]<<" ";
            j++;
        }
        cout<<numb[1][i]<<" ";
    }
    if(numb[0].size()>0)
        cout<<numb[0][0]<<" ";
    fori(0,numb[2].size())
    {
        cout<<numb[2][i]<<" ";
        if(j<numb[0].size())
        {
            cout<<numb[0][j]<<" ";
            j++;
        }
    }
    cout<<"\n";
    return 0;
}
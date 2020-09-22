#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    double c;
    vector<double> river;
    cin>>n;
    fori(0,n)
    {
        cin>>a;
        river.push_back(a);
    }
    cin>>a;
    while(a!=77)
    {
        if(a==88)
        {
            cin>>b;
            b--;
            river[b]+=river[b+1];
            river.erase(river.begin()+b+1);
        }
        if(a==99)
        {
            cin>>b>>c;
            b--;
            river.insert(river.begin()+b+1,river[b]*(100-c)/100);
            river[b]=river[b]*c/100;
        }
        cin>>a;
    }
    fori(0,river.size())
    {
        cout<<river[i]<<" ";
    }
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long q,k,m,n;
    string s,s1,s2;
    cin>>q>>k;
    vector<long long> pamu;
    fori(1,1000000)
    {
        s1=to_string(i);
        s2=s1;
        reverse(s2.begin(),s2.end());
        s=s1+s2;
        m=stoll(s);
        if(m%k==0)
            pamu.push_back(m);
        s1.pop_back();
        s=s1+s2;
        m=stoll(s);
        if(m%k==0)
            pamu.push_back(m);
    }
    sort(pamu.begin(),pamu.end());
    fori(0,q)
    {
        cin>>m>>n;
        cout<<upper_bound(pamu.begin(),pamu.end(),n)-lower_bound(pamu.begin(),pamu.end(),m)<<"\n";
    }
    return 0;
}
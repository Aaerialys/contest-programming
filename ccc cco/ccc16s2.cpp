#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,q,a=0;
    cin>>q>>n;
    int peg[n];
    int dmoj[n];
    for(int i=0;i<n;i++)
        cin>>dmoj[i];
    for(int i=0;i<n;i++)
        cin>>peg[i];
    sort(peg,peg+n);
    sort(dmoj,dmoj+n);
    if(q==1)
    {
        for(int i=0;i<n;i++)
        {
            if(peg[i]>dmoj[i])
                a+=peg[i];
            else
                a+=dmoj[i];
        }
    }
    if(q==2)
    {
        for(int i=0;i<n;i++)
        {
            if(peg[i]>dmoj[n-i-1])
                a+=peg[i];
            else
                a+=dmoj[n-i-1];
        }
    }
    cout<<a;
    return 0;
}
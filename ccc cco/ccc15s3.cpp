#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int g,p,a,b,i;
    cin>>g>>p;
    vector<int> gate;
    for(int i=1;i<=g;i++)
        gate.push_back(i);
    for(i=0;i<p;i++)
    {
        cin>>a;
        b=upper_bound(gate.begin(),gate.end(),a)-gate.begin();
        if(b==0)
        {
            cout<<i<<endl;
            return 0;
        }
        else
        {
            gate.erase(gate.begin()+b-1);
        }
    }
    cout<<p;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        vector<int> y;
        cin>>x;
        if(x==0)
        {
            cout<<"0000"<<endl;
        }
        else
        {
            while(x!=0)
            {
                y.push_back(x%2);
                x=x/2;
            }
            for(int j=0;j<(4-y.size()%4)%4;j++)
                cout<<0;
            for(int j=y.size()-1;j>=0;j--)
            {
                cout<<y[j];
                if(j%4==0)
                    cout<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
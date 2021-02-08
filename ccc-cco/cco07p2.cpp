#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    int len[6];
    string flake;
    unordered_set<string> flakes;
    cin>>n;
    fori(0,n)
    {
        forj(0,6)
            cin>>len[j];
        fork(0,6)
        {
            flake="";
            forj(0,6)
                flake+=to_string(len[(j+k)%6]);
            if(flakes.find(flake)!=flakes.end())
            {
                cout<<"Twin snowflakes found."<<endl;
                return 0;
            }
        }
        reverse(len,len+6);
        fork(0,6)
        {
            flake="";
            forj(0,6)
                flake+=to_string(len[(j+k)%6]);
            if(flakes.find(flake)!=flakes.end())
            {
                cout<<"Twin snowflakes found."<<endl;
                return 0;
            }
        }
        flakes.insert(flake);
    }
    cout<<"No two snowflakes are alike."<<endl;
    return 0;
}
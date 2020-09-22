#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

map<string,int> word;
string str;
int x,n;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>str;
        word[str]++;
    }
    for(auto const& i:word)
        if(i.second==1)
            x++;
    cout<<x;
    return 0;
}
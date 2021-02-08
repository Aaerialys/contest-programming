#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

set<pair<int,string>> word[26];
int n,q;
string s;
char ch;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    fori(0,n)
    {
        cin>>s;
        word[s[0]-'a'].insert({0,s});
    }
    fori(0,q)
    {
        cin>>ch;
        auto x=*word[ch-'a'].begin();
        cout<<x.second<<"\n";
        word[ch-'a'].erase(x);
        x.first++;
        word[ch-'a'].insert(x);
    }
    return 0;
}
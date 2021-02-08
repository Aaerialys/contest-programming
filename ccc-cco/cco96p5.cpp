#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,q,a,b,pre[26];
vector<int> gr[26];
string s1,s2;

bool dfs(int p,int v)
{
    if(v==b)
        return true;
    for(auto i:gr[v])
        if(i!=p&&dfs(v,i))
        {
            pre[v]=i;
            return true;
        }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    fori(0,n)
    {
        cin>>s1>>s2; a=s1[0]-'A'; b=s2[0]-'A';
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    fori(0,q)
    {
        cin>>s1>>s2; a=s1[0]-'A'; b=s2[0]-'A';
        dfs(-1,a);
        while(a!=b)
        {
            cout<<(char)(a+'A');
            a=pre[a];
        }
        cout<<(char)(b+'A')<<endl;
    }
    return 0;
}
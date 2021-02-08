#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,t;
unordered_map<string,int> pass;

bool cmp(string a,string b)
{
    return a.size()<b.size();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str[20010];
    cin>>n;
    fori(0,n)
        cin>>str[i];
    sort(str,str+n,cmp);
    fori(0,n)
    {
        set<string> sub;
        forj(1,str[i].size())
            fork(0,str[i].size()-j+1)
            {
                sub.insert(str[i].substr(k,j));
            }
        for(auto i:sub)
            t+=pass[i];
        t+=pass[str[i]]*2;
        pass[str[i]]++;
    }
    cout<<t;
    return 0;
}
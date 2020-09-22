#include <bits/stdc++.h>
using namespace std; int n; string str; bool pos[101]; unordered_map<string,int> f;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("whereami.in", "r", stdin); freopen("whereami.out", "w", stdout);
    cin>>n>>str;
    for(int i=0;i<n;i++) for(int j=0;j<=i;j++) f[str.substr(j,i-j+1)]++;
    for(auto i:f) if(i.second>1) pos[i.first.size()]=1;
    for(int i=1;i<=100001;i++)
        if(!pos[i])
        {
            cout<<i;
            break;
        }
    return 0;
}

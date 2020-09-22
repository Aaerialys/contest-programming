#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

string s;
short pos[151][151];
short go(int l,int r)
{
    if(l>r)
        return true;
    if(l==r)
        return false;
    if(pos[l][r]>=0)
        return pos[l][r];
    fori(l,r)
    {
        if(s[i]!=s[r])
            break;
        if(go(i+1,r-1))
            return pos[l][r]=true;
    }
    ford(i,r,l+1)
    {
        if(s[i]!=s[l])
            break;
        if(go(l+1,i-1))
            return pos[l][r]=true;
    }
    fori(l,r)
        if(go(l,i)&&go(i+1,r))
            return pos[l][r]=true;
    fori(l+1,r)
        if(s[i]==s[r]&&go(l,i)&&go(i+1,r-1))
            return pos[l][r]=true;
    return pos[l][r]=false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,25)
    {
        cin>>s; seto(pos,-1);
        if(go(0,s.size()-1))
            cout<<"S";
        else
            cout<<"U";
        if(i%5==4)
            cout<<"\n";
    }
    return 0;
}
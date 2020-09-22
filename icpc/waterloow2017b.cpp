#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int fr[26];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,k,m=INT_MAX,mc,t=0,x=0;
    string str,s;
    cin>>n>>k>>str;
    fori(0,n)
    {
        fr[str[i]-'a']++;
    }
    fori(0,26)
    {
        if(fr[i]<m)
        {
            m=fr[i];
            mc=i;
        }
    }
    if(m>k||k>n)
    {
        cout<<"WRONGANSWER";
        return 0;
    }
    while(t<k-m)
    {
        if(str[x]!=mc+'a')
            t++;
        x++;
    }
    cout<<str.substr(0,x);
    fori(x,n)
    {
        cout<<char('a'+mc);
    }
    return 0;
}
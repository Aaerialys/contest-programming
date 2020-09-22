#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>str;
    vector<int> numb;
    int x,s,t=0;
    bool mult=false;
    s=str.size();
    fori(0,s)
    {
        x=str[i]-'0';
        if(x==0)
            mult=true;
        t+=x;
        numb.push_back(x);
    }
    if(!(t%3==0&&mult))
        cout<<-1;
    else
    {
        sort(numb.begin(),numb.end());
        for(int i=s-1;i>=0;i--)
            cout<<numb[i];
    }
    return 0;
}
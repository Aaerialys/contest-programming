#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

stack<int> s;
string in;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>in; s.push(-1);
    fori(0,in.size())
    {
        if(in[i]-'0'==1-s.top())
            s.pop();
        else
            s.push(in[i]-'0');
    }
    cout<<in.size()-s.size()+1;
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

string s1,s2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s1>>s2;
    if(s2[s2.size()-1]=='s')
        cout<<s1<<"-tu les "<<s2<<" ?";
    else if(s2[s2.size()-1]=='e')
        cout<<s1<<"-tu la "<<s2<<" ?";
    else
        cout<<s1<<"-tu le "<<s2<<" ?";
    return 0;
}
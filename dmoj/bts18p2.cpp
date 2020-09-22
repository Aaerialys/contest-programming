#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,a,b,f[1000010][26];
string str;
char c;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    getline(cin,str);
    fori(0,str.size())
    {
        forj(0,26)
            f[i+1][j]=f[i][j];
        if(str[i]!=' ')
            f[i+1][str[i]-'a']++;
    }
    cin>>n;
    fori(0,n)
    {
        cin>>a>>b>>c;
        cout<<f[b][c-'a']-f[a-1][c-'a']<<"\n";
    }
    return 0;
}
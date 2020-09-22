#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n;
string in;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>in;
        if((in[2]>='0'&&in[2]<='9'&&(in[2]-'0')%2)||(in[2]>='A'&&in[2]<='Z'&&(in[2]-'A')%2))
        {
            in[2]--;
            cout<<in<<" ";
            in[2]++;
        }
        cout<<in<<"\n";
    }
    return 0;
}
#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string in,essay;
    fork(0,5)
    {
        getline(cin,in);
        ford(i,in.size()-1,0)
            if(in.substr(in.size()-i,i)==in.substr(0,i))
            {
                cout<<in<<in.substr(i,in.size()-i)<<endl;
                break;
            }
    }
    return 0;
}
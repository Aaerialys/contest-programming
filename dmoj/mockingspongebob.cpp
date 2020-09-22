#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    string s;
    cin>>n;
    getline(cin,s);
    forj(0,n)
    {
        x=0;
        getline(cin,s);
        fori(0,s.size())
        {
            if((s[i]<='z'&&s[i]>='a')||(s[i]<='Z'&&s[i]>='A'))
            {
                if(x%2==0)
                    s[i]=tolower(s[i]);
                if(x%2==1)
                    s[i]=toupper(s[i]);
                x++;
           }
        }
        cout<<s<<"\n";
    }
    return 0;
}
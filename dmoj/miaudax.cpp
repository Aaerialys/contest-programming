#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
string str;
vector<int> numb;
long long t=1;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    fori(0,str.size())
        if(i%2==0)
            numb.push_back(str[i]-'0');
    sort(numb.begin(),numb.end());
    fori(0,numb.size())
    {
        t*=numb[i];
        if(i>0)
            cout<<'x';
        cout<<numb[i];
    }
    cout<<"\n"<<t;
    return 0;
}
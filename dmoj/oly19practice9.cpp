#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,x,y,t;
pair<int,int> numb[100100];
string str;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first+abs(a.second-b.first)+b.second==b.first+abs(b.second-a.first)+a.second)
        return a.first<b.first;
    return a.first+abs(a.second-b.first)+b.second<b.first+abs(b.second-a.first)+a.second;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>str; t+=str.size(); y=x=0;
        fori(0,str.size())
        {
            if(str[i]=='(')
                x++;
            if(str[i]==')')
            {
                if(x==0)
                    y++;
                else
                    x--;
            }
        }
        numb[i]={y,x};
    }
    sort(numb,numb+n,cmp);
    x=y=0;
    fori(0,n)
    {
        x+=max(0,numb[i].first-y);
        y=max(0,y-numb[i].first);
        y+=max(0,numb[i].second);
    }
    cout<<t-x-y;
    return 0;
}
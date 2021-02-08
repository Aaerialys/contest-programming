#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int sset[26];
bool v[26],vv[26];
vector<int> sub[26];

void cont(int x)
{
    if(!v[x])
    {
        v[x]=true;
        fori(0,sub[x].size())
        {
            cont(sub[x][i]);
            sset[x]=sset[x]|sset[sub[x][i]];
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    char a,b;
    bool d;
    string str;
    cin>>n;
    fori(0,n)
    {
        cin>>a>>str>>b;
        vv[a-'A']=true;
        if(b>='a'&&b<='z')
            sset[a-'A']=sset[a-'A']|1<<b-'a';
        if(b>='A'&&b<='Z')
        {
            sub[a-'A'].push_back(b-'A');
            vv[b-'A']=true;
        }
    }
    fori(0,26)
    {
        if(vv[i])
        {
            fori(0,26)
                v[i]=false;
            cont(i);
            a=i+'A';
            cout<<a<<" = {";
            d=false;
            forj(0,26)
            {
                b=j+'a';
                if(sset[i]&1<<j)
                {
                    if(d)
                        cout<<",";
                    else
                        d=true;
                    cout<<b;
                }
            }
            cout<<"}"<<endl;
        }
    }
    return 0;
}
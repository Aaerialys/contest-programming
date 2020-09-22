#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,x,t,aa;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fork(0,10)
    {
        string in;
        unordered_map<string,int> child;
        cin>>n; t=0;
        fori(0,n)
        {
            cin>>in; x=2;
            forj(2,in.size()+1)
            {
                if(j==in.size()||in[j]=='.')
                {
                    aa=stoi(in.substr(x,j-x));
                    if(child.find(in.substr(0,x))==child.end())
                        child[in.substr(0,x)]=stoi(in.substr(x,j-x));
                    else
                        child[in.substr(0,x)]=max(child[in.substr(0,x)],stoi(in.substr(x,j-x)));
                    x=j+1;
                }
            }
        }
        for(auto i:child)
            t=(t+i.second)%1000000007;
        cout<<t+1<<endl;
    }
    return 0;
}
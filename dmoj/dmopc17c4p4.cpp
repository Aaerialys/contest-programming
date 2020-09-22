#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int day[1000010];
bool first[1000010];
bool protec[1000010];
vector<int> nP;
vector<int> P;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    cin>>n;
    fori(0,n)
    {
        cin>>a;
        a--;
        if(!protec[a])
        {
            protec[a]=true;
            first[i]=true;
            P.push_back(a);
        }
        day[a]=i;
    }
    if(P.size()==1)
    {
        cout<<-1;
        return 0;
    }
    fori(0,n)
    {
        if(!protec[i])
            nP.push_back(i);
    }
    P.push_back(P[0]);
    a=b=0;
    fori(0,n)
    {
        if(first[i])
        {
            cout<<P[a+1]+1<<" ";
            a++;
        }
        else
        {
            cout<<nP[b]+1<<" ";
            b++;
        }
    }
    return 0;
}
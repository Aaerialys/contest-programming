#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int B=1600,R=2e5/B+1;
int n,q,l,r,a,b,c,x,y,t;
char ch;
vector<int> bk[R],numb,biv;
unordered_map<int,int> freq[R];

void rebuild()
{
    biv.clear();
    fori(0,R)
    {
        for(auto j:bk[i])
            numb.push_back(j);
        bk[i].clear(); freq[i].clear();
        biv.push_back(i*B);
    }
    fori(0,numb.size())
    {
        bk[i/B].push_back(numb[i]);
        freq[i/B][numb[i]]++;
    }
    numb.clear();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in1.txt", "r", stdin);
    cin>>n>>q;
    fori(0,n)
    {
        cin>>a;
        numb.push_back(a);
    }
    fori(0,q)
    {
        //t=0;
        if(i%(B-1)==0)
            rebuild();
        cin>>ch;
        if(ch=='I')
        {
            cin>>a>>b; a^=t; b^=t; x=upper_bound(biv.begin(),biv.end(),a)-biv.begin()-1;
            if(a-biv[x]>=bk[x].size())
                bk[x].push_back(b);
            else
                bk[x].insert(bk[x].begin()+a-biv[x],b);
            freq[x][b]++;
            forj(x+1,R)
                biv[j]++;
        }
        if(ch=='D')
        {
            cin>>a; a^=t; a--; x=upper_bound(biv.begin(),biv.end(),a)-biv.begin()-1; b=bk[x][a-biv[x]];
            bk[x].erase(bk[x].begin()+a-biv[x]); freq[x][b]--;
            forj(x+1,R)
                biv[j]--;
        }
        if(ch=='C')
        {
            cin>>a>>b>>c; a^=t; b^=t; c^=t; a--; b--; t=0; x=upper_bound(biv.begin(),biv.end(),a)-biv.begin()-1; y=upper_bound(biv.begin(),biv.end(),b)-biv.begin()-1;
            if(x==y)
            {
                forj(a-biv[x],b-biv[x]+1)
                    if(bk[x][j]==c)
                        t++;
            }
            else
            {
                forj(a-biv[x],bk[x].size())
                    if(bk[x][j]==c)
                        t++;
                forj(0,b-biv[y]+1)
                    if(bk[y][j]==c)
                        t++;
                forj(x+1,y)
                    if(freq[j].count(c)!=0)
                        t+=freq[j][c];
            }
            cout<<t<<"\n";
        }
    }
    return 0;
}
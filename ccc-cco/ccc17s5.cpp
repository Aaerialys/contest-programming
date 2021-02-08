#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;
const long long BB=401,R=375,M=150010;
long long B,n,m,q,a,b,c,t,bsum[BB],lshift[M],rmost[BB][M],re[M],pre;
vector<pair<long long,long long>> line[M];
pair<long long,long long> numb[M];


int main()
{
    auto tt=system_clock::now();
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(0,BB)
        forj(0,M)
            rmost[i][j]=-1;
    cin>>n>>m>>q;
    B=(n-1)/R+1;
    fori(0,n)
    {
        cin>>a;
        numb[i].first=a;
        line[a].push_back({i,0});
        rmost[i/R][a]=line[a].size()-1;
        re[a]=i/R;
    }
    fori(0,n)
    {
        cin>>a;
        b=lower_bound(line[numb[i].first].begin(),line[numb[i].first].end(),make_pair(i,LLONG_MIN))-line[numb[i].first].begin();
        line[numb[i].first][b].second=a;
        numb[i].second=b;
        bsum[i/R]+=a;
    }
    fori(0,q)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c; t=0; b--; c--;
            forj(ceil((b*1.0)/R),c/R)
                t+=bsum[j];
            forj(b,min((int)ceil((b*1.0)/R)*R,c+1))
                t+=line[numb[j].first][(numb[j].second-lshift[numb[j].first]+line[numb[j].first].size()*10LL)%line[numb[j].first].size()].second;
            forj(max(min((int)ceil((b*1.0)/R)*R,c+1),(c/R)*R),c+1)
                t+=line[numb[j].first][(numb[j].second-lshift[numb[j].first]+line[numb[j].first].size()*10LL)%line[numb[j].first].size()].second;
            cout<<t<<"\n";
        }
        if(a==2)
        {
            cin>>b;
            pre=re[b];
            forj(0,B) //! fix, starting and ending bucket of a line
            {
                if(rmost[j][b]!=-1)
                {
                    bsum[j]-=line[b][(rmost[j][b]-lshift[b]+line[b].size()*10LL)%line[b].size()].second-line[b][(rmost[pre][b]-lshift[b]+line[b].size()*10LL)%line[b].size()].second;
                    pre=j;
                }
            }
            lshift[b]++;
            lshift[b]%=line[b].size();
        }
    }
    return 0;
}

/**
sqrt(n) size buckets
store rightmost station of each bucket
keep list of stations of each line
when updating, update sum of each bucket
shift list of stations with a delta value
update each individual element when needed by query
**/
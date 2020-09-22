#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int r,s,a,b,m,mx[1001][1001],cool[1001][1001],numb[1001];
stack<pair<int,int>> st;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>r>>s;
    fori(0,r)
        forj(0,s)
            cin>>mx[i][j];
    fori(0,r-1)
        forj(0,s-1)
            if(mx[i][j]+mx[i+1][j+1]<=mx[i][j+1]+mx[i+1][j])
                cool[i][j]=1;
    st.push({-1,INT_MIN});
    fori(0,r)
    {
        forj(0,s-1)
        {
            if(cool[i][j]==0)
                numb[j]=0;
            else
                numb[j]++;
        }
        forj(0,s)
        {
            a=st.top().first; b=st.top().second;
            while(b>=numb[j])
            {
                st.pop();
                m=max(m,(j-st.top().first)*(b+1));
                a=st.top().first; b=st.top().second;
            }
            st.push({j,numb[j]});
        }
        st.pop();
    }
    cout<<m<<endl;
    return 0;
}
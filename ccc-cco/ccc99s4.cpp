#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int aa=0;aa<n;aa++)
    {
        queue<int> xlist;
        queue<int> ylist;
        int x1,x2,y1,y2,a,b,r,c,m=INT_MAX;
        cin>>r>>c>>x2>>y2>>x1>>y1;
        x1--;
        y1--;
        x2--;
        y2--;
        xlist.push(x1);
        ylist.push(y1);
        int dist[r][c ];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                dist[i][j]=INT_MAX;
        }
        dist[x1][y1]=0;
        while(xlist.empty()==false)
        {
            a=xlist.front();
            b=ylist.front();
            xlist.pop();
            ylist.pop();
            if(a+1<r&&b+2<c&&dist[a+1][b+2]>dist[a][b]+1)
            {
                xlist.push(a+1);
                ylist.push(b+2);
                dist[a+1][b+2]=dist[a][b]+1;
            }
            if(a+2<r&&b+1<c&&dist[a+2][b+1]>dist[a][b]+1)
            {
                xlist.push(a+2);
                ylist.push(b+1);
                dist[a+2][b+1]=dist[a][b]+1;
            }
            if(a+2<r&&b-1>=0&&dist[a+2][b-1]>dist[a][b]+1)
            {
                xlist.push(a+2);
                ylist.push(b-1);
                dist[a+2][b-1]=dist[a][b]+1;
            }
            if(a+1<r&&b-2>=0&&dist[a+1][b-2]>dist[a][b]+1)
            {
                xlist.push(a+1);
                ylist.push(b-2);
                dist[a+1][b-2]=dist[a][b]+1;
            }
            if(a-1>=0&&b-2>=0&&dist[a-1][b-2]>dist[a][b]+1)
            {
                xlist.push(a-1);
                ylist.push(b-2);
                dist[a-1][b-2]=dist[a][b]+1;
            }
            if(a-2>=0&&b-1>=0&&dist[a-2][b-1]>dist[a][b]+1)
            {
                xlist.push(a-2);
                ylist.push(b-1);
                dist[a-2][b-1]=dist[a][b]+1;
            }
            if(a-2>=0&&b+1<c&&dist[a-2][b+1]>dist[a][b]+1)
            {
                xlist.push(a-2);
                ylist.push(b+1);
                dist[a-2][b+1]=dist[a][b]+1;
            }
            if(a-1>=0&&b+2<c&&dist[a-1][b+2]>dist[a][b]+1)
            {
                xlist.push(a-1);
                ylist.push(b+2);
                dist[a-1][b+2]=dist[a][b]+1;
            }
        }
        for(int i=1;x2+i<r-1;i++)
        {
            if(dist[x2+i][y2]<=i&&(i-dist[x2+i][y2])%2==0&&m==INT_MAX)
            {
                m=i;
                cout<<"Win in "<<m<<" knight move(s)."<<endl;
            }
        }
        if(m==INT_MAX)
        {
            for(int i=0;i+x2+1<r;i++)
            {
                if(dist[x2+i+1][y2]<=i&&(i-dist[x2+i+1][y2])%2==0&&m==INT_MAX)
                {
                    m=i;
                    cout<<"Stalemate in "<<m<<" knight move(s)."<<endl;
                }
            }
        }
        if(m==INT_MAX)
            cout<<"Loss in "<<r-x2-2<<" knight move(s)."<<endl;
    }
    return 0;
}
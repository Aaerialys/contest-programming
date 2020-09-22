#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

double slope(pair <int, int> a, pair <int, int> b)
{
    if(a.first==b.first)
       return INT_MIN;
    return (a.second - b.second)*1.0/(a.first - b.first);
}
int dist(pair<int,int> a,pair<int,int> b,pair<int,int> x)
{
    return abs(a.first*b.second+b.first*x.second+x.first*a.second-a.second*b.first-b.second*x.first-x.second*a.first);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("DATA22.txt", "r", stdin);
    for(int d = 0; d < 10; d++){
        int numS = 0;
        int n;
        cin>>n;
        vector <pair <int, int>> points;
        fori(0, n){
            int a, b;
            cin>>a>>b;
            points.push_back({a,b});
        }
        if(n%2==1)
        {
            cout<<0<<endl;
            continue;
        }
        fori(0,n/2)
        {
            bool sym = true;
            pair <int, int> a=points[i],b=points[(i+n/2)%n];
            double m1 = slope(a, b);
            forj(1,n/2){
                pair <int, int> x = points[(i+j)%n], y = points[(i-j+n)%n];
                double m2 = slope(x, y);
                if(m1 == INT_MIN && m2 != 0){
                    sym = false;
                    break;
                }
                if(m2 == INT_MIN && m1 != 0){
                    sym = false;
                    break;
                }
                bool xxxx=false;
                if(abs(m2+1/m1)<0.0000001)
                    xxxx=true;
                if((m1!=INT_MIN)&&(m2!=INT_MIN)&&(!xxxx)){
                    sym = false;
                    break;
                }
                if(dist(a,b,x)!=dist(a,b,y)){
                    sym = false;
                    break;
                }
            }
            if(sym == true)numS++;
        }
        cout << numS << endl;
    }

    return 0;
}
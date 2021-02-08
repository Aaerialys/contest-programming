#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int x,y,spiral[10][10]={{72,71,70,69,68,67,66,65,64,99},
                    {73,42,41,40,39,38,37,36,63,98},
                    {74,43,20,19,18,17,16,35,62,97},
                    {75,44,21,6,5,4,15,34,61,96},
                    {76,45,22,7,0,3,14,33,60,95},
                    {77,46,23,8,1,2,13,32,59,94},
                    {78,47,24,9,10,11,12,31,58,93},
                    {79,48,25,26,27,28,29,30,57,92},
                    {80,49,50,51,52,53,54,55,56,91},
                    {81,82,83,84,85,86,87,88,89,90}};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>x>>y;
    fori(0,10)
    {
        forj(0,10)
            if(spiral[i][j]+x<=y)
                cout<<spiral[i][j]+x<<" ";
        cout<<endl;
    }
    return 0;
}
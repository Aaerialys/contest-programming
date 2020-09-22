#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> xlist;
    queue<int> ylist;
    int x1,x2,y1,y2,a,b,m=0;
    cin>>x1>>y1>>x2>>y2;
    xlist.push(x1);
    ylist.push(y1);
    xlist.push(100);
    ylist.push(100);
    while(xlist.front()!=x2||ylist.front()!=y2)
    {
        a=xlist.front();
        b=ylist.front();
        if(a==100&&b==100)
        {
            xlist.push(100);
            ylist.push(100);
            m++;
        }
        else{
            if(a+1<9&&b+2<9)
            {
                xlist.push(a+1);
                ylist.push(b+2);
            }
            if(a+2<9&&b+1<9)
            {
                xlist.push(a+2);
                ylist.push(b+1);
            }
            if(a+2<9&&b-1>0)
            {
                xlist.push(a+2);
                ylist.push(b-1);
            }
            if(a+1<9&&b-2>0)
            {
                xlist.push(a+1);
                ylist.push(b-2);
            }
            if(a-1>0&&b-2>0)
            {
                xlist.push(a-1);
                ylist.push(b-2);
            }
            if(a-2>0&&b-1>0)
            {
                xlist.push(a-2);
                ylist.push(b-1);
            }
            if(a-2>0&&b+1<9)
            {
                xlist.push(a-2);
                ylist.push(b+1);
            }
            if(a-1>0&&b+2<9)
            {
                xlist.push(a-1);
                ylist.push(b+2);
            }
        }
        xlist.pop();
        ylist.pop();
    }
    cout<<m;
    return 0;
}
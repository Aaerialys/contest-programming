#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
    int n,a;
    stack<int> tower;
    stack<int> town;
    tower.push(1000000000);
    town.push(1);
    scanf("%d",&n);
    for(int i=1;i<=n; i++)
    {
        scanf("%d",&a);
        while(tower.top()<=a)
        {
            tower.pop();
            town.pop();
        }
        printf("%d ",i-town.top());
        tower.push(a);
        town.push(i);
    }
    return 0;
}
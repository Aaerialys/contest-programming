#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    auto tt=system_clock::now();
    int a,b,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cout<<a+b<<"\n";
    }
    return 0;
}
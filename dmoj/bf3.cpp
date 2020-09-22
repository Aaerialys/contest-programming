#include <bits/stdc++.h>
using namespace std;

bool prime(int N){
    if (N==1) return 0;
    for (int l=2; l*l<=N; ++l) if (N%l==0) return 0;
    return 1;
}

int main(){
    int n;
    cin >> n;
    do{
        if (prime(n)){cout << n;return 0;}
    }while(n++);
    return 0;
}
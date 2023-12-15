#include <bits/stdc++.h>
using namespace std;
bool check(int a, int b,int m){
    return (a-b)%m == ((a%m)-(b%m)+m)%m;
}
int main(){

    int a,b,m;
    cin>>a>>b;
    cout<<check(a,b,m);
    return 0;
}